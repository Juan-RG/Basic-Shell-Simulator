#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "Nodo.h"
#include "Arbol_ficheros_error.h"
#include "Directorio.h"
#include "Fichero.h"
#include "Enlace.h"

#include "Ruta.h"


void pruebaAddNodoDirectorio();

void pruebaAddElementsDirectorio();

void pruebaRm();

void pruebaPWD();

void pruebaLs();

void pruebaDu();

void pruebaVi();

void pruebaMKDIR();

void pruebaCD();

void pruebaStat();

void pruebaln();

using namespace std;

int main()
{

   pruebaAddNodoDirectorio();
   pruebaAddElementsDirectorio();
   pruebaRm();
   pruebaPWD();
   pruebaLs();
   pruebaDu();
   pruebaVi();
   pruebaMKDIR();
   pruebaCD();
   pruebaStat();
   pruebaln();

    //lo dejamos asi por no tocar el main no perderiamos nada de informacion generando un shared_ptr como hacemos en los casos de prueba
    //asi el objeto se copia y se perdera. Pero en la practica no afecta por que se trabajara con la copia de ruta
   Directorio raiz("");
   Ruta ruta(raiz);


    for (bool done=false; !done; )
    {

        cout << ruta.pwd() << "> " << flush;

        // Leer linea de entrada
        string line;
        if (!getline(cin,line))
        {
            done = true;
            continue;
        }

        // Separar tokens
        vector<string> cmd;
        istringstream iss(line);
        for (string tok; iss >> tok; )
            cmd.push_back(tok);

        if (cmd.size()<1)
            continue;

        try
        {
            if ((cmd[0]=="exit") || (cmd[0]=="by"))
            {
                done = true;
            }
            else if (cmd[0]=="pwd")
            {
                cout << ruta.pwd() << endl;
            }
            else if (cmd[0]=="ls")
            {
                cout << ruta.ls() << endl;
            }
            else if (cmd[0]=="du")
            {
                cout << ruta.du() << endl;
            }
            else if (cmd[0]=="vi")
            {
                ruta.vi(cmd.at(1),stoi(cmd.at(2)));
            }
            else if (cmd[0]=="mkdir")
            {
                ruta.mkdir(cmd.at(1));
            }
            else if (cmd[0]=="cd")
            {
                ruta.cd(cmd.at(1));
            }
            else if (cmd[0]=="stat")
            {
                cout << ruta.stat(cmd.at(1)) << endl;
            }
            else if (cmd[0]=="ln")
            {
                ruta.ln(cmd.at(1),cmd.at(2));
            }
            else if (cmd[0]=="rm")
            {
                ruta.rm(cmd.at(1));
            }
            else
            {
                cerr << "Error sintactico: comando desconocido" << endl;
            }
        }
        catch (const Arbol_ficheros_error& e)
        {
            cerr << e.what() << endl;
        }
        catch (const out_of_range& e)
        {
            cerr << "Error sintactico: parametros insuficientes" << endl;
            cerr << e.what() << endl;
        }
    }

    cout << endl << "By!!" << endl;

    return 0;
}
void pruebaln(){
    std::shared_ptr<Directorio> raiz = std::make_shared<Directorio>("");
    Ruta ruta(raiz);
    ruta.vi("fichero",10);
    ruta.ln("fichero","enlace");

    if (!(ruta.du() == "enlace  10 Bytes\n"
                       "fichero  10 Bytes\n")){
        cerr << " Error en ln \n";
    }
}
void pruebaStat(){
    std::shared_ptr<Directorio> raiz = std::make_shared<Directorio>("");
    Ruta ruta(raiz);
    ruta.vi("fichero",10);
    if (ruta.stat("fichero") != 10){
        cerr << "error en stat\n";
    }
}
void pruebaCD(){
    std::shared_ptr<Directorio> raiz = std::make_shared<Directorio>("");
    Ruta ruta(raiz);
    ruta.mkdir("directorio");
    ruta.cd("directorio");
    if (!(ruta.pwd() == "/directorio/\n")){
        cerr << "error en cd\n";
    }

}
void  pruebaVi(){
    std::shared_ptr<Directorio> raiz = std::make_shared<Directorio>("");
    Ruta ruta(raiz);
    ruta.vi("fichero",10);

    if (!raiz->existeNodo("fichero")){
        cerr << " Error en vi \n";
    }

    ruta.vi("fichero",20);

    if (!ruta.stat("fichero") == 20){
        cerr << " Error en vi actualizar \n";
    }



}
void pruebaMKDIR(){
    std::shared_ptr<Directorio> raiz = std::make_shared<Directorio>("");
    Ruta ruta(raiz);
    ruta.mkdir("fichero");
    if (!raiz->existeNodo("fichero")){
        cerr << " Error en mkdir \n";
    }
}

void pruebaDu(){
    std::shared_ptr<Directorio> raiz = std::make_shared<Directorio>("");
    Ruta ruta(raiz);
    ruta.vi("fichero",10);
    ruta.ln("fichero","enlace");
    if (!(ruta.du() == "enlace  10 Bytes\n"
                         "fichero  10 Bytes\n")){
        cerr << " Error en du \n";
    }
}

void pruebaLs(){
    std::shared_ptr<Directorio> raiz = std::make_shared<Directorio>("");
    Ruta ruta(raiz);

    ruta.mkdir("directorio");
    ruta.vi("fichero",10);
    ruta.ln("fichero","enlace");

    if (!(ruta.ls() == ".\n"
                       "directorio\n"
                       "enlace\n"
                       "fichero\n")){
        cerr << " Error en ls \n";
    }

}
void  pruebaPWD(){
    std::shared_ptr<Directorio> raiz = std::make_shared<Directorio>("");
    Ruta ruta(raiz);

    ruta.mkdir("a");
    ruta.cd("a");

    if (!(ruta.pwd() == "/a/\n")){
        cerr << "error pwd\n";
    }
}

void pruebaAddNodoDirectorio() {
    bool error = false;
    Directorio raiz("");

    raiz.mkdir("file");
    try {
        raiz.mkdir("file");
    } catch (const Arbol_ficheros_error& e) {
        error = true;
    }

    if (!error){
        std::cerr << "Test: pruebaAddNodoDirectorio -- error Nodos con mismo nombre \n";
    } else {

    }
}

void pruebaAddElementsDirectorio() {

        std::shared_ptr<Directorio> raiz = std::make_shared<Directorio>("");
        Ruta ruta(raiz);

        ruta.mkdir("directorio");
        ruta.vi("Fichero",10);
        ruta.ln("Fichero", "enlace");

        if (!(ruta.ls() == ".\n"
                           "Fichero\n"
                           "directorio\n"
                           "enlace\n")){
            cerr << " comprobar con to_string cuando este. Hasta ahora funciona \n";
        }
}

void pruebaRm(){
    std::shared_ptr<Directorio> raiz = std::make_shared<Directorio>("");
    Ruta ruta(raiz);

    ruta.mkdir("directorio");
    ruta.vi("fichero",10);
    ruta.ln("fichero","enlace");
    ruta.rm("fichero");


    if (raiz->existeFichero("fichero")){
        cerr << "Error rm no elimina fichero\n";
    }

    ruta.rm("directorio");

    if (raiz->existeDirectorio("directorio")){
        cerr << "Error rm no elimina directorio\n";
    }

    ruta.rm("enlace");

    if (raiz->existeNodo("enlace")){
        cerr << "Error rm no elimina enlace\n";
    }
}
