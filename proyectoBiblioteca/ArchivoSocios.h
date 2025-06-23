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

    int getCantidadRegistros();
    bool agregarRegistro(Socio regSocio);
    Socio leer(int pos);
    void listarRegistros();
    int buscarID(int id);
    bool modificarRegistro(Socio reg, int pos);
    bool bajaRegistro(int id);



/*

bool listarRegistrosOrdenadosPorIdSocio();
bool listarRegistrosOrdenadosPorApellido();
int buscarSocioPorDNI();
int buscarSocioPorIdSocio();
*/






};
