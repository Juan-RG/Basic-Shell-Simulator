//
// Created by Juan on 24/04/2021.
//

#pragma once


class Arbol_ficheros_error : public std::exception {
public:
    const char * what() const noexcept override;
};



