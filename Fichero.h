//
// Created by Juan on 24/04/2021.
//

#pragma once


#include "Nodo.h"


class Fichero : Nodo{
private:
    int tamanyo;
public:
    Fichero(std::string nombre_, int tamanyo_): Nodo(nombre_), tamanyo(tamanyo_){}

    int getTamanyo();
};



