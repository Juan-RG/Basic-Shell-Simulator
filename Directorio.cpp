//
// Created by Juan on 24/04/2021.
//

#include "Directorio.h"

void Directorio::introducirNodo(const std::string& nombre, const std::shared_ptr<Nodo>& nuevoNodo) {
    mapaDeNombres.insert(std::pair<std::string , std::shared_ptr<Nodo>>(nombre, nuevoNodo));
}

Directorio::~Directorio(){

}

int Directorio::calcularTamanyo(){
    int size = 0;
    for(const auto& d : this->mapaDeNombres){ //TODO: comprobar recursividad con enlaces a padres
        size += d.second->calcularTamanyo();
    }
    return size;
}


bool Directorio::existeNodo(const std::string& nombre) {
    if (mapaDeNombres.find(nombre) == mapaDeNombres.end()){
        return false;
    } else {
        return true;
    }
}

void Directorio::mkdir(const std::string& nombre) {
    if (existeNodo(nombre) || nombre == "/" || nombre == "." || nombre == ".."){
        //Excepcion si se intenta crear un directorio con un nombre existente
        throw excepcion_nodo_existe("El directorio que intenta crear ya existe\n");
    } else {
        introducirNodo(nombre, std::make_shared<Directorio>(nombre));
    }
}

std::string Directorio::du() {
    std::string lista;
    if (!mapaDeNombres.empty()){
        for(const auto& d : this->mapaDeNombres){
            lista += d.second->getNombre() + "  " + std::to_string(d.second->solve(0)->calcularTamanyo()) + " Bytes\n";
            d.second->actualizarNodo();
        }
    }else{
        //No hay directorios.
        throw excepcion_nodo_no_encontrado("Este directorio no contiene nada");
    }
    return lista;
}

bool Directorio::existeDirectorio(const std::string& nombre) {
    if (existeNodo(nombre)) {
        return std::dynamic_pointer_cast<Directorio>(mapaDeNombres.find(nombre)->second) != nullptr;
    }else{
        return false;
    }
}
void Directorio::actualizarNodo() {
    for(const auto& d : this->mapaDeNombres){
        d.second->actualizarNodo();
    }
}

bool Directorio::existeFichero(const std::string& nombre) {
    if (existeNodo(nombre)) {
        return  std::dynamic_pointer_cast<Fichero>(mapaDeNombres.find(nombre)->second) != nullptr;
    }else{
        return false;
    }
}

//toDo: Esta funcion no me acaba de convencer
bool Directorio::existeEnlaceDirectorio(const std::string& nombre) {
    if (existeNodo(nombre)) {
        // Para casteos necesario el vitual en el padre
        auto enlace = std::dynamic_pointer_cast<Enlace>(mapaDeNombres.find(nombre)->second);
        if (enlace != nullptr){
            return std::dynamic_pointer_cast<Directorio>(enlace->solve(0)) != nullptr;
        } else{
            return false;
        }
    }else{
        return false;
    }
}

bool Directorio::existeEnlaceFichero(const std::string &nombre) {
    if (existeNodo(nombre)) {
        // Para casteos necesario el vitual en el padre
        auto enlace = std::dynamic_pointer_cast<Enlace>(mapaDeNombres.find(nombre)->second);
        if (enlace != nullptr){
            return std::dynamic_pointer_cast<Fichero>(enlace->solve(0)) != nullptr;
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
    return std::dynamic_pointer_cast<Directorio>(enlace->solve(0));
}

std::shared_ptr<Nodo> Directorio::solve(int num) {
    return shared_from_this();
}

void Directorio::vi(const std::string& nombre, int size) {
    if (existeFichero(nombre) || existeEnlaceFichero(nombre)){
        auto fichero = std::dynamic_pointer_cast<Fichero>(mapaDeNombres.find(nombre)->second->solve(0));
       fichero->actualizarTamanio(size);
    } else {
        if (existeNodo(nombre)){
            //si existe un nodo que no es fichero excepcion
            //std::logic_error errorVi("El elemento a editar no es un fichero\n");
           //throw errorVi;
           throw excepcion_error_sintactico(nombre);
        } else {
            introducirNodo(nombre, std::make_shared<Fichero>(nombre, size));
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
    introducirNodo(nombre,  std::make_shared<Enlace>(nombre, nodo));
}

void Directorio::rm(const std::string& nombre) {
    mapaDeNombres.erase(nombre);
}


