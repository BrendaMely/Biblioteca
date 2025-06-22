#pragma once

#include "Autor.h"
#include "string.h"

class ArchivoAutores{
private:
    char _nombreArchivo[30];
    int _tamanioRegistro;

public:
    ArchivoAutores(const char* nombreArchivo="Autor.dat"){
    strcpy(_nombreArchivo, nombreArchivo);
    _tamanioRegistro=sizeof(Autor);
    }

    int buscarAutorXIdAutor(int idAutor);


};
