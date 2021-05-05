//
// Created by Juan on 24/04/2021.
//

#include "Fichero.h"

int Fichero::calcularTamanyo() {
    return tamanyo;
}

void Fichero::actualizarTamanio(int incremento) {
    std::cout << "actualizo\n";
    tamanyo = incremento;
}

std::shared_ptr<Nodo> Fichero::solve(int num){
    //return std::make_shared<Fichero>(*this);
    std::cout << "paso solve fichero\n";
    auto aa = shared_from_this();
    std::cout << "ooooooooo\n";
    std::cout << aa->getNombre() << "\n";
    return shared_from_this();
    //return std::make_shared<Fichero>(std::move(*this));
    //return std::shared_ptr<Fichero>(this);
}

void Fichero::actualizarNodo() {

}
