#pragma once
#include "Fecha1.h"

class Prestamo{
private:
    int _isbn;
    int _idSocio;
    Fecha _fechaPrestamo;
    Fecha _fechaDevolucion;
    bool _prestamoActivo;


public:
    ///getters y setters:

    bool setIsbn(int isbn);
    void setIdSocio(int idSocio);
    void setFechaPrestamo(Fecha fechaPrestamo);
    void setFechaDevolucion(Fecha fechaDevolucion);
    void setPrestamoActivo(bool prestamoActivo);

    int getIsbn();
    int getIdSocio();
    Fecha getFechaPrestamo();
    Fecha getFechaDevolucion();
    int getPrestamoActivo();

    ///metodos:
    bool CargarPrestamo();
    bool CargarDevolucion();
    void MostrarPrestamoActivos();
    void MostrarPrestamoInactivos();
};
