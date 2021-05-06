//
// Created by Juan on 24/04/2021.
//

#pragma once

#include <vector>
#include "Directorio.h"

class Ruta {
private:
    //Variables
    std::shared_ptr<Directorio> raiz;
    std::vector<std::shared_ptr<Directorio>> directorios;

    //Funciones
    void introducirDirectorio(std::string nombre);

    std::vector<std::string> pathToVector(std::string path);

    std::shared_ptr<Directorio> rutaAbsoluta(std::vector<std::string>& ruta);

    std::shared_ptr<Directorio> rutaRelativa(std::vector<std::string>& ruta);

    std::shared_ptr<Directorio> raizOrDirectory();

public:

    Ruta(const Directorio& raiz){
        this->raiz = std::make_shared<Directorio>(raiz);
    };

    Ruta(std::shared_ptr<Directorio> ptr){
        this->raiz = ptr;
    };

    std::string pwd();

    std::string ls();

    std::string du();

    void vi(std::string nombre, int size);

    void mkdir(const std::string& nombre);

    void cd(std::string nombre);

    void ln(std::string path, std::string nombre);

    int stat(std::string path);

    void rm(std::string path);

};