//
// Created by Juan on 24/04/2021.
//

#pragma once

#include <string>
#include "Nodo.h"

class Enlace : public Nodo, public std::enable_shared_from_this<Nodo> {
private:
    std::shared_ptr<Nodo> enlace;
    bool resuelto = 0;

public:

    Enlace(std::string nombre, std::shared_ptr<Nodo> enlace): enlace(std::move(enlace)), Nodo(nombre) {};

    ~Enlace() override{};

    std::shared_ptr<Nodo> solve(int numero) override;

    int calcularTamanyo() override;

    void actualizarNodo() override;

};



