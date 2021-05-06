//
// Created by Juan on 24/04/2021.
//

#pragma once

#include <exception>
#include <string>

class Arbol_ficheros_error : public std::exception {
    std::string ex;
public:
    Arbol_ficheros_error(std::string ex_) : ex(ex_){}

   const char* what() const noexcept override {
        return ex.c_str();
    }
};

class excepcion_nodo_existe : public Arbol_ficheros_error {
public:
    excepcion_nodo_existe(const std::string& e) : Arbol_ficheros_error(e) {}
};

class excepcion_dir_vacio : public Arbol_ficheros_error {
public:
    excepcion_dir_vacio(const std::string& e) : Arbol_ficheros_error(e) {}
};

class excepcion_nodo_no_encontrado : public Arbol_ficheros_error {
public:
    excepcion_nodo_no_encontrado(std::string ex, bool dir, bool enlace)
            : Arbol_ficheros_error(ex) {
        if(!dir){
            Arbol_ficheros_error("No se ha encontrado el directorio " + ex + "\n");
        } else if(!enlace){
            Arbol_ficheros_error("No se ha encontrado el enlace " + ex + "\n");
        } else{
            Arbol_ficheros_error("No se ha encontrado el fichero " + ex + "\n");
        }
    }

    excepcion_nodo_no_encontrado(std::string nombre, std::string path)
    : Arbol_ficheros_error("No se encuentra ningun elemento con nombre " + nombre + " en la ruta " + path + "\n"){ }

    excepcion_nodo_no_encontrado(std::string ex)
    : Arbol_ficheros_error("No se ha encuentrado el directorio con el nombre " + ex){ }
};

class excepcion_error_sintactico : public Arbol_ficheros_error {
public:
    excepcion_error_sintactico(const std::string& e)
    : Arbol_ficheros_error("El elemento " + e + " a editar no es un fichero\n") { }

    excepcion_error_sintactico(const std::string& e, int size)
    : Arbol_ficheros_error("El elemento " + e + " no puede tener tamanyo " + std::to_string(size) + ", valor negativo\n") { }
};

class excepcion_bucle_enlace : public Arbol_ficheros_error {
public:
    excepcion_bucle_enlace(int e)
    : Arbol_ficheros_error("Numero de enlaces continuos superado: " + std::to_string(e) + "\n") { }

    excepcion_bucle_enlace(const std::string& e)
    : Arbol_ficheros_error(e) { }
};