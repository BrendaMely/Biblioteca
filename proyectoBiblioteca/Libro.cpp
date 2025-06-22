#include "Libro.h"
#include "ArchivoLibros.h"

#include <iostream>
#include<cstring>

using namespace std;

///getters y setters:
    bool Libro:: setIsbn (int isbn){
    if(isbn>=9000000000000&& isbn<=9999999999999){
            _isbn=isbn;
            return true;
        }
        else{
            cout<<"Isbn debe contener 13 digitos"<<endl;
            return false; ///valor no valido
        }
    }


    void Libro:: setLibro (const char* libro){
    if(libro==nullptr || strlen(libro)==0){
            cout<<"Nombre de libro vacio"<<endl;
            _libro[0]='\0';
            return;
        }

        ///************validar longitud maxima
        if(strlen(libro)>=50){
            cout<<"Nombre de libro demasiado largo"<<endl;
            _libro[0]='\0';
            return;
        }
        ///si pasa todas las validaciones
        strcpy(_libro, libro);
    }


    bool Libro:: setIdAutor(int idAutor){
    if(idAutor>0){
            _idAutor=idAutor;
            return true;
        }
        else{
            cout<<"IdAutor tiene que ser un numero positivo"<<endl;
            _idAutor=-1;
            return false;
        }
    }


    void Libro:: setFechaDePublicacion(Fecha fechaDePublicacion){
    _fechaDePublicacion=fechaDePublicacion;
    }


    bool Libro:: setCantidadEjemplares(int cantidadEjemplares){
        if(cantidadEjemplares>0){
            _cantidadEjemplares=cantidadEjemplares;
            return true;
        }
        else{
            cout<<"La cantidad de ejemplares tiene que ser un numero positivo"<<endl;
            _cantidadEjemplares=-1;
            return false;
        }
    }


    int Libro:: getIsbn() {
    return _isbn;
    }
    char* Libro:: getLibro() {
    return _libro;
    }
    int Libro:: getIdAutor() {
    return _idAutor;
    }
    Fecha Libro:: getFechaDePublicacion() {
    return _fechaDePublicacion;
    }
    int Libro:: getCantidadEjemplares() {
    return _cantidadEjemplares;
    }



///metodos:
    bool Libro:: Cargar(int isbn){
        ArchivoLibros archiLibros;
        char ingresoDeDatosParaValidar[100];

        if(isbn==0){
            bool isbnValido=false;
            int isbnIngresado;

            while(!isbnValido){
                cout<<"Ingresar ISBN a buscar"<<endl;
                cin>>isbnIngresado;

                if(setIsbn(isbnIngresado)){
                    isbnValido=true;

                    if(archiLibros.buscarLibroXISBN(isbnIngresado)>=0){
                        cout<<"Ya existe un libro con ese isbn"<<endl;
                        return false;
                    }
                    ///si no esta e el archivo libros ya se asigna el isbn en _isbn a travez del setIsbn
                }
                else{
                    cout<<"Isbn invalido"<<endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
            }
        }

        ///
        else{
            if(setIsbn(isbn)){
                if(archiLibros.buscarLibroXISBN(isbn)>=0){
                    cout<<"Ya existe un libro registrado con ese isbn"<<endl;
                    return false;
                }
                ///si no esta e el archivo libros ya se asigna el isbn en _isbn a travez del setIsbn
            }
            else{
                return false; ///cuando es invalido el formato isbn en el set
            }
        }
        cin.ignore(1000, '\n');


        _libro[0]='\0';
        while(_libro[0]=='\0'){
            cout<<"Ingrese el titulo del libro: ";
            cin.getline(ingresoDeDatosParaValidar, 100);
            setLibro(ingresoDeDatosParaValidar);
        }


        cout<<"Ingrese IdAutor: "<<endl;
        cin>>_idAutor;
        setIdAutor(_idAutor);
        cin.ignore(1000, '\n');

        while(_idAutor==-1){
            cout<<"Vuelve a ingresar el idAutor (numero positivo): "<<endl;
            cin>>_idAutor;
            setIdAutor(_idAutor);
            cin.ignore(1000, '\n');
        }

        Fecha fechaTemporalDePublicacion;
        bool fechaValida=false;

        while(!fechaValida){
            cout<<"Ingrese fecha de publicacion del libro: ";
            int dia, mes, anio;
            cout<<"Dia: ";
            cin>>dia;
            cout<<"Mes: ";
            cin>>mes;
            cout<<"Anio: ";
            cin>>anio;

            cin.ignore(1000, '\n');
            if(fechaTemporalDePublicacion.setDia(dia) && fechaTemporalDePublicacion.setMes(mes) && fechaTemporalDePublicacion.setAnio(anio)){
                _fechaDePublicacion=fechaTemporalDePublicacion;
                fechaValida=true;
            }
            else{
                cout<<"Ingrese nuevamente la fecha de publicacion del libro"<<endl;
            }
        }

        cout<<"Ingrese Cantidad de Ejemplares: "<<endl;
        cin>>_cantidadEjemplares;
        setIdAutor(_cantidadEjemplares);
        cin.ignore(1000, '\n');

        while(_cantidadEjemplares==-1){
            cout<<"Vuelve a ingresar la cantidad de ejemplares (numero positivo): "<<endl;
            cin>>_cantidadEjemplares;
            setCantidadEjemplares(_cantidadEjemplares);
            cin.ignore(1000, '\n');
        }


        return true;

    }








    void Libro:: Mostrar(){
    }
