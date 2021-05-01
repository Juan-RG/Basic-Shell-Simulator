//
// Created by Juan on 24/04/2021.
//

#include "Directorio.h"

void Directorio::introducirNodo(std::string nombre, std::shared_ptr<Nodo> nuevoNodo) {
   //contenido.push_back(nuevoNodo);
    mapaDeNombres.insert(std::pair<std::string , std::shared_ptr<Nodo>>(nombre, nuevoNodo));
}

int Directorio::calcularTamanyo(){
    int size = 0;

    for(auto d : this->mapaDeNombres){ //TODO: comprobar recursividad con enlaces a padres
        size = size + d.second->calcularTamanyo();
    }

    return size;
}


bool Directorio::existeNodo(std::string nombre) {
    auto it = mapaDeNombres.find(nombre);
    if (it == mapaDeNombres.end()){
        return false;
    } else {
        return true;
    }
}

void Directorio::mkdir(std::string nombre) {
    if (existeNodo(nombre)){
        throw 5;
    } else {
        std::shared_ptr<Directorio> nuevoDir = std::make_shared<Directorio>(nombre);
        introducirNodo(nombre, nuevoDir);

    }
}

std::string Directorio::du() {
    std::string lista;

    if (!mapaDeNombres.empty()){
        for(auto d : this->mapaDeNombres){
            lista = lista + d.second->getNombre() + "  " + std::to_string(d.second->calcularTamanyo()) + " Bytes\n";
        }
    }else{
        throw 2;
    }

    return lista;
}

bool Directorio::existeDirectorio(std::string nombre) {

    if (existeNodo(nombre)) {

        auto nodo = mapaDeNombres.find(nombre)->second;
        // Para casteos necesario el vitual en el padre
        auto directorio = std::dynamic_pointer_cast<Directorio>(nodo);

        return directorio != nullptr;
    }else{
        return false;
    }
}


std::shared_ptr<Directorio> Directorio::obtenerDirectorio(std::string nombre) {
    return std::dynamic_pointer_cast<Directorio>(mapaDeNombres.find(nombre)->second);
}

bool Directorio::existeFichero(std::string nombre) {

    if (existeNodo(nombre)) {
        auto nodo = mapaDeNombres.find(nombre)->second;
        // Para casteos necesario el vitual en el padre
        auto fichero = std::dynamic_pointer_cast<Fichero>(nodo);

        return fichero != nullptr;
    }else{
        return false;
    }
}

void Directorio::vi(std::string nombre, int size) {
    if (existeFichero(nombre)){ //if (existeNodo(nombre)){ TODO: que existe uso??? Cual es la diferencia?
            throw 6;
    } else {
        std::shared_ptr<Fichero> nuevoFichero = std::make_shared<Fichero>(nombre, size);
        introducirNodo(nombre, nuevoFichero);
    }
}

std::string Directorio::ls() {
    std::string lista;
    for (auto d : this->mapaDeNombres) {
        lista = lista + d.second->getNombre() + "\n";
    }
    return lista;
}

std::shared_ptr<Nodo> Directorio::obtenerNodo(std::string nombre) {
    return mapaDeNombres.find(nombre)->second;
}

void Directorio::ln(std::shared_ptr<Nodo> enlace) {
    introducirNodo(enlace->getNombre(), enlace);
}

void Directorio::rm(std::string nombre) {
    mapaDeNombres.erase(nombre);
}
