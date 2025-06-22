#pragma once
#include "Fecha1.h"

class Libro{
private:
    int _isbn;
    char _libro[50];
    int _idAutor;
    Fecha _fechaDePublicacion;
    int _cantidadEjemplares;


public:
    ///getters y setters:
    bool setIsbn (int isbn);
    void setLibro (const char* libro);
    bool setIdAutor(int idAutor);
    void setFechaDePublicacion(Fecha fechaDePublicacion);
    bool setCantidadEjemplares(int cantidadEjemplares);

    int getIsbn() ;
    char* getLibro() ;
    int getIdAutor() ;
    Fecha getFechaDePublicacion() ;
    int getCantidadEjemplares() ;


    ///metodos:
    bool Cargar(int isbn=0);
    void Mostrar();
};

