#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ruta.h"
#include "Directorio.h"



using namespace std;

int main() {
    std::vector<std::shared_ptr<Nodo>> contenido; //todo: cambiar por map


    std::shared_ptr<Directorio> raiz = std::make_shared<Directorio>("hola");

    std::shared_ptr<Directorio> directorio = std::make_shared<Directorio>("prueba");
    std::shared_ptr<Enlace> enlace = std::make_shared<Enlace>("prueba2",directorio);


    contenido.push_back(directorio);
    contenido.push_back(enlace);

    for (auto d : contenido) {
        cout << d->getNombre() << "aa\n";
    }

}