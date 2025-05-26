#include<iostream>
#include "funcionesMenuPagos.h"

using namespace std;

void menuPagos(){
    int opcion;

    while (true){
        system("cls");

        cout<<"--------------ABML PAGOS--------------------"<<endl;
        cout<<"1 - REGISTRAR PAGO"<<endl;
        cout<<"2 - LISTAR PAGOS RECIBIDOS"<<endl;
        cout<<"3 - LISTAR PAGOS ORDENADOS POR ID SOCIO"<<endl;
        cout<<"4 - LISTAR PAGOS ORDENADOS POR FECHA DE PAGO"<<endl;
        cout<<"5 - BUSCAR PAGOS POR ID SOCIO"<<endl;
        cout<<"6 - BUSCAR PAGOS POR FECHA DE PAGO"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"--------------------------------------------------"<<endl;
        cout<<"SELECCIONAR OPCION:"<<endl;
        cin>>opcion;

        system("cls");

        switch(opcion){
        case 1: agregarPago();
        break;
        case 2: listarPagosRecibidos();
        break;
        case 3: listarPagosRecibidosPorIdSocio();
        break;
        case 4: listarPagosRecibidosPorFechaDePago();
        break;
        case 5: buscarPagosRecibidosPorIdSocio();
        break;
        case 6: buscarPagosRecibidosPorFechaDePago();
        break;
        case 0: return;
        break;
        default: cout<<"LA SELECCION NO ES CORRECTA"<<endl;
        }
        system("pause");
    }
    return;

}
