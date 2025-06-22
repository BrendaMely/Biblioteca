#pragma once

#include "Suscripcion.h"
#include "string.h"

class ArchivoSuscripciones{
private:
    char _nombreArchivo[30];
    int _tamanioRegistro;

public:
    ArchivoSuscripciones(const char* nombreArchivo="Suscripcion.dat"){
    strcpy(_nombreArchivo, nombreArchivo);
    _tamanioRegistro=sizeof(Suscripcion);
    }

    int buscarSuscriptorXIdSocio(int idSocio);

};
