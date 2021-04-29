//
// Created by Juan on 24/04/2021.
//

#pragma once


#include "Nodo.h"

class Fichero : public Nodo {

private:
    double tamanyo;
public:

    Fichero(std::string nombre, std::shared_ptr<Nodo> padre): Nodo(nombre, padre){};
};



