//
// Created by Juan on 24/04/2021.
//

#pragma once


#include "Directorio.h"

class Ruta {
private:
    Directorio raiz;  //todo: usar la forma de raiz no se añade en directorios es simplemente la / extructura unix puro

    std::vector<std::shared_ptr<Directorio>> directorios;


public:
    Ruta(Directorio& raiz):raiz(raiz){};

    std::string pwd();

    std::string ls();

    std::string du();

    void vi(std::string nombre, int size);      //ToDo:: Falta de implementar

    void mkdir(std::string nombre);

    void cd(std::string nombre);

    void ln(std::string path, std::string nombre);

    int stat(std::string path);

    void rm(std::string path);
};





