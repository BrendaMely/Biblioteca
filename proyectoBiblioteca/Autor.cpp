#include "Autor.h"
#include "ArchivoAutores.h"
#include <iostream>
#include<cstring>

using namespace std;

///getters y setters:
    bool Autor:: setIdAutor(int idAutor){
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
    void Autor:: setNombreAutor(const char* nombreAutor){
            ///verifica si el puntero es nulo o longitud cadena es 0
        ///asigna cadena vacia a _nombre y sale de la funcion
        if(nombreAutor==nullptr || strlen(nombreAutor)==0){
            cout<<"Nombre vacio"<<endl;
            _nombreAutor[0]='\0';
            return;
        }

        ///valida si son letras y espacio
        for(int i=0; nombreAutor[i]!='\0'; i++){
            if(!isalpha(nombreAutor[i]) && nombreAutor[i]!=' '){
                cout<<"Caracter ingresado no valido"<<endl;
                _nombreAutor[0]='\0';
                return;
            }
        }
        ///************validar longitud maxima
        if(strlen(nombreAutor)>=30){
            cout<<"Nombre demasiado largo"<<endl;
            _nombreAutor[0]='\0';
            return;
        }
        ///si pasa todas las validaciones
        strcpy(_nombreAutor, nombreAutor);
    }


    void Autor:: setApellidoAutor(const char* apellidoAutor){
    ///verifica si el puntero es nulo o longitud cadena es 0
        ///asigna cadena vacia a _nombre y sale de la funcion
        if(apellidoAutor==nullptr || strlen(apellidoAutor)==0){
            cout<<"Nombre vacio"<<endl;
            _apellidoAutor[0]='\0';
            return;
        }

        ///valida si son letras y espacio
        for(int i=0; apellidoAutor[i]!='\0'; i++){
            if(!isalpha(apellidoAutor[i]) && apellidoAutor[i]!=' '){
                cout<<"Caracter ingresado no valido"<<endl;
                _apellidoAutor[0]='\0';
                return;
            }
        }
        ///************validar longitud maxima
        if(strlen(apellidoAutor)>=30){
            cout<<"Apellido demasiado largo"<<endl;
            _apellidoAutor[0]='\0';
            return;
        }
        ///si pasa todas las validaciones
        strcpy(_apellidoAutor, apellidoAutor);
    }

    int Autor:: getIdAutor(){
    return _idAutor;
    }
    char* Autor:: getNombreAutor(){
    return _nombreAutor;
    }
    char* Autor:: getApellidoAutor(){
    return _apellidoAutor;
    }


///metodos:
    bool Autor:: Cargar(int idAutor){
        ArchivoAutores archiAutores;
        char ingresoDeDatosParaValidar[100];

                if(idAutor==0){
            bool idValido=false;
            int idIngresado;

            while(!idValido){
                cout<<"Ingrese idAutor a buscar"<<endl;
                cin>>idIngresado;

                if(setIdAutor(idIngresado)){
                    idValido=true;

                    if(archiAutores.buscarAutorXIdAutor(idIngresado)>=0){
                        cout<<"Ya existe un autor con ese numero de idAutor"<<endl;
                        return false;
                    }
                }
                else{
                    cout<<"IdAutor invalido"<<endl;
                    cin.clear();
                        cin.ignore(1000, '\n');
                }
            }
        }
        ///
        else{
            if(setIdAutor(idAutor)){
                if(archiAutores.buscarAutorXIdAutor(idAutor)>=0){
                        cout<<"Ya existe un autor con ese numero de idAutor"<<endl;
                        return false;
                    }
                    ///si no esta en archivo autores ya se copio el idAutor validado en _idAutor
            }
            else{
                return false; ///cuando dio invalido el formato idAutor en el set
            }
        }
        cin.ignore(1000, '\n');


        cout<<"Ingrese Id Autor: (numero positivo)";
        cin>>_idAutor;
        setIdAutor(_idAutor);
        cin.ignore(1000, '\n');

        while(_idAutor==-1){
            cout<<"Vuelve a ingresar IdAutor (numero positivo):" <<endl;
            cin>>_idAutor;
            setIdAutor(_idAutor);
            cin.ignore(1000, '\n');
        }


        _nombreAutor[0]='\0';
        while(_nombreAutor[0]== '\0'){
           cout<<"Ingrese Nombre Completo del Autor: (Ej. Lucas Martin): ";
           ///cin.getline evita errores de salto de linea residuales
           ///evita el cin.ignore() despues de cada cin
            cin.getline(ingresoDeDatosParaValidar, 100);
            setNombreAutor(ingresoDeDatosParaValidar);
        }


        _apellidoAutor[0]='\0';
        while(_apellidoAutor[0]=='\0'){
            cout<<"Ingrese Apellido Completo del Autor: ";
            cin.getline(ingresoDeDatosParaValidar, 100);
            setApellidoAutor(ingresoDeDatosParaValidar);
        }

        return true;
    }
    void Autor:: Mostrar(){
        cout<<"Datos del Autor: "<<endl;
        cout<<"idAutor: "<<_idAutor<<endl;
        cout<<"Nombre Autor: "<<_nombreAutor<<endl;
        cout<<"Apellido Autor: "<<_apellidoAutor<<endl;

    }
