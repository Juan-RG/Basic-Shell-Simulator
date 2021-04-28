//
// Created by Juan on 24/04/2021.
//

#pragma once


#include "Directorio.h"

class Ruta {
private:
    Directorio raiz;

    std::vector<std::shared_ptr<Nodo>> directorios;


public:
    Ruta(Directorio& raiz):raiz(raiz){};

    /*Sin hacer no me gusta la dclaracion pero con string no va <<*/
    std::string pwd();

    /*Sin hacer no me gusta la dclaracion pero con string no va <<*/
    std::string ls();

    double du();

    void vi(std::string nombre, int size);                                                          //ToDo:: Falta de implementar

    void mkdir(std::string nombre);

    void cd(std::string nombre);

    void ln(std::string path, std::string nombre);

    int stat(std::string path);

    void rm(std::string path);
};





