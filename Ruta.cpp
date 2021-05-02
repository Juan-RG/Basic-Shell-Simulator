//
// Created by Juan on 24/04/2021.
//

#include <sstream>
#include "Ruta.h"
#include "Enlace.h"


void Ruta::cd(std::string nombre) {
    //Compruebo que no hay directiorios en el path
    if (directorios.empty()){
        //Compruebo si existe un enlace o un directorio                 Todo: Posible refactor
            bool existeDirectorio = raiz->existeDirectorio(nombre);
            //compruebo si el enlace es un directorio
            bool existeEnlace = raiz->existeEnlaceCD(nombre);
            if(existeDirectorio || existeEnlace){
                if (existeEnlace){
                    //Si existe enlace extraigo el directorio que apunta el enlace
                    std::shared_ptr<Directorio> directorio = raiz->obtenerDirectorioEnlace(nombre);
                    //funcion retorna 0 si es igual, 0> si es diferente y <0 si empeiza igual pero no es el mismo
                    //si es diferente lo añado al vector
                    if (nombre.compare(".")){
                        directorios.push_back(directorio);
                    }
                } else{
                    //si es un directorio lo añado sin mas
                    std::shared_ptr<Directorio> directorio = raiz->obtenerDirectorio(nombre);
                    directorios.push_back(directorio);

                }
            } else {
                throw 5;
            }

    } else{
        //Igual que la anterior pero con nuevos directorios
        bool existeDirectorio = directorios.back()->existeDirectorio(nombre);
        bool existeEnlace = directorios.back()->existeEnlaceCD(nombre);
        if(existeDirectorio || existeEnlace){
            if (existeEnlace){
                std::shared_ptr<Directorio> directorio = directorios.back()->obtenerDirectorioEnlace(nombre);
                //estos cuentan con la carpeta .. que los lleva a al director anterior
                if (nombre.compare("..") == 0) {
                   directorios.erase(directorios.end());
                }else if (nombre.compare(".")) {
                    directorios.push_back(directorio);
                }
            } else{
                std::shared_ptr<Directorio> directorio = directorios.back()->obtenerDirectorio(nombre);
                directorios.push_back(directorio);
            }
        } else {
            throw 5;
        }

    }
}

std::string Ruta::du() {
    if (directorios.empty()){
       return raiz->du();
    }else{
        return directorios.back()->du();
    }
}

/*void ln(str path, str name): Crea en el directorio actual un enlace simbólico de nombre ”name” que apunta al elemento identificado mediante el nombre ”path”. El nombre ”name” no
puede contener una ruta completa, es un nombre simple, pero ”path” sí, de tal modo que
pueden crearse enlaces simbólicos a elementos en otro directorio del árbol.
*/
void Ruta::ln(std::string path, std::string nombre) {

        std::vector<std::string> ruta;
        std::istringstream iss(path);
        std::string token;
        std::shared_ptr<Directorio> aux(raiz);

        //limpio el primer caracter
        std::getline(iss, token, '/');
        bool respuesta;
        int cont = 0;
        while (std::getline(iss, token, '/')) {
            ruta.push_back(token);
            cont++;
        }
        //std::shared_ptr<Directorio> prueba;
        while (cont > 1){
            respuesta = aux->existeDirectorio(ruta.front());
            if (!respuesta){
                throw 12;
            }else{
                //refactorizar
                aux = aux->obtenerDirectorio(ruta.front());
                //aux = prueba;

                std::cout << aux->getNombre() << "\n";

                ruta.erase(ruta.begin());

                cont--;
            }
        }
        respuesta = aux->existeNodo(ruta.front());
        std::cout << respuesta << "\n";
            if (!respuesta){
                throw 12;
            } else {
              //std::shared_ptr<Enlace> enlace = std::make_shared<Enlace>(nombre, aux->obtenerNodo(ruta.front()));
              if (directorios.empty()){
                 if (raiz->existeNodo(nombre)){
                     throw 1;
                 }else{
                     raiz->ln(nombre, aux->obtenerNodo(ruta.front()));

                 }
              } else{
                  if (directorios.back()->existeNodo(nombre)){
                      throw 1;
                  }else{
                      directorios.back()->ln(nombre, aux->obtenerNodo(ruta.front()));
                  }

              }
            }
 }

std::string Ruta::ls() {
    std::string resultado;
   /// resultado += ".\n";
    if (directorios.empty()){
        return resultado += raiz->ls();
    }else{
      //  resultado += "..\n";
        return resultado += directorios.back()->ls();
    }
}

void Ruta::mkdir(std::string nombre) {
    /* no se pueden crear directorios */
    if (!nombre.compare("/")){
        throw 2;
    }
    if (directorios.empty()){
        raiz->mkdir(nombre, raiz);
    } else {
        directorios.back()->mkdir(nombre,directorios.back());
    }
}

std::string Ruta::pwd() {
    if (directorios.empty()){
        return raiz->getNombre() + "\n";
    } else{
        std::string ruta;
        ruta += raiz->getNombre();
        for (std::shared_ptr<Nodo> d : this->directorios) {
            ruta = ruta +  d->getNombre() + "/";
        }
        ruta += "\n";
        return ruta;
    }
}

void Ruta::rm(std::string path) {

    std::vector<std::string> ruta;
    std::istringstream iss(path);
    std::string token;
    std::shared_ptr<Directorio> aux(raiz);

    //limpio el primer caracter
    std::getline(iss, token, '/');
    bool respuesta;
    int cont = 0;
    while (std::getline(iss, token, '/')) {
        ruta.push_back(token);
        cont++;
    }

    while (cont > 1){
        respuesta = aux->existeDirectorio(ruta.front());
        if (!respuesta){
            throw 12;
        }else{
            //refactorizar
            aux = aux->obtenerDirectorio(ruta.front());
            //aux = prueba;

            std::cout << aux->getNombre() << "\n";

            ruta.erase(ruta.begin());

            cont--;
        }
    }

    respuesta = aux->existeNodo(ruta.front());
    std::cout << respuesta << "\n";
    if (!respuesta){
        throw 12;
    } else {
        if (directorios.empty()){
            raiz->rm(ruta.front());
        } else{
            directorios.back()->rm(ruta.front());
        }
    }

}

int Ruta::stat(std::string path) {
    std::cout << path << "\n";
    return 0;
}

/*void vi(str name, int size): Edita el fichero de nombre ”name” (en el directorio actual). Para
simular la edición, simplemente se cambia el tamaño del fichero al valor especificado como
parámetro. Si el fichero no existe, se debe crear con el nombre y tamaño especificados.*/
void Ruta::vi(std::string nombre, int size) {
    if (directorios.empty()){
        raiz->vi(nombre, size);
    } else {
        directorios.back()->vi(nombre, size);
    }
}


