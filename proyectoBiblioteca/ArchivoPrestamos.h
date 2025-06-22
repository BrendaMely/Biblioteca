#pragma once

#include "Prestamo.h"
#include "string.h"

class ArchivoPrestamos{
private:
    char _nombreArchivo[30];
    int _tamanioRegistro;

public:
    ArchivoPrestamos(const char* nombreArchivo="Prestamo.dat"){
    strcpy(_nombreArchivo, nombreArchivo);
    _tamanioRegistro=sizeof(Prestamo);
    }

    int buscarPrestamoXIdSocio(int idSocio);


};
