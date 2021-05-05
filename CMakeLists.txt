cmake_minimum_required(VERSION 3.17)
project(p4)

set(CMAKE_CXX_STANDARD 20)

add_executable(p4 main.cc Nodo.cpp Nodo.h Fichero.cpp Fichero.h Enlace.cpp Enlace.h Directorio.cpp Directorio.h Ruta.cpp Ruta.h)

