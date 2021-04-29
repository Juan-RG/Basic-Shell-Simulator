//
// Created by Juan on 24/04/2021.
//

#pragma once


#include "Directorio.h"

class Enlace : public Nodo {
private:
    std::shared_ptr<Nodo> enlace;
public:

    Enlace(std::string nombre): Nodo(nombre){};
    int calcularTamanyo() override;
};



