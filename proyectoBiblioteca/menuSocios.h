#include<iostream>
#include "funcionesMenuSocios.h"

using namespace std;

void menuSocios(){
    int opcion;

    while (true){
        system("cls");

        cout<<"--------------ABML SOCIOS--------------------"<<endl;
        cout<<"1 - ALTA DE SOCIO"<<endl;
        cout<<"2 - BAJA DE SOCIO"<<endl;
        cout<<"3 - MODIFICAR TELEFONO"<<endl;
        cout<<"4 - LISTAR SOCIOS"<<endl;
        cout<<"5 - LISTAR SOCIOS POR ID SOCIOS"<<endl;
        cout<<"6 - LISTAR SOCIOS POR APELLIDO"<<endl;
        cout<<"7 - BUSCAR SOCIO POR DNI"<<endl;
        cout<<"8 - BUSCAR SOCIO POR ID SOCIO"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"--------------------------------------------------"<<endl;
        cout<<"SELECCIONAR OPCION:"<<endl;
        cin>>opcion;

        system("cls");

        switch(opcion){
        case 1: agregarSocio();
        break;
        case 2: bajaSocio();
        break;
        case 3: modificarTelefono();
        break;
        case 4: listarSocios();
        break;
        case 5: listarSociosPorIdSocios();
        break;
        case 6: listarSociosPorApellido();
        break;
        case 7: buscarSocioPorDNI();
        break;
        case 8: buscarSocioPorIdSocio();
        break;
        case 0: return;
        break;
        default: cout<<"LA SELECCION NO ES CORRECTA"<<endl;
        }
        system("pause");
    }
    return;

}

