//
// Created by Juan on 24/04/2021.
//

#include "Enlace.h"

int Enlace::calcularTamanyo() {

    return enlace->calcularTamanyo();
    return enlace->calcularTamanyo();
}

std::shared_ptr<Nodo> Enlace::getLink() {
    return enlace;
}
/*
std::shared_ptr<Nodo> Enlace::solve() {
    return solve(1);

}*/
std::shared_ptr<Nodo> Enlace::solve(int numero) {
    if (numero > 10){
        throw 5;
    }
    return std::shared_ptr<Nodo>(enlace->solve(numero + 1));
}
/*
void Enlace::actualizarTamanio(int incremento) {    //TODO: NO VEO OTRA FORMA PERO ESTO ESTA MU FEO
    throw 15;   //Soltar excepcion de que no puedes modificar a la fuerta el tam de un dir?
}

 */