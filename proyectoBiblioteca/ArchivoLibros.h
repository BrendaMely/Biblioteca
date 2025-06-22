#pragma once

#include "Libro.h"
#include "string.h"

class ArchivoLibros{
private:
    char _nombreArchivo[30];
    int _tamanioRegistro;


public:
    ArchivoLibros(const char* nombreArchivo="Libro.dat"){
    strcpy(_nombreArchivo, nombreArchivo);
    _tamanioRegistro=sizeof(Libro);
    }

    int buscarLibroXISBN(int isbn);



};
