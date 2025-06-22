#pragma once

class Autor{
private:
    int _idAutor;
    char _nombreAutor[30];
    char _apellidoAutor[30];


public:
    ///getters y setters:
    bool setIdAutor(int idAutor);
    void setNombreAutor(const char* nombreAutor);
    void setApellidoAutor(const char* apellidoAutor);

    int getIdAutor();
    char* getNombreAutor();
    char* getApellidoAutor();

    ///metodos:
    bool Cargar(int idAutor=0);
    void Mostrar();

};
