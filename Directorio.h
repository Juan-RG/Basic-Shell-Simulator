//
// Created by Juan on 24/04/2021.
//

#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>
#include "Fichero.h"
#include "Nodo.h"

class Directorio : public Nodo {
private:
    std::vector<std::shared_ptr<Nodo>> contenido; //todo: cambiar por map
    std::map<std::string,std::shared_ptr<Nodo>> mapaDeNombres;
   // std::vector<Nodo> contenido;

    bool existeNodo(std::string nombre);
    void introducirNodo(std::string  nombre,std::shared_ptr<Nodo> nuevoNodo);
public:
    //borrar el constructor vacio de nodo y preguntarle el por que
    //falta la gestion de .. y .

    //Directorio(std::string nombre = "/"): Nodo(nombre){};
    Directorio(std::string nombre = "/"): Nodo(nombre){};

    bool existeDirectorio(std::string nombre);
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

    //void agregarNodo(std::shared_ptr<Nodo> nuevoNodo);
    int calcularTamanyo() override;

    /*No podra añadir un nuevo nodo si ya existe uno con ese nombre*/
    void mkdir(std::string nombre);
    std::string du();
    std::string ls();
    std::string pwd();
};



