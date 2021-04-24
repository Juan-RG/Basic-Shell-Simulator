//
// Created by Juan on 24/04/2021.
//

#pragma once

#include <string>
class Nodo {
private:
    std::string nombre;
    int enlaces;
    Nodo* padre;
    double tamano;
public:
    //el tamaño cuando se genere sera 0 y el numero de referencias 0, el & revisar no creo que este 100% bien
    Nodo(std::string nombre,Nodo* padre): nombre(nombre), padre(padre), tamano(0), enlaces(0){}

    Nodo(std::string nombre): nombre(nombre){};
};



