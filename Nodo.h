//
// Created by Juan on 24/04/2021.
//

#pragma once

#include <string>
#include <iostream>
#include <memory>

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

    virtual int calcularTamanyo() = 0;

    std::string getNombre();

    bool operator==(const Nodo& nodo) {
        if (this->nombre.compare(nodo.nombre)){
            return false;
        }else{
            return true;
        }
    }

    virtual ~Nodo(){

    }
};



