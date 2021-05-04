//
// Created by Juan on 24/04/2021.
//

#include "Directorio.h"

void Directorio::introducirNodo(const std::string& nombre, const std::shared_ptr<Nodo>& nuevoNodo) {
    mapaDeNombres.insert(std::pair<std::string , std::shared_ptr<Nodo>>(nombre, nuevoNodo));
}

int Directorio::calcularTamanyo(){
    int size = 0;
    for(const auto& d : this->mapaDeNombres){ //TODO: comprobar recursividad con enlaces a padres
        size += d.second->calcularTamanyo();
    }
    return size;
}


bool Directorio::existeNodo(const std::string& nombre) {
    auto it = mapaDeNombres.find(nombre);
    if (it == mapaDeNombres.end()){
        return false;
    } else {
        return true;
    }
}

void Directorio::mkdir(const std::string& nombre) {
    if (existeNodo(nombre) || nombre == "/" || nombre == "." || nombre == ".."){
        //Error si se intenta crear un directorio con un nombre existente
        //throw 5;
        throw excepcion_nodo_existe("El directorio que intenta crear ya existe\n");
    } else {
        auto nuevoDir = std::make_shared<Directorio>(nombre);
        introducirNodo(nombre, nuevoDir);

    }
}

std::string Directorio::du() {
    std::string lista;
    if (!mapaDeNombres.empty()){
        for(const auto& d : this->mapaDeNombres){
            lista += d.second->getNombre() + "  " + std::to_string(d.second->calcularTamanyo()) + " Bytes\n";
        }
    }else{
        //No hay directorios. Tal vez en vez de error devolver vacio
        //throw 2;
        throw excepcion_nodo_no_encontrado("Este directorio no contiene nada");
    }
    return lista;
}

bool Directorio::existeDirectorio(const std::string& nombre) {

    if (existeNodo(nombre)) {
        // Para casteos necesario el vitual en el padre
        auto directorio = std::dynamic_pointer_cast<Directorio>(mapaDeNombres.find(nombre)->second);
        return directorio != nullptr;
    }else{
        return false;
    }
}

bool Directorio::existeFichero(const std::string& nombre) {
    if (existeNodo(nombre)) {
        // Para casteos necesario el vitual en el padre
        auto fichero = std::dynamic_pointer_cast<Fichero>(mapaDeNombres.find(nombre)->second);
        return fichero != nullptr;
    }else{
        return false;
    }
}

bool Directorio::existeEnlace(std::string nombre) {

    if (existeNodo(nombre)) {
        // Para casteos necesario el vitual en el padre
        auto fichero = std::dynamic_pointer_cast<Enlace>(mapaDeNombres.find(nombre)->second);
        return fichero != nullptr;
    }else{
        return false;
    }
}
//toDo: Esta funcion no me acaba de convencer
bool Directorio::existeEnlaceCD(const std::string& nombre) {
    if (existeNodo(nombre)) {
        // Para casteos necesario el vitual en el padre
        auto enlace = std::dynamic_pointer_cast<Enlace>(mapaDeNombres.find(nombre)->second);
        if (enlace != nullptr){
            auto  directorioEnlace = std::dynamic_pointer_cast<Directorio>(enlace->getLink());
            return directorioEnlace != nullptr;
        } else{
            return false;
        }
    }else{
        return false;
    }
}

std::shared_ptr<Directorio> Directorio::obtenerDirectorio(const std::string& nombre) {
    return std::dynamic_pointer_cast<Directorio>(mapaDeNombres.find(nombre)->second);
}

std::shared_ptr<Directorio> Directorio::obtenerDirectorioEnlace(const std::string& nombre) {
    auto enlace = std::dynamic_pointer_cast<Enlace>(mapaDeNombres.find(nombre)->second);
    return std::dynamic_pointer_cast<Directorio>(enlace->getLink());
}
/*
std::shared_ptr<Fichero> Directorio::obtenerFichero(std::string nombre) {
    return std::dynamic_pointer_cast<Fichero>(mapaDeNombres.find(nombre)->second);
}

std::shared_ptr<Enlace> Directorio::obtenerEnlace(std::string nombre) {
    return std::dynamic_pointer_cast<Enlace>(mapaDeNombres.find(nombre)->second);
}
*/

/*
void Directorio::actualizarTamanio(int incremento) {    //TODO: NO VEO OTRA FORMA PERO ESTO ESTA MU FEO
    throw 15;   //Soltar excepcion de que no puedes modificar a la fuerta el tam de un dir?
}
*/

std::shared_ptr<Nodo> Directorio::solve() {
    return std::shared_ptr<Nodo>(this);
}
void Directorio::vi(const std::string& nombre, int size) {
    if (existeFichero(nombre)){
        auto fichero = std::dynamic_pointer_cast<Fichero>(mapaDeNombres.find(nombre)->second);
       fichero->actualizarTamanio(size);
    } else {
        if (existeNodo(nombre)){
            //si existe un nodo que no es fichero error
            std::logic_error errorVi("El elemento a editar no es un fichero\n");
            throw errorVi;
        } else {
            auto nuevoFichero = std::make_shared<Fichero>(nombre, size);
            introducirNodo(nombre, nuevoFichero);
        }
    }
}

std::string Directorio::ls() {
    std::string lista;
    for (const auto& d : this->mapaDeNombres) {
        lista += d.second->getNombre() + "\n";
    }
    return lista;
}

std::shared_ptr<Nodo> Directorio::obtenerNodo(const std::string& nombre) {
    return mapaDeNombres.find(nombre)->second;
}

void Directorio::ln(const std::string& nombre, const std::shared_ptr<Nodo>& nodo) {
    auto enlace = std::make_shared<Enlace>(nombre, nodo);
    introducirNodo(nombre, enlace);
}

void Directorio::rm(const std::string& nombre) {
    mapaDeNombres.erase(nombre);
}


