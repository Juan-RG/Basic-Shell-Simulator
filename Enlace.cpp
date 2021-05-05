//
// Created by Juan on 24/04/2021.
//

#include "Enlace.h"

int Enlace::calcularTamanyo() {
    int n = 0;
    std::cout << n++ << "\n";
    std::cout << "paso cte \n";
    if (!resuelto){
        resuelto = 1;
        return enlace->calcularTamanyo();
    }else{
        throw 2;
    }
    return enlace->calcularTamanyo();
}
void Enlace::actualizarNodo() {
    resuelto = 0;
}

std::shared_ptr<Nodo> Enlace::getLink() {
    return enlace;
}
/*
std::shared_ptr<Nodo> Enlace::solve() {
    return solve(1);

}*/
std::shared_ptr<Nodo> Enlace::solve(int numero) {
    std::cout << "paso solve \n";
    if (numero >180){
        throw 5;
    }
    return enlace->solve(numero + 1);
}
/*
void Enlace::actualizarTamanio(int incremento) {    //TODO: NO VEO OTRA FORMA PERO ESTO ESTA MU FEO
    throw 15;   //Soltar excepcion de que no puedes modificar a la fuerta el tam de un dir?
}

 */