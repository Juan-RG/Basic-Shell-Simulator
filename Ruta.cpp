//
// Created by Juan on 24/04/2021.
//

#include "Ruta.h"

void Ruta::cd(std::string nombre) {
    if(directorios.back()->existeDirectorio(nombre)){

    } else{
        throw 2;
    }
}

std::string Ruta::du() {
    return directorios.back()->du();
}


void Ruta::ln(std::string path, std::string nombre) {

}

std::string Ruta::ls() {
    return directorios.back()->ls();
}

void Ruta::mkdir(std::string nombre) {
    directorios.back()->mkdir(nombre);
}

std::string Ruta::pwd() {
    if (directorios.empty()){
        return raiz.getNombre() + "\n" ;
    } else{
        return directorios.back()->pwd();
    }
}

void Ruta::rm(std::string path) {

}

int Ruta::stat(std::string path) {
    return 0;
}

/*void vi(str name, int size): Edita el fichero de nombre ”name” (en el directorio actual). Para
simular la edición, simplemente se cambia el tamaño del fichero al valor especificado como
parámetro. Si el fichero no existe, se debe crear con el nombre y tamaño especificados.*/
void Ruta::vi(std::string nombre, int size) {
    //directorios.back()->existeFichero(nombre, directorios.back(), size);
}


