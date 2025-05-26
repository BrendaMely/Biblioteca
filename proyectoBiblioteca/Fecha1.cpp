#include <iostream>
#include "Fecha1.h"
using namespace std;

      Fecha:: Fecha (){
        _dia=1;
        _mes=1;
        _anio=2000;

        }
        Fecha::Fecha(int dia, int mes, int anio){
        setDia(dia);
        setMes(mes);
        setAnio(anio);
        }



    bool  Fecha:: esBisiesto(){
        if(_anio%4==0){
            if(_anio%100 !=0 || (_anio %100 == 0 && _anio%400==0)){
                return true;
            }
        }
        return false;
}
///Retorna los dias del mes
    int Fecha:: diasEnMes(){
        if(_mes==2){
            if(esBisiesto()){
                return 29;
            }
            else{
                return 28;
            }
        }

        if(_mes==4 || _mes==6 || _mes==9 || _mes==11){
            return 30;
        }
        else{
            return 31;
        }

}


    void Fecha:: setDia(int dia){
    _dia=dia;
}

    void Fecha:: setMes (int mes){
    _mes=mes;

}
    void Fecha:: setAnio(int anio){
    _anio=anio;
}

    void Fecha:: Cargar(){
        int dia, mes, anio;
        bool  fechaValida= false;

        while(!fechaValida){
        cout<<"DIA:";
        cin>>dia;
        cout<<"MES:";
        cin>>mes;
        cout<<"ANIO:";
        cin>>anio;

        bool anioValido=(anio>0&&anio<=9999);
        bool mesValido=(mes>=1&&mes<=12);
        bool diaValido=false;

        if(anioValido&&mesValido){
            int maxDias=diasEnMes();
            diaValido=(dia>=1 && dia<=maxDias);
        }

        if (anioValido&&mesValido&&diaValido){
            setAnio(anio);
            setMes(mes);
            setDia(dia);
            fechaValida=true;
        }

        else{
                cout<<"Error al ingresar fecha"<<endl;
                if(!anioValido){
                    cout<<"Anio invalido (Ingresar entre 1 - 9999)"<<endl;
                }
                if(!mesValido){
                    cout<<"Mes invalido (Ingresar entre 1 - 12)"<<endl;
                }
                if(!diaValido){
                    cout<<"Dia invalido (para mes "<<_mes<<" ingresar dias entre 1 y "<<diasEnMes()<<")"<<endl;
                }

                cin.clear();
                cin.ignore(1000, '\n');
        }

        }

}

    void Fecha:: Mostrar(){
        cout<<_dia<<"/"<<_mes<<"/"<<_anio<<endl;

}

    int Fecha:: getDia(){
        return _dia;

}
    int Fecha:: getMes(){
        return _mes;

}
    int Fecha:: getAnio(){
        return _anio;

}
