//
// Created by Juan on 24/04/2021.
//

#include <sstream>
#include "Ruta.h"
#include "Enlace.h"


void Ruta::cd(std::string nombre) {
    if (directorios.empty()){
        if (nombre == "."){

        }else{
            if(raiz->existeDirectorio(nombre)){
                std::shared_ptr<Directorio> directorio = raiz->obtenerDirectorio(nombre);
                directorios.push_back(directorio);
            } else {

                throw 5;
            }
        }
    } else{
        if (nombre == "." || nombre == ".."){
            if (nombre == ".."){
                directorios.erase(directorios.end());
            }
        }else {
            if (directorios.back()->existeDirectorio(nombre)) {
                std::shared_ptr<Directorio> directorio = directorios.back()->obtenerDirectorio(nombre);
                directorios.push_back(directorio);
            } else {
                throw 5;
            }
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
    resultado += ".\n";
    if (directorios.empty()){
        return resultado += raiz->ls();
    }else{
        resultado += "..\n";
        return resultado += directorios.back()->ls();
    }
}

void Ruta::mkdir(std::string nombre) {
    if (directorios.empty()){
        raiz->mkdir(nombre);
    } else {
        directorios.back()->mkdir(nombre);
    }
}

std::string Ruta::pwd() {
    if (directorios.empty()){
        return raiz->getNombre() + "\n";
    } else{
        std::string ruta;
        ruta += raiz->getNombre();
        for (auto d : this->directorios) {
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

int Ruta::stat(std::string path) {  //TODO:directorios y ficheros con ruta completa funcionan
                                    //TODO: fichero y dir sin ruta completa funcionan solo en raiz ta bien???
                                    //TODO: hay que meter enlaces
                                    //TODO: hay que meter . y ..
    std::vector<std::string> ruta;
    std::istringstream iss(path);
    std::string token;
    std::shared_ptr<Directorio> auxDir(raiz);
    std::shared_ptr<Fichero> auxFichero;

    //std::cout << path << "\n";

    std::getline(iss, token, '/');
    //std::cout << token << "\n";
    bool existeDir, existeFichero;
    int tamanyo = 0;
    int cont = 0;
    while (std::getline(iss, token, '/')) {
        ruta.push_back(token);
        std::cout << "token: " << token << std::endl;
        cont++;
    }

    //std::cout << " ANTES DEL IF token: " << token << std::endl;
    if(cont == 0){  //Si no presenta "/" es una direccion relativa
        /*std::cout << " DENTRO DEL IF token: " << token << std::endl;
        std::cout << " DENTRO DEL IF path: " << path << std::endl;*/
        ruta.push_back(path); //guardamos para devolver el nombre del nodo representado
        //std::cout << "Entro con ruta.front: " << ruta.front() << std::endl;

        if(!directorios.empty()){   //Si no estamos en dir raiz
            //std::cout << "Cambio la raiz por dirback()"<< std::endl;
            auxDir = directorios.back();
        } /*else{
            std::cout << "no toco la RAIZ"<< std::endl;
        }*/

        existeDir = auxDir->existeDirectorio(ruta.front());
        existeFichero  = auxDir->existeFichero(ruta.front());
        //existeDir = directorios.back()->existeDirectorio(ruta.front());
        //existeFichero = directorios.back()->existeFichero(ruta.front());

        if(existeFichero){    //Si hemos llegado al final y es un fichero
            /*std::cout << "Entro dir con cont: " << cont << std::endl;
            std::cout << "Entro con path: " << path << std::endl;
            std::cout << "Entro con ruta.front: " << ruta.front() << std::endl;*/
            auxFichero = auxDir->obtenerFichero(ruta.front());
           // tamanyo = auxFichero->calcularTamanyo();
            tamanyo = auxFichero->calcularTamanyo();
        } else if(existeDir){    //Si hemos llegado al final y es un fichero
            /*std::cout << "Entro fichero con cont: " << cont << std::endl;
            std::cout << "Entro con path: " << path << std::endl;
            std::cout << "Entro con ruta.front: " << ruta.front() << std::endl;*/
            auxDir = auxDir->obtenerDirectorio(ruta.front());
            tamanyo = auxDir->calcularTamanyo();
        } else {  //Si no existe ningun fichero o dir con ese nombre excepcion
            throw 13;
        }
    }
    //std::cout << "CONT antes while " << cont << std::endl;
    while (cont > 0){   //Para direcciones absolutas
        /*std::cout << "ruta.front(): " << ruta.front() << std::endl;
        std::cout << "CONT en while " << cont << std::endl;*/
        existeDir = auxDir->existeDirectorio(ruta.front());
        existeFichero  = auxDir->existeFichero(ruta.front());

        if (!existeDir && !existeFichero){  //Si no existe ningun fichero o dir con ese nombre excepcion
            throw 13;
        } else if(existeFichero && (cont == 1)){    //Si hemos llegado al final y es un fichero
            //std::cout << "Entro dir con cont: " << cont << std::endl;
            auxFichero = auxDir->obtenerFichero(ruta.front());
            tamanyo = auxFichero->calcularTamanyo();

            cont = 0;
        } else if(existeDir && (cont == 1)){    //Si hemos llegado al final y es un fichero
            //std::cout << "Entro fichero con cont: " << cont << std::endl;
            auxDir = auxDir->obtenerDirectorio(ruta.front());
            tamanyo = auxDir->calcularTamanyo();
            cont = 0;
        } else {        //Si seguimos teniendo rutas a las que acceder
            auxDir = auxDir->obtenerDirectorio(ruta.front());

            ruta.erase(ruta.begin());
            cont--;
        }
    }

    std::cout << ruta.back() << " -> ";
    return tamanyo;
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


