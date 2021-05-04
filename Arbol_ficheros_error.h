//
// Created by Juan on 24/04/2021.
//

#pragma once

#include <exception>
#include <string>
/*
class Arbol_ficheros_error : public std::exception {
public:
    const char * what() const noexcept override;
};*/

class Arbol_ficheros_error : public std::exception {
    std::string ex, msg;

public:
    Arbol_ficheros_error(std::string ex_) : ex(ex_){}
    //const std::string& expresion() const {return ex;}

    const char* what() const noexcept override {    //No se que hace
        return ex.c_str();
    }
};

class excepcion_nodo_existe : public Arbol_ficheros_error {
public:
    excepcion_nodo_existe(const std::string& e) : Arbol_ficheros_error(e) {}
};

class excepcion_nodo_no_encontrado : public Arbol_ficheros_error {
public:
    excepcion_nodo_no_encontrado(const std::string& e) : Arbol_ficheros_error(e) {}
};

class excepcion_error_sintactico : public Arbol_ficheros_error {
public:
    excepcion_error_sintactico(const std::string& e) : Arbol_ficheros_error(e) {}
};