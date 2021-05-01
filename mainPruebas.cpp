#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ruta.h"
#include "Directorio.h"
#include "Enlace.h"


using namespace std;

int main() {
    std::map<std::string,std::shared_ptr<Nodo>> mapaDeNombres;


    std::shared_ptr<Directorio> raiz = std::make_shared<Directorio>("hola");

    std::shared_ptr<Directorio> directorio = std::make_shared<Directorio>("prueba");
    std::shared_ptr<Enlace> enlace = std::make_shared<Enlace>("prueba2",directorio);


    mapaDeNombres.insert(std::pair<std::string , std::shared_ptr<Nodo>>(directorio->getNombre(), directorio));
    mapaDeNombres.insert(std::pair<std::string , std::shared_ptr<Nodo>>(enlace->getNombre(), enlace));

    for (auto d : mapaDeNombres) {
        cout << d.second->getNombre() << "\n";
    }

}