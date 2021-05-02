//
// Created by Juan on 24/04/2021.
//

#pragma once


#include "Directorio.h"

class Ruta {
private:
    //Variables
    std::shared_ptr<Directorio> raiz;  //todo: usar la forma de raiz no se añade en directorios es simplemente la / extructura unix puro
    std::vector<std::shared_ptr<Directorio>> directorios;

    //Funciones
    void introducirDirectorio(std::string nombre);

    std::vector<std::string> pathToVector(std::string path);

    std::shared_ptr<Directorio> rutaAbsoluta(std::vector<std::string>& ruta);

    std::shared_ptr<Directorio> rutaRelativa(std::vector<std::string>& ruta);

public:
    Ruta(Directorio& raiz){
        this->raiz = std::make_shared<Directorio>(raiz);
    };

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





