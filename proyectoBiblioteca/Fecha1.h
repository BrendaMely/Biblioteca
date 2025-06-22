#pragma once

class Fecha{
private:
    int _dia; ///ap
    int _mes;
    int _anio;

    bool  esBisiesto();
    int diasEnMes();

public:

    bool setDia(int dia); ///par ext, suvaaa_d
    bool setMes (int mes);
    bool setAnio(int anio);

    int getDia();
    int getMes();
    int getAnio();

    Fecha();
    Fecha(int dia, int mes, int anio);

    void Cargar();
    void Mostrar() const;

};
