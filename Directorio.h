//
// Created by Juan on 24/04/2021.
//

#pragma once


#include <string>
#include <vector>
#include <memory>
#include "Nodo.h"

class Directorio : public Nodo {
private:
    std::vector<std::shared_ptr<Nodo>> contenido;
   // std::vector<Nodo> contenido;
public:
    //borrar el constructor vacio de nodo y preguntarle el por que
    //falta la gestion de .. y .

    //Directorio(std::string nombre = "/"): Nodo(nombre){};
    Directorio(std::string nombre = "/"): Nodo(nombre){};

    Directorio(std::string nombre, std::shared_ptr<Directorio> padre): Nodo(nombre, padre){};

    //Todo:generar constructor

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
    void agregarNodo(std::shared_ptr<Nodo> nuevoNodo);
};



