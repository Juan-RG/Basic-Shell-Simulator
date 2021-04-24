//
// Created by Juan on 24/04/2021.
//

#pragma once


#include <string>
#include <vector>
#include "Nodo.h"

class Directorio : Nodo {
private:
    std::vector<Nodo> contenido;
public:
    //borrar el constructor vacio de nodo y preguntarle el por que
    //falta la gestion de .. y .
    Directorio(std::string nombre): Nodo(nombre){};
    /*
    Directorio(std::string nombre): Nodo(){
        if (nombre.empty()){
            Directorio::Nodo("/", nullptr);
        }else{
            Directorio::Nodo(nombre, nullptr);
        }
    };
*/
    /*No podra añadir un nuevo nodo si ya existe uno con ese nombre*/
    void agregarNodo(Nodo nuevoNodo);
};



