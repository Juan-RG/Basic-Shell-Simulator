//
// Created by Juan on 24/04/2021.
//

#pragma once


#include "Directorio.h"

class Enlace : public Nodo {
private:
    std::shared_ptr<Nodo> enlace;
public:

    Enlace(std::string nombre, std::shared_ptr<Nodo> enlace): enlace(enlace), Nodo(nombre) {};

    int calcularTamanyo() override;

    std::shared_ptr<Nodo> getLink();

    virtual ~Enlace(){};


};



