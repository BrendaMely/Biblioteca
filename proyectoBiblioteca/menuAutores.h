#include<iostream>
#include "funcionesMenuAutores.h"

using namespace std;

void menuAutores(){
    int opcion;

    while (true){
        system("cls");

        cout<<"--------------ABML SOCIOS--------------------"<<endl;
        cout<<"1 - ALTA DE AUTOR"<<endl;
        cout<<"2 - BAJA DE AUTOR"<<endl;
        cout<<"3 - LISTAR AUTORES"<<endl;
        cout<<"4 - LISTAR AUTORES POR ID AUTOR"<<endl;
        cout<<"5 - BUSCAR AUTOR POR ID AUTOR"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"--------------------------------------------------"<<endl;
        cout<<"SELECCIONAR OPCION:"<<endl;
        cin>>opcion;

        system("cls");

        switch(opcion){
        case 1: agregarAutor();
        break;
        case 2: bajaAutor();
        break;
        case 3: listarAutores();
        break;
        case 4: listarAutoresPorIdAutor();
        break;
        case 5: buscarAutorPorIdAutor();
        break;
        case 0: return;
        break;
        default: cout<<"LA SELECCION NO ES CORRECTA"<<endl;
        }
        system("pause");
    }
    return;

}
