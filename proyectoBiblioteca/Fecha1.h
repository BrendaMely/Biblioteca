#pragma once

class Fecha{
private:
    int _dia; ///ap
    int _mes;
    int _anio;

    bool  esBisiesto();
    int diasEnMes();

public:

    void setDia(int dia); ///par ext, suvaaa_d
    void setMes (int mes);
    void setAnio(int anio);

    int getDia();
    int getMes();
    int getAnio();

    Fecha();
    Fecha(int dia, int mes, int anio);

    void Cargar();
    void Mostrar();

};
