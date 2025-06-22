#pragma once

#include "Socio.h"
#include "string.h"

class ArchivoSocios{
private:
    char _nombreArchivo[30];
    int _tamanioRegistro;

public:
    ArchivoSocios(const char* nombreArchivo="Socio.dat"){
    strcpy (_nombreArchivo, nombreArchivo);
    _tamanioRegistro=sizeof(Socio);
    }

    int buscarSocioXDNI(const char* dniSocio);
/*
int agregarRegistro();
int agregarRegistro(Socio regSocio);
bool listarRegistros();
bool listarRegistrosOrdenadosPorIdSocio();
bool listarRegistrosOrdenadosPorApellido();
int buscarSocioPorDNI();
int buscarSocioPorIdSocio();
*/






};
