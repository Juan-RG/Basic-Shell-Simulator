//
// Created by Juan on 24/04/2021.
//

#pragma once

#include <string>
#include <iostream>
#include <memory>
#include "Arbol_ficheros_error.h"

class Nodo {
private:
    //Variables
    std::string nombre;

public:

    //Nodo(std::string nombre): nombre(nombre), enlaces(0){}

    Nodo(std::string nombre): nombre(nombre){
        if (nombre.empty()){
            this->nombre = "/";
        } else {
            this->nombre = nombre;
        }
    };

    virtual ~Nodo(){

    }

    virtual int calcularTamanyo() = 0;

    std::string getNombre();
/*
    bool operator==(const Nodo& nodo) {
        std::cout << this->nombre.compare(nodo.nombre);
        if (this->nombre.compare(nodo.nombre)){
            return false;
        }else{
            return true;
        }
    }
*/

};



