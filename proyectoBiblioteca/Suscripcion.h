#pragma once
#include "Fecha1.h"

class Suscripcion{
private:
    int _idSocio;
    Fecha _fechaDeSuscripcion;
    bool _tipoDeSuscripcion;
    Fecha _fechaDeVencimiento;


public:
    ///getters y setters:
    bool setIdSocio (int idSocio);
    void setFechaDeSuscripcion (Fecha fechaDeSuscripcion);
    int setTipoDeSuscripcion (int tipoDeSuscripcion);
    void setFechaDeVencimiento (Fecha fechaDeVencimiento);

    int getIdSocio ();
    Fecha getFechaDeSuscripcion ();
    bool getTipoDeSuscripcion ();
    Fecha getFechaDeVencimiento ();

    ///metodos:
    bool Cargar(int idSocio=0);
    void Mostrar();
};
