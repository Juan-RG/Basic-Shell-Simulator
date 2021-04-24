cmake_minimum_required(VERSION 3.17)
project(p4)

set(CMAKE_CXX_STANDARD 20)

add_executable(p4 main.cpp Nodo.cpp Nodo.h Fichero.cpp Fichero.h Enlaces.cpp Enlaces.h Directorio.cpp Directorio.h Ruta.cpp Ruta.h)
add_executable(Pruebas mainPruebas.cpp)