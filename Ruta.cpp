//
// Created by Juan on 24/04/2021.
//

#include "Ruta.h"

void Ruta::cd(std::string nombre) {
    if (directorios.empty()){
        if (nombre == "."){

        }else{
            if(raiz.existeDirectorio(nombre)){
                std::shared_ptr<Directorio> directorio = raiz.obtenerDirectorio(nombre);
                directorios.push_back(directorio);
            } else {

                throw 5;
            }
        }
    } else{
        if (nombre == "." || nombre == ".."){
            if (nombre == ".."){
                directorios.erase(directorios.end());
            }
        }else {
            if (directorios.back()->existeDirectorio(nombre)) {
                std::shared_ptr<Directorio> directorio = directorios.back()->obtenerDirectorio(nombre);
                directorios.push_back(directorio);
            } else {
                throw 5;
            }
        }
    }
}

std::string Ruta::du() {
    if (directorios.empty()){
       return raiz.du();
    }else{
        return directorios.back()->du();
    }
}


void Ruta::ln(std::string path, std::string nombre) {

}

std::string Ruta::ls() {
    std::string resultado;
    resultado += ".\n";
    if (directorios.empty()){
        return resultado += raiz.ls();
    }else{
        resultado += "..\n";
        return resultado += directorios.back()->ls();
    }
}

void Ruta::mkdir(std::string nombre) {
    if (directorios.empty()){
        raiz.mkdir(nombre);
    } else {
        directorios.back()->mkdir(nombre);
    }
}

std::string Ruta::pwd() {
    if (directorios.empty()){
        return raiz.getNombre() + "\n";
    } else{
        std::string ruta;
        ruta += raiz.getNombre();
        for (std::shared_ptr<Nodo> d : this->directorios) {
            ruta = ruta +  d->getNombre() + "/";
        }
        ruta += "\n";
        return ruta;
    }
}

void Ruta::rm(std::string path) {

}

int Ruta::stat(std::string path) {
    std::cout << path << "\n";
    return 0;
}

/*void vi(str name, int size): Edita el fichero de nombre ”name” (en el directorio actual). Para
simular la edición, simplemente se cambia el tamaño del fichero al valor especificado como
parámetro. Si el fichero no existe, se debe crear con el nombre y tamaño especificados.*/
void Ruta::vi(std::string nombre, int size) {
    //directorios.back()->existeFichero(nombre, directorios.back(), size);
}


