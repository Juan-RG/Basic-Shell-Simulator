//
// Created by Juan on 24/04/2021.
//

#include <sstream>
#include "Ruta.h"
#include "Enlace.h"

/**
 * Funcion cd estrae la cadena y la formatea para trabajar con ella
 * @param path
 */
void Ruta::cd(std::string path) {                                   //todo preguntar que tiene que hacer un enlace de un enlace que va a un directorio
    std::vector<std::string> ruta = pathToVector(path);
    //opciones
    // opcion cd / vector.size 1 contenido vacio -> eliminar todos nodos del vector
    //opcion cd aa vector 1 contenido aa
    //opcion cd /aaa/b vector.size 3 contenido vacio->aa->b
    //opcion cd ./aa/b vector.size 3 contenido .->aa->b
    //opcion cd ../aa/b vector.size 3 contenido ..->aa->b
    //funcion para diferenciar
    if (ruta.size() == 1){
        //logica e barra
        if (!(ruta.front().compare(""))){
            //Si va a / limpio el vector
            directorios.clear();
        }else {
            //si no introduzo directamente el vector
           introducirDirectorio(ruta.front());
        }
    } else {
        //si no si va a barra limpio el vector y voy accediendo por los directorios
        if (!(ruta.front().compare(""))){
            directorios.clear();
            for (int i = 1; i < ruta.size(); ++i) {
                introducirDirectorio(ruta.at(i));
            }
        }else {
            //si es relativa voy desde el actual
            for (int i = 0; i < ruta.size(); ++i) {
                introducirDirectorio(ruta.at(i));
            }
        }
    }
}

void Ruta::introducirDirectorio(std::string nombre){
    //si no estoy en un directorio significa que estoy en la raiz
    if (directorios.empty()){
        // si es un . significa que se refiere a la raiz actual no hago nada
        if (nombre == "."){
        }else{
            //si es cualquier otra cosa
            //miro si existe directorio o enlace
            bool existeDirectorio = raiz->existeDirectorio(nombre);
            bool existeEnlace = raiz->existeEnlaceCD(nombre);

            //si existen
            if(existeDirectorio || existeEnlace){
                //obtengo el directorio del enlace y lo introduzco en el vector
                if (existeEnlace){
                    std::shared_ptr<Directorio> directorio = raiz->obtenerDirectorioEnlace(nombre);
                    directorios.push_back(directorio);
                } else{
                    //meto el directorio
                    std::shared_ptr<Directorio> directorio = raiz->obtenerDirectorio(nombre);
                    directorios.push_back(directorio);
                }
            } else {
                //Si no hay directorios o enlaces retorno error
                throw 5;
            }
        }
    } else{
        //si existen nodos pueden referirse a . o ..
        if (nombre == "." || nombre == ".."){
            //si dos punto significa eliminar el vector si es . no hacemos nada
            if (nombre == ".."){
                directorios.erase(directorios.end());
            }
        }else {
            //si es cualquier otra cosa compruebo si existe
            //si es cualquier otra cosa
            //miro si existe directorio o enlace
            bool existeDirectorio = directorios.back()->existeDirectorio(nombre);
            bool existeEnlace = directorios.back()->existeEnlaceCD(nombre);

            //si existen
            if(existeDirectorio || existeEnlace){
                //obtengo el directorio del enlace y lo introduzco en el vector
                if (existeEnlace){
                    std::shared_ptr<Directorio> directorio = directorios.back()->obtenerDirectorioEnlace(nombre);
                    directorios.push_back(directorio);
                } else{
                    //meto el directorio
                    std::shared_ptr<Directorio> directorio = directorios.back()->obtenerDirectorio(nombre);
                    directorios.push_back(directorio);
                }
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
        return directorios.back()->du();                                                                //todo:: probar
    }
}

/*void ln(str path, str name): Crea en el directorio actual un enlace simbólico de nombre ”name” que apunta al elemento identificado mediante el nombre ”path”. El nombre ”name” no
puede contener una ruta completa, es un nombre simple, pero ”path” sí, de tal modo que
pueden crearse enlaces simbólicos a elementos en otro directorio del árbol.
*/
void Ruta::ln(std::string path, std::string nombre) {

    std::vector<std::string> ruta = pathToVector(path);
    bool respuesta;
    //opciones ln
    // ln a prueba  vector.size 1 0 = a
    // ln /a prueba vector.size 2 0 = vacio, 1 = a
    // ln ./a prueba vector.size 2 0 = ., 1 = a
    // ln ../a prueba vector size 2 0 = .., 1= a

    //nodos necesario para ir recorriendo la estructura
    std::shared_ptr<Directorio> aux;
    //copia de los directorios por si es relativa

    //si empieza por vacio significa que es / y por tanto absoluta
    if (!(ruta.front().compare(""))){
        aux = rutaAbsoluta(ruta);
    }else{
        aux = rutaRelativa(ruta);
    }

    //meotodo ln del otro dia quizas se pueda refactorizar me he centrado en lo de arriba
    respuesta = aux->existeNodo(ruta.front());
    if (!respuesta){
        throw 12;
    } else {
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
    /* no se pueden crear directorios */
    if (!nombre.compare("/")){
        throw 2;
    }
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

    std::vector<std::string> ruta = pathToVector(path);
    bool respuesta;
    //opciones ln
    // ln a prueba  vector.size 1 0 = a
    // ln /a prueba vector.size 2 0 = vacio, 1 = a
    // ln ./a prueba vector.size 2 0 = ., 1 = a
    // ln ../a prueba vector size 2 0 = .., 1= a

    //nodos necesario para ir recorriendo la estructura
    std::shared_ptr<Directorio> aux;
    //copia de los directorios por si es relativa
    //si empieza por vacio significa que es / y por tanto absoluta
    if (!(ruta.front().compare(""))){
        aux = rutaAbsoluta(ruta);
    }else{
        aux = rutaRelativa(ruta);
    }
    respuesta = aux->existeNodo(ruta.front());

    if (!respuesta){
        throw 12;
    } else {
        aux->rm(ruta.front());
    }

}

int Ruta::stat(std::string path) {  //TODO: hay que meter  ..
    std::vector<std::string> ruta;
    std::istringstream iss(path);
    std::string token;

    std::shared_ptr<Directorio> auxDir(raiz);
    std::shared_ptr<Fichero> auxFichero;
    std::shared_ptr<Enlace> auxEnlace;

    std::getline(iss, token, '/');  //Eliminamos hasta la / de una posible direccion absoluta

    bool existeDir, existeFichero, existeEnlace;
    int tamanyo = 0;
    int cont = 0;
    std::cout << path << std::endl;
    while (std::getline(iss, token, '/')) {
        std::cout << token << std::endl;
        if(token != "."){   //Si en la ruta hay un punto, el compilador lo ignorara
            ruta.push_back(token);
            cont++;
        }
    }

    if(cont == 0){
        ruta.push_back(path);
        cont++;
    }

    while (cont > 0){   //Para direcciones absolutas
        if(!directorios.empty()){   //Si no estamos en dir raiz
            auxDir = directorios.back();
        }

        existeDir = auxDir->existeDirectorio(ruta.front());
        existeFichero  = auxDir->existeFichero(ruta.front());
        existeEnlace = auxDir->existeEnlace(ruta.front());

        if (!existeDir && !existeFichero && !existeEnlace){  //Si hemos llegado al final y no hay un nodo con ese nombre, error
            throw 13;
        } else if(existeFichero && (cont == 1)){    //Si hemos llegado al final y es un fichero
            auxFichero = auxDir->obtenerFichero(ruta.front());
            tamanyo = auxFichero->calcularTamanyo();

            cont = 0;
        } else if(existeDir && (cont == 1)){    //Si hemos llegado al final y es un fichero
            auxDir = auxDir->obtenerDirectorio(ruta.front());
            tamanyo = auxDir->calcularTamanyo();

            cont = 0;
        } else if(existeEnlace && (cont == 1)) { //Si hemos llegado al final y es un enlace
            auxEnlace = auxDir->obtenerEnlace(ruta.front());
            tamanyo = auxEnlace->calcularTamanyo();

            cont = 0;
        } else if (!existeDir && cont != 0){  //Si no hemos llegado al final y algun directorio no existe, error
            throw 13;
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

std::vector<std::string> Ruta::pathToVector(std::string path){

        std::vector<std::string> ruta;
        std::istringstream iss(path);
        std::string token;

        while (std::getline(iss, token, '/')) {
        ruta.push_back(token);
        }

        return ruta;
}

std::shared_ptr<Directorio> Ruta::rutaAbsoluta(std::vector<std::string>& ruta){
    std::shared_ptr<Directorio> aux;
    //elimino el primer espacio
    ruta.erase(ruta.begin());
    //empiezo en la raiz
    aux = raiz;
    bool respuesta;
    //recorro las cadenas/directorios hasta el antepenultimo el ultimo sera el nodo del enlace
    while (ruta.size() > 1){
        //busco directorio
        respuesta = aux->existeDirectorio(ruta.front());
        if (!respuesta){
            throw 12;
        }else{
            //lo asigno a aux no me hace falta guardar toda cadena          // Todo: preguntar si en las absolutas es necesario el .. y . si pueden ser posibles añadir
            aux = aux->obtenerDirectorio(ruta.front());
            //elimino la cadena
            ruta.erase(ruta.begin());
        }
    }
    return aux;
}


std::shared_ptr<Directorio> Ruta::rutaRelativa(std::vector<std::string>& ruta){
    std::vector<std::shared_ptr<Directorio>> directoriosAux = directorios;
    std::cout << ruta.size()<<"\n";
    bool respuesta;
    //si empiza por otra cosa significa que es relativa
    while (ruta.size() > 1){
        //si es . simplemente elimno si es .. vuelvo atras en el vector
        if (ruta.front() == "." || ruta.front() == ".."){
            if (ruta.front() == ".."){
                //elimino el directorio
                directoriosAux.erase(directoriosAux.end());
            }
            ruta.erase(ruta.begin());
        }else {
            //si hemos llegado a la raiz hay que buscar en la raiz
            if (directoriosAux.empty()){
                respuesta = raiz->existeDirectorio(ruta.front());
            }else{
                respuesta = directoriosAux.back()->existeDirectorio(ruta.front());
            }
            if (!respuesta){
                throw 12;
            }else{
                //si hemos llegado a la raiz hay que buscar en la raiz
                if (directoriosAux.empty()){
                    directoriosAux.push_back(raiz->obtenerDirectorio(ruta.front()));
                }else{
                    directoriosAux.push_back(directoriosAux.back()->obtenerDirectorio(ruta.front()));
                }
                ruta.erase(ruta.begin());
            }
        }
    }
    //si hemos llegado a la raiz hay que buscar en la raiz
    if (directoriosAux.empty()){
        return raiz;
    } else{
        return directoriosAux.back();
    }

}

