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


    bool Fecha:: setDia(int dia){
        if(dia>=1 && dia<=diasEnMes()){
            _dia=dia;
            return true;
        }
        else{
            return false;
        }
}

    bool Fecha:: setMes (int mes){
        if(mes>=1 && mes<=12){
            _mes=mes;
            return true;
        }
        else{
            return false;
        }
}


    bool Fecha:: setAnio(int anio){
        if(anio<=1 && anio<=9999){
          _anio=anio;
          return true;
        }
        else {
            return false;
        }
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

        bool anioValido=setAnio(anio);
        bool mesValido=setMes(mes);
        bool diaValido=setDia(dia);

        if(anioValido&&mesValido&&diaValido){
            fechaValida=true;
            }
            else{
                cout<<"Fecha incorrecta"<<endl;
                if(!anioValido){
                    cout<<"Anio invalido"<<endl;
                }
                if(!mesValido){
                    cout<<"Mes invalido"<<endl;
                }
                if(!diaValido){
                    cout<<"Dia invalido"<<endl;
                }
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }

}

    void Fecha:: Mostrar() const{
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
