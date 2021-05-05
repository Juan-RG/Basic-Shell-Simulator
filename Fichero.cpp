//
// Created by Juan on 24/04/2021.
//

#include "Fichero.h"

int Fichero::calcularTamanyo() {
    return tamanyo;
}

void Fichero::actualizarTamanio(int incremento) {
    tamanyo = incremento;
}

std::shared_ptr<Nodo> Fichero::solve(int num){
    return shared_from_this();
}

void Fichero::actualizarNodo() {

}
