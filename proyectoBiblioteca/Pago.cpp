#include "Pago.h"

#include <iostream>
#include<cstring>

using namespace std;

///getters y setters:

    void Pago:: setIdSocio(int idSocio){
    _idSocio=idSocio;
    }
    void Pago:: setFechaActual(Fecha fechaActual){
    _fechaActual=fechaActual;
    }
    void Pago:: setFechaDePago(Fecha fechaDePago){
    _fechaDePago=fechaDePago;
    }
    void Pago:: setFechaDeVencimientoActualizado(Fecha fechaDeVencActualizado){
    _fechaDeVencActualizado=fechaDeVencActualizado;
    }
    void Pago:: setCuota(float cuota){
    _cuota=cuota;
    }

    int Pago:: getIdSocio(){
    return _idSocio;
    }
    Fecha Pago:: getFechaActual(){
    return _fechaActual;
    }
    Fecha Pago:: getFechaDePago(){
    return _fechaDePago;
    }
    Fecha Pago:: getFechaDeVencimientoActualizado(){
    return _fechaDeVencActualizado;
    }
    float Pago:: getCuota(){
    return _cuota;
    }


///metodos:
    bool Pago:: Cargar(){
    }
    void Pago:: Mostrar(){
    }
