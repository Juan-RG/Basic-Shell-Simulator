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
    int enlaces;

public:

    Nodo(std::string nombre, std::shared_ptr<Nodo> padre): nombre(nombre), enlaces(0){}

    Nodo(std::string nombre): nombre(nombre), enlaces(0){
        if (nombre.empty()){
            nombre = "/";
            this->nombre = nombre;
        }

        else{
            this->nombre = nombre;
        }
    };

    //virtual ~Nodo(){};

    void actualizarTamanio(double incremento);
    virtual int calcularTamanyo();

    std::string getNombre();

    bool operator==(const Nodo& nodo) {
        if (this->nombre.compare(nodo.nombre)){
            return false;
        }else{
            return true;
        }
    }


};



