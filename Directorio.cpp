//
// Created by Juan on 24/04/2021.
//

#include "Directorio.h"
#include <algorithm>

void Directorio::mkdir(std::string nombre) {
    //void Directorio::mkdir(std::shared_ptr<Nodo> nuevoNodo) {
    //std::cout << (std::find(contenido.begin(), contenido.end(), nuevoNodo) == contenido.end()) <<"\n";
    //if (std::find(contenido.begin(), contenido.end(), nuevoNodo) == contenido.end()) {

    auto resultado = std::find_if(contenido.begin(), contenido.end(), [&](std::shared_ptr<Nodo> const& p) {
        return *p == *nuevoNodo; // assumes MyType has operator==
    });

    //Directorio a = dynamic_cast<Directorio*>(**resultado);
//    std::shared_ptr<Directorio> bp = std::dynamic_pointer_cast<Directorio>(*resultado);
//    std::cout << bp->getTamanyo()<< "\n";

    if (resultado == contenido.end()) {
       // contenido.push_back(*nuevoNodo);
        contenido.push_back(nuevoNodo);
    } else {
        throw 2;
        //excepcion de que el nombre existe
    }
}


