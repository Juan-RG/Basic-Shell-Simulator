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

public:
    //el tamaño cuando se genere sera 0 y el numero de referencias 0, el & revisar no creo que este 100% bien
    Nodo(std::string nombre): nombre(nombre), enlaces(0){}
    Nodo(std::string nombre, std::shared_ptr<Nodo> padre): nombre(nombre), enlaces(0){}

/*    Nodo(std::string nombre): nombre(nombre), tamanyo(0), enlaces(0){
    Nodo(std::string nombre): nombre(nombre), enlaces(0){
        if (nombre.empty()){
            nombre = "/";
            this->nombre = nombre;
        }
        /*
        else{
            this->nombre = nombre;
        }*/
  //  };

    void actualizarTamanio(double incremento);
    virtual int calcularTamanyo();

    std::string getNombre();

    bool operator==(const Nodo& nodo)
    {
       if(this->nombre.compare(nodo.nombre))
            return false;
        else
            return true;
    }

/* funciona sin vector shared_pointer
    bool operator==(const std::shared_ptr<Nodo>& rhs)
    {
        if(this->nombre.compare(rhs->nombre))
            return false;
        else
            return true;
    }
    */
/*                                                              Eliminar
     bool operator==(const Nodo& obj2) const
    {
         std::cout << "n1: "<< this->nombre << "\n";
         std::cout << "n2: "<< obj2.nombre << "\n";
        if(this->nombre.compare(obj2.nombre))
            return false;
        else
            return true;
    }

    bool operator==(const std::shared_ptr<Nodo>& obj2) const
    {
        std::cout << "-n1: "<< this->nombre << "\n";
        std::cout << "-n2: "<< obj2->nombre << "\n";
        if(this->nombre == obj2->nombre)
            return true;
        else
            return false;
    }

    */

};



