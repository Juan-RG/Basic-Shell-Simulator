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
    //std::vector<std::shared_ptr<Nodo>> contenido; //todo: cambiar por map
    std::map<std::string,std::shared_ptr<Nodo>> mapaDeNombres;

    //funciones
    void introducirNodo(std::string  nombre,std::shared_ptr<Nodo> nuevoNodo);
public:

    Directorio(std::string nombre = "/"): Nodo(nombre){};

    bool existeDirectorio(std::string nombre);

    bool existeFichero(std::string nombre);

    bool existeEnlace(std::string nombre);

    bool existeEnlaceCD(std::string nombre);

    bool existeNodo(std::string nombre);

    void agregarNodo(std::shared_ptr<Nodo> nuevoNodo);

    std::shared_ptr<Nodo> obtenerNodo(std::string nombre);

    std::shared_ptr<Directorio> obtenerDirectorio(std::string nombre);

    std::shared_ptr<Fichero> obtenerFichero(std::string nombre);

    std::shared_ptr<Enlace> obtenerEnlace(std::string nombre);

    std::shared_ptr<Directorio> obtenerDirectorioEnlace(std::string nombre);

    int calcularTamanyo() override;

    void actualizarTamanio(int incremento) override;

    /*No podra añadir un nuevo nodo si ya existe uno con ese nombre*/
    void mkdir(std::string nombre);

    void vi(std::string nombre, int size);

    std::string du();

    std::string ls();

    void ln(std::string nombre, std::shared_ptr<Nodo> nodo);



    virtual ~Directorio(){};

    void rm(std::string nombre);

};



