#include<iostream>
#include "funcionesMenuSuscriptores.h"

using namespace std;

void menuSuscripciones(){
    int opcion;

    while (true){
        system("cls");

        cout<<"--------------ABML SOCIOS--------------------"<<endl;
        cout<<"1 - ALTA DE SUSCRIPTOR"<<endl;
        cout<<"2 - BAJA DE SUSCRIPTOR"<<endl;
        cout<<"3 - LISTAR SUSCRIPTORES"<<endl;
        cout<<"4 - LISTAR SUSCRIPTORES POR ID SOCIO"<<endl;
        cout<<"5 - BUSCAR SUSCRIPTOR POR ID SOCIO"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"--------------------------------------------------"<<endl;
        cout<<"SELECCIONAR OPCION:"<<endl;
        cin>>opcion;

        system("cls");

        switch(opcion){
        case 1: agregarSuscriptor();
        break;
        case 2: bajaSuscriptor();
        break;
        case 3: listarSuscriptores();
        break;
        case 4: listarSuscriptoresPorIdSocio();
        break;
        case 5: buscarSuscriptorPorIdSocio();
        break;
        case 0: return;
        break;
        default: cout<<"LA SELECCION NO ES CORRECTA"<<endl;
        }
        system("pause");
    }
    return;

}
