#include "Prestamo.h"
#include "ArchivoPrestamos.h"

#include <iostream>
#include<cstring>

using namespace std;

///getters y setters:
    bool Prestamo:: setIsbn (int isbn){
    if(isbn>=9000000000000&& isbn<=9999999999999){
            _isbn=isbn;
            return true;
        }
        else{
            cout<<"Isbn debe contener 13 digitos"<<endl;
            return false; ///valor no valido
        }
    }


    void Prestamo:: setIdSocio(int idSocio){
        if(idSocio>=10000000 && idSocio<=99999999){
            _idSocio=idSocio;
        }
        else{
            cout<<"IdSocio debe contener 8 digitos"<<endl;
            _idSocio=-1; ///valor no valido
        }
    }


    void Prestamo:: setFechaPrestamo(Fecha fechaPrestamo){
    _fechaPrestamo=fechaPrestamo;
    }
    void Prestamo:: setFechaDevolucion(Fecha fechaDevolucion){
    _fechaDevolucion=fechaDevolucion;
    }
    void Prestamo::setPrestamoActivo(bool prestamoActivo){
    }

    int Prestamo:: getIsbn(){
    return _isbn;
    }
    int Prestamo:: getIdSocio(){
    return _idSocio;
    }
    Fecha Prestamo:: getFechaPrestamo(){
    return _fechaPrestamo;
    }
    Fecha Prestamo:: getFechaDevolucion(){
    return _fechaDevolucion;
    }
    int Prestamo::getPrestamoActivo(){
    return _prestamoActivo;
    }


///metodos:
    bool Prestamo:: CargarPrestamo(){
    }
    bool Prestamo:: CargarDevolucion(){
    }

    void Prestamo:: MostrarPrestamoInactivos(){
    }

    void Prestamo:: MostrarPrestamoActivos(){
    }
