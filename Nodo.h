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

    Nodo(std::string nombre): nombre(nombre){
        if (nombre.empty()){
            this->nombre = "/";
        } else {
            this->nombre = nombre;
        }
    };

    virtual ~Nodo(){

    }

    virtual std::shared_ptr<Nodo> solve(int nivel) = 0;

    virtual int calcularTamanyo() = 0;

    std::string getNombre();

    virtual void actualizarNodo() = 0;
};



