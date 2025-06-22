#include "Suscripcion.h"
#include "Socio.h"
#include "ArchivoSuscripciones.h"

#include <iostream>
#include<cstring>

using namespace std;

///getters y setters:
    bool Suscripcion:: setIdSocio (int idSocio){
    if(idSocio>=10000000 && idSocio<=99999999){
            _idSocio=idSocio;
            return true;
        }
        else{
            cout<<"IdSocio debe contener 8 digitos"<<endl;
            return false; ///valor no valido
        }
    }
    void Suscripcion:: setFechaDeSuscripcion (Fecha fechaDeSuscripcion){
    _fechaDeSuscripcion=fechaDeSuscripcion;
    }

    int Suscripcion:: setTipoDeSuscripcion (int tipoDeSuscripcion){
        if(tipoDeSuscripcion==0 || tipoDeSuscripcion==1){
            _tipoDeSuscripcion=tipoDeSuscripcion;
            return true;
        }
        else{
            cout<<"Tipo de suscripcion invalida (Ingrese 0 para suscripcion mensual y 1 para suscripcion anual"<<endl;
            return false;
        }

    }

    void Suscripcion:: setFechaDeVencimiento (Fecha fechaDeVencimiento){
    _fechaDeVencimiento=fechaDeVencimiento;
    }


    int Suscripcion:: getIdSocio (){
    return _idSocio;
    }
    Fecha Suscripcion:: getFechaDeSuscripcion (){
    return _fechaDeSuscripcion;
    }
    bool Suscripcion:: getTipoDeSuscripcion (){
    return _tipoDeSuscripcion;
    }
    Fecha Suscripcion:: getFechaDeVencimiento (){
    return _fechaDeVencimiento;
    }


///metodos:

    bool Suscripcion:: Cargar(int idSocio){
        ArchivoSuscripciones archiSuscripciones;

        if(idSocio==0){
            bool idValido=false;
            int idIngresado;

            while(!idValido){
                cout<<"Ingrese idSocio a buscar"<<endl;
                cin>>idIngresado;

                if(setIdSocio(idIngresado)){
                    idValido=true;

                    if(archiSuscripciones.buscarSuscriptorXIdSocio(idIngresado)>=0){
                        cout<<"Ya existe una suscripcion con ese numero de idSocio"<<endl;
                        return false;
                    }
                }
                else{
                    cout<<"IdSocio invalido"<<endl;
                    cin.clear();
                        cin.ignore(1000, '\n');
                }
            }
        }
        ///
        else{
            if(setIdSocio(idSocio)){
                if(archiSuscripciones.buscarSuscriptorXIdSocio(idSocio)>=0){
                        cout<<"Ya existe una suscripcion con ese numero de idSocio"<<endl;
                        return false;
                    }
                    ///si no esta en archivo suscripciones ya se copi el idSocio validado en _idSocio
            }
            else{
                return false; ///cuando dio invalido el formato idSocio en el set
            }
        }
        cin.ignore(1000, '\n');

        Fecha fechaTemporalSuscripcion;
        bool fechaValida=false;

        while(!fechaValida){
            cout<<"Ingrese Fecha de Nacimiento: ";
            int dia, mes, anio;
            cout<<"Dia: ";
            cin>>dia;
            cout<<"Mes: ";
            cin>>mes;
            cout<<"Anio: ";
            cin>>anio;

            cin.ignore(1000, '\n');

            if(fechaTemporalSuscripcion.setDia(dia) && fechaTemporalSuscripcion.setMes(mes)
            && fechaTemporalSuscripcion.setAnio(anio)){
                _fechaDeSuscripcion=fechaTemporalSuscripcion;
                fechaValida=true;
            }
            else{
                cout<<"Ingrese nuevamente la fecha de suscripcion "<<endl;
            }
        }

        int tipoSuscripcionIngresado;
        bool esValido=false;

        cout<<"Ingrese tipo de suscripcion: (0 si es mensual y 1 si es anual)"<<endl;
        cin>>tipoSuscripcionIngresado;
        esValido=setTipoDeSuscripcion(tipoSuscripcionIngresado);
        cin.ignore(1000, '\n');

        while(!esValido){
            cout<<"Error: Ingrese tipo de suscripcion: (0 si es mensual y 1 si es anual): "<<endl;
            cin>>tipoSuscripcionIngresado;
            esValido=setTipoDeSuscripcion(tipoSuscripcionIngresado);
            cin.ignore(1000, '\n');
        }




        Fecha fechaTemporalVencimiento;
        int diaVencimiento=0, mesVencimiento=0, anioVencimiento=0;

        if(getTipoDeSuscripcion()==0){
            diaVencimiento=fechaTemporalSuscripcion.getDia();
            mesVencimiento=fechaTemporalSuscripcion.getMes();
            anioVencimiento=fechaTemporalSuscripcion.getAnio();

            if(mesVencimiento<12){
                mesVencimiento++;
            }
            if(mesVencimiento==12){
                mesVencimiento=1;
                anioVencimiento++;
            }
            fechaTemporalVencimiento= Fecha(diaVencimiento, mesVencimiento, anioVencimiento);
            _fechaDeVencimiento=fechaTemporalVencimiento;
            cout<<"La fecha de vencimiento de suscripcion es: "<<endl;
            _fechaDeVencimiento.Mostrar();
        }
        else{
            if(getTipoDeSuscripcion()==1){
                diaVencimiento=fechaTemporalSuscripcion.getDia();
                mesVencimiento=fechaTemporalSuscripcion.getMes();
                anioVencimiento=fechaTemporalSuscripcion.getAnio();
                anioVencimiento++;

                fechaTemporalVencimiento= Fecha(diaVencimiento, mesVencimiento, anioVencimiento);
                _fechaDeVencimiento=fechaTemporalVencimiento;
               cout<<"La fecha de vencimiento de suscripcion es: "<<endl;
               _fechaDeVencimiento.Mostrar();
            }

        }
    return true;
    }


    void Suscripcion:: Mostrar(){
        cout<<"Datos de la suscripcion: "<<endl;
        cout<<"IdSocio:"<< _idSocio<<endl;
        cout<<"Fecha de Suscripcion:"<<endl;
        _fechaDeSuscripcion.Mostrar();
        cout<<"Tipo de Suscripcion: (0 Mensual - 1 Anual"<< _tipoDeSuscripcion<<endl;
        cout<<"Fecha de Vencimiento de Suscripcion:"<<endl;
        _fechaDeVencimiento.Mostrar();
    }
