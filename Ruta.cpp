//
// Created by Juan on 24/04/2021.
//

#include <sstream>
#include "Ruta.h"

/**
 * Funcion cd estrae la cadena y la formatea para trabajar con ella
 * @param path
 */
void Ruta::cd(std::string path) {
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
        if (ruta.front() == ""){
            //Si va a / limpio el vector
            directorios.clear();
        }else {
            //si no introduzo directamente el vector
           introducirDirectorio(ruta.front());
        }
    } else {
        //si no si va a barra limpio el vector y voy accediendo por los directorios
        if (ruta.front() == ""){
            directorios.clear();
            ruta.erase(ruta.begin());
        }
        for (auto & i : ruta) {
            introducirDirectorio(i);
        }
    }
}

void Ruta::introducirDirectorio(std::string nombre){
    //si no estoy en un directorio significa que estoy en la raiz
        std::shared_ptr<Directorio> directorioActual = raizOrDirectory();
        // si es un . significa que se refiere a la raiz actual no hago nada
        //si existen nodos pueden referirse a . o ..
        if (nombre == "." || nombre == ".."){
            //si dos punto significa eliminar el vector si es . no hacemos nada
            if (nombre == ".." && !directorios.empty()){
                directorios.erase(directorios.end());
            }
        }else {
            //si es cualquier otra cosa compruebo si existe
            //si es cualquier otra cosa
            //miro si existe directorio o enlace
            bool existeDirectorio = directorioActual->existeDirectorio(nombre);
            bool existeEnlace = directorioActual->existeEnlaceDirectorio(nombre);
            //si existen
            if(existeDirectorio || existeEnlace){
                //obtengo el directorio del enlace y lo introduzco en el vector
                if (existeEnlace){
                    std::shared_ptr<Directorio> directorio = directorioActual->obtenerDirectorioEnlace(nombre);
                    directorios.push_back(directorio);
                } else{
                    //meto el directorio
                    std::shared_ptr<Directorio> directorio = directorioActual->obtenerDirectorio(nombre);
                    directorios.push_back(directorio);
                }
            } else {
                //Si no hay directorios o enlaces retorno excepcion
                throw excepcion_nodo_no_encontrado(nombre, existeDirectorio, existeEnlace);
            }
        }
}


std::string Ruta::du() {
    std::shared_ptr<Directorio> directorioActual = raizOrDirectory();
    return directorioActual->du();
}


void Ruta::ln(std::string path, std::string nombre) {
    std::vector<std::string> ruta = pathToVector(path);
    //opciones ln
    // ln a prueba  vector.size 1 0 = a
    // ln /a prueba vector.size 2 0 = vacio, 1 = a
    // ln ./a prueba vector.size 2 0 = ., 1 = a
    // ln ../a prueba vector size 2 0 = .., 1= a

    //nodos necesario para ir recorriendo la estructura
    std::shared_ptr<Directorio> aux;
    //copia de los directorios por si es relativa

    //si empieza por vacio significa que es / y por tanto absoluta
    if (ruta.front() == ""){
        aux = rutaAbsoluta(ruta);
    }else{
        aux = rutaRelativa(ruta);
    }

    //meotodo ln del otro dia quizas se pueda refactorizar me he centrado en lo de arriba
    if (aux->existeNodo(ruta.front())){
        std::shared_ptr<Directorio> directorioActual = raizOrDirectory();
        if (directorioActual->existeNodo(nombre)){
            //Compruebo que el nombre ha crear no exista ya en el directorio
            throw excepcion_nodo_existe("Ya exsite un nodo con dicho nombre\n");
        }else{
            directorioActual->ln(nombre, aux->obtenerNodo(ruta.front()));
        }
    } else {
        //error no existe el elemento final del path en ln
        throw excepcion_nodo_no_encontrado(ruta.front(), path);
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

void Ruta::mkdir(const std::string& nombre) {
    /* no se pueden crear directorios */
    std::shared_ptr<Directorio> directorioActual = raizOrDirectory();

    directorioActual->mkdir(nombre);
}

std::string Ruta::pwd() {

    if (directorios.empty()){
        return raiz->getNombre() + "\n";
    } else{
        std::string ruta;
        ruta += raiz->getNombre();
        for (auto d : this->directorios) {
            ruta +=  d->getNombre() + "/";
        }
        ruta += "\n";
        return ruta;
    }
}

void Ruta::rm(std::string path) {
    std::vector<std::string> ruta = pathToVector(path);
    //opciones ln
    // ln a prueba  vector.size 1 0 = a
    // ln /a prueba vector.size 2 0 = vacio, 1 = a
    // ln ./a prueba vector.size 2 0 = ., 1 = a
    // ln ../a prueba vector size 2 0 = .., 1= a

    //nodos necesario para ir recorriendo la estructura
    std::shared_ptr<Directorio> aux;
    //copia de los directorios por si es relativa
    //si empieza por vacio significa que es / y por tanto absoluta
    if (ruta.front() == ""){
        aux = rutaAbsoluta(ruta);
    }else{
        aux = rutaRelativa(ruta);
    }

    if ( aux->existeNodo(ruta.front())){
        aux->rm(ruta.front());
    } else {
        //si no existe el elemento a eliminar excepcion
        throw excepcion_nodo_no_encontrado(ruta.front(), path);
    }

}

int Ruta::stat(std::string path) {

    std::vector<std::string> ruta = pathToVector(path);
    //opciones ln
    // ln a prueba  vector.size 1 0 = a
    // ln /a prueba vector.size 2 0 = vacio, 1 = a
    // ln ./a prueba vector.size 2 0 = ., 1 = a
    // ln ../a prueba vector size 2 0 = .., 1= a

    //nodos necesario para ir recorriendo la estructura
    std::shared_ptr<Directorio> aux;
    //copia de los directorios por si es relativa
    //si empieza por vacio significa que es / y por tanto absoluta
    if (ruta.front() == ""){
        aux = rutaAbsoluta(ruta);
    }else{
        aux = rutaRelativa(ruta);
    }

    if (aux->existeNodo(ruta.front())){
        std::shared_ptr<Nodo> auxFichero = aux->obtenerNodo(ruta.front());
        int tamanio = auxFichero->calcularTamanyo();
        auxFichero->actualizarNodo();
        return tamanio;
    } else {
        //si no existe el elemento a eliminar excepcion
        throw excepcion_nodo_no_encontrado(ruta.front(), path);
    }
}

void Ruta::vi(std::string nombre, int size) {
    std::shared_ptr<Directorio> directorioActual = raizOrDirectory();
    directorioActual->vi(nombre, size);
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
    //recorro las cadenas/directorios hasta el antepenultimo el ultimo sera el nodo del enlace
    while (ruta.size() > 1){
        //busco directorio

        if (aux->existeDirectorio(ruta.front())){
            //lo asigno a aux no me hace falta guardar toda cadena
            aux = aux->obtenerDirectorio(ruta.front());
            //elimino la cadena
            ruta.erase(ruta.begin());
        }else{
            //si no existe el directorio al que ir
            throw excepcion_nodo_no_encontrado(ruta.front());
        }
    }
    return aux;
}


std::shared_ptr<Directorio> Ruta::rutaRelativa(std::vector<std::string>& ruta){
    std::vector<std::shared_ptr<Directorio>> directoriosAux = directorios;
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
            if (respuesta){
                //si hemos llegado a la raiz hay que buscar en la raiz
                if (directoriosAux.empty()){
                    directoriosAux.push_back(raiz->obtenerDirectorio(ruta.front()));
                }else{
                    directoriosAux.push_back(directoriosAux.back()->obtenerDirectorio(ruta.front()));
                }
                ruta.erase(ruta.begin());
            }else{
                //si no existe el esiguiente directorio
                throw excepcion_nodo_no_encontrado(ruta.front());
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

std::shared_ptr<Directorio> Ruta::raizOrDirectory() {
    if (directorios.empty()){
        return raiz;
    } else {
        return directorios.back();
    }
}

