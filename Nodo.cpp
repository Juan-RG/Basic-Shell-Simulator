//
// Created by Juan on 24/04/2021.
//

#include "Nodo.h"

void Nodo::actualizarTamanio(double incremento) {
    tamano += incremento;
}


std::string Nodo::getNombre(){
    return nombre;
}

double Nodo::getTamanyo(){
    return tamanyo;
}