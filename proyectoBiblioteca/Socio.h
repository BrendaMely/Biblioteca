#pragma once
#include "Fecha1.h"


class Socio{
private:
    char _dni[9];
    char _nombre[30];
    char _apellido[30];
    char _telefono[12];
    char _direccion[50];
    char _email[50];
    Fecha _fechaDeNacimiento;
    int _idSocio;


public:
    ///getters y setters:

    bool setDni(const char* dni);
    void setNombre(const char* nombre);
    void setApellido(const char* apellido);
    void setTelefono(const char* telefono);
    void setDireccion(const char* direccion);
    void setEmail(const char*email);
    void setFechaDeNacimiento(Fecha fechaDeNacimiento);
    void setIdSocio(int idSocio);

    char* getDni();
    char* getNombre();
    char* getApellido();
    char* getTelefono();
    char* getDireccion();
    char* getEmail();
    Fecha getFechaDeNacimiento();
    int getIdSocio();

    ///metodos:
   bool Cargar(const char* nuevoDni="NADA");
    void Mostrar();

};
