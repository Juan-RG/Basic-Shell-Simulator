//
// Created by Juan on 24/04/2021.
//

#pragma once

#include "Nodo.h"

class Fichero : public Nodo, public std::enable_shared_from_this<Fichero>{
private:
    int tamanyo;
public:
    Fichero(std::string nombre_, int tamanyo_): Nodo(nombre_), tamanyo(tamanyo_){};

    ~Fichero() override {};

    std::shared_ptr<Nodo> solve(int num) override;

    int calcularTamanyo() override;

    void actualizarTamanio(int incremento);

    void actualizarNodo() override;
};



