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
#include "Enlace.h"

class Directorio : public Nodo {
private:
    //Variables

    std::map<std::string, std::shared_ptr<Nodo>> mapaDeNombres;

    //funciones
    void introducirNodo(const std::string&  nombre,const std::shared_ptr<Nodo>& nuevoNodo);
public:

    Directorio(std::string nombre = "/"): Nodo(nombre){};

    ~Directorio() override{};

    bool existeDirectorio(const std::string& nombre);

    bool existeFichero(const std::string& nombre);

    bool existeEnlace(std::string nombre);

    bool existeEnlaceCD(const std::string& nombre);

    bool existeNodo(const std::string& nombre);

    //void agregarNodo(std::shared_ptr<Nodo> nuevoNodo);

    std::shared_ptr<Nodo> obtenerNodo(const std::string& nombre);

    std::shared_ptr<Directorio> obtenerDirectorio(const std::string& nombre);

    //std::shared_ptr<Fichero> obtenerFichero(std::string nombre);

   // std::shared_ptr<Enlace> obtenerEnlace(std::string nombre);

    std::shared_ptr<Directorio> obtenerDirectorioEnlace(const std::string& nombre);

    int calcularTamanyo() override;

    //void actualizarTamanio(int incremento) override;

    /*No podra añadir un nuevo nodo si ya existe uno con ese nombre*/
    void mkdir(const std::string& nombre);

    void vi(const std::string& nombre, int size);

    std::string du();

    std::string ls();

    void ln(const std::string& nombre, const std::shared_ptr<Nodo>& nodo);

    void rm(const std::string& nombre);

};



