//
// Created by Juan on 24/04/2021.
//

#include "Ruta.h"

void Ruta::cd(std::string nombre) {

}

std::string Ruta::du() {
    std::string lista;

    for(std::shared_ptr<Nodo> d : this->directorios){
        lista = lista + d->getNombre() + "  " + std::to_string(d->getTamanyo()) + " Bytes\n";
    }

    return lista;
}

void Ruta::ln(std::string path, std::string nombre) {

}

std::string Ruta::ls() {
    std::string lista;

    for(std::shared_ptr<Nodo> d : this->directorios){
        lista = lista + d->getNombre() + "\n";
    }

    return lista;
}

void Ruta::mkdir(std::string nombre) {
    std::shared_ptr<Directorio> nuevoDir = std::make_shared<Directorio>(nombre, directorios.back());
    directorios.back()->agregarNodo(nuevoDir);
}

std::string Ruta::pwd() {
    std::string ruta;

    for(std::shared_ptr<Nodo> d : this->directorios){
        if(d->getNombre() == "/"){
            ruta = d->getNombre();
        } else{
            ruta = ruta + "/" + d->getNombre();
        }
    }

    return ruta;
}

void Ruta::rm(std::string path) {

}

int Ruta::stat(std::string path) {
    return 0;
}

void Ruta::vi(std::string nombre, int size) { //Todo lo de buscar si existe, crear etc, se hace aqui o en dir como mkdir

}




