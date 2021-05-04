//
// Created by Juan on 24/04/2021.
//

#pragma once

#include <string>
#include "Nodo.h"

class Enlace : public Nodo {
private:
    std::shared_ptr<Nodo> enlace;

    //Funciones

public:

    Enlace(std::string nombre, std::shared_ptr<Nodo> enlace): enlace(enlace), Nodo(nombre) {};

    ~Enlace() override{};

   // std::shared_ptr<Nodo> solve() override;
    std::shared_ptr<Nodo> solve(int numero) override;

    int calcularTamanyo() override;

    //void actualizarTamanio(int incremento) override;

    std::shared_ptr<Nodo> getLink();




};



