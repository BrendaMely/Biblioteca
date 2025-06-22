#pragma once
#include "Fecha1.h"

class Pago{
private:
    int _idSocio;
    Fecha _fechaActual;
    Fecha _fechaDePago;
    Fecha _fechaDeVencActualizado;
    float _cuota;


public:
    ///getters y setters:
    void setIdSocio(int idSocio);
    void setFechaActual(Fecha fechaActual);
    void setFechaDePago(Fecha fechaDePago);
    void setFechaDeVencimientoActualizado(Fecha fechaDeVencActualizado);
    void setCuota(float cuota);

    int getIdSocio();
    Fecha getFechaActual();
    Fecha getFechaDePago();
    Fecha getFechaDeVencimientoActualizado();
    float getCuota();

    ///metodos:
    bool Cargar();
    void Mostrar();
};

