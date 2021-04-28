//
// Created by Juan on 24/04/2021.
//

#pragma once

#include <string>
#include <iostream>
#include <memory>

class Nodo {
private:
    std::string nombre;
    int enlaces;
    std::shared_ptr<Nodo*> padre;
    double tamanyo;
public:
    //el tamaño cuando se genere sera 0 y el numero de referencias 0, el & revisar no creo que este 100% bien
    Nodo(std::string nombre, std::shared_ptr<Nodo*> padre): nombre(nombre), padre(padre), tamano(0), enlaces(0){}

    Nodo(std::string nombre): padre(nullptr), tamano(0), enlaces(0){
        if (nombre.empty()){
            nombre = "/";
            this->nombre = nombre;
        }else{
            this->nombre = nombre;
        }
    };

    void actualizarTamanio(double incremento);

    std::string getNombre(){
        return nombre;
    }

     bool operator==(const Nodo& obj2) const
    {
        if(this->nombre == obj2.nombre)
            return true;
        else
            return false;
    }
    double getTamanyo();
};



