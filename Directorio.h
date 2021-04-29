//
// Created by Juan on 24/04/2021.
//

#pragma once


#include <string>
#include <vector>
#include <memory>
#include <map>
#include "Nodo.h"

class Directorio : public Nodo {
private:
    std::vector<std::shared_ptr<Nodo>> contenido; //todo: cambiar por map
    std::map<std::string,std::string> mapaDeNombres;
   // std::vector<Nodo> contenido;

    bool existeNodo(std::string nombre);
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
    void mkdir(std::string nombre);




};



