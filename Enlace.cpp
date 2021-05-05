//
// Created by Juan on 24/04/2021.
//

#include "Enlace.h"

int Enlace::calcularTamanyo() {
    if (!resuelto){
        resuelto = true;
        return enlace->calcularTamanyo();
    }else{
        resuelto = false;
        //Error enlace ya resuleto
        throw 2;
    }
}
void Enlace::actualizarNodo() {
    resuelto = false;
}
std::shared_ptr<Nodo> Enlace::solve(int numero) {
    if (numero > 180){
        //error bucle infinito de enlaces yo creo que no es posible pero bueno lo comentado en tutos
        throw 5;
    }
    return enlace->solve(numero + 1);
}
