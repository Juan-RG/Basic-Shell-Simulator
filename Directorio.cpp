//
// Created by Juan on 24/04/2021.
//

#include "Directorio.h"
#include <algorithm>

void Directorio::agregarNodo(std::shared_ptr<Nodo> nuevoNodo) {
    if (std::find(contenido.begin(), contenido.end(), nuevoNodo) == contenido.end()) {
        std::cout << " paso \n";
        contenido.push_back(nuevoNodo);
    } else {
        std::cout << " existe ";
        //excepcion de que el nombre existe
    }
}
