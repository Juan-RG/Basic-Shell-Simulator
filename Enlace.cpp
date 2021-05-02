//
// Created by Juan on 24/04/2021.
//

#include "Enlace.h"

int Enlace::calcularTamanyo() {
    return enlace->calcularTamanyo();
}

std::shared_ptr<Nodo> Enlace::getLink() {
    return enlace;
}