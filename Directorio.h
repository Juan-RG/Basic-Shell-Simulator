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

class Directorio : public Nodo, public std::enable_shared_from_this<Directorio> {
private:
    //Variables
    std::map<std::string, std::shared_ptr<Nodo>> mapaDeNombres;

    //funciones
    void introducirNodo(const std::string&  nombre,const std::shared_ptr<Nodo>& nuevoNodo);
public:
    void actualizarNodo() override;

    Directorio(std::string nombre = "/"): Nodo(nombre){};

    virtual ~Directorio() override;

    std::shared_ptr<Nodo> solve(int num) override;

    bool existeDirectorio(const std::string& nombre);

    bool existeFichero(const std::string& nombre);

    bool existeEnlaceDirectorio(const std::string& nombre);

    bool existeEnlaceFichero(const std::string& nombre);

    bool existeNodo(const std::string& nombre);

    std::shared_ptr<Nodo> obtenerNodo(const std::string& nombre);

    std::shared_ptr<Directorio> obtenerDirectorio(const std::string& nombre);

    std::shared_ptr<Directorio> obtenerDirectorioEnlace(const std::string& nombre);

    int calcularTamanyo() override;

    void mkdir(const std::string& nombre);

    void vi(const std::string& nombre, int size);

    std::string du();

    std::string ls();

    void ln(const std::string& nombre, const std::shared_ptr<Nodo>& nodo);

    void rm(const std::string& nombre);

};



