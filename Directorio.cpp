//
// Created by Juan on 24/04/2021.
//

#include "Directorio.h"

void Directorio::introducirNodo(std::string nombre, std::shared_ptr<Nodo> nuevoNodo) {
    contenido.push_back(nuevoNodo);
    mapaDeNombres.insert(std::pair<std::string , std::shared_ptr<Nodo>>(nombre, nuevoNodo));
}

int Directorio::calcularTamanyo(){
    int size;

    for(std::shared_ptr<Nodo> d : this->contenido){ //TODO: comprobar recursividad con enlaces a padres
        size = size + d->calcularTamanyo();
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

    for(std::shared_ptr<Nodo> d : this->contenido){
        lista = lista + d->getNombre() + "  " + std::to_string(d->calcularTamanyo()) + " Bytes\n";
    }

    return lista;
}

bool Directorio::existeDirectorio(std::string nombre) {

    if (existeNodo(nombre)) {

        auto nodo = mapaDeNombres.find(nombre)->second;
       // auto nodo = mapaDeNombres[nombre];

       // Para casteos necesario el vitual en el padre
       // auto directorio = std::dynamic_pointer_cast<Directorio>(nodo);

         }
    return true;
}

std::string Directorio::ls() {
    std::string lista;

    for (std::shared_ptr<Nodo> d : this->contenido) {
        lista = lista + d->getNombre() + "\n";
    }

    return lista;
}

std::string Directorio::pwd() {
    std::string ruta;

    for (std::shared_ptr<Nodo> d : this->contenido) {
        ruta = ruta + "/" + d->getNombre();
    }

    return ruta;
}
