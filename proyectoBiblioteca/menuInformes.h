#include<iostream>
#include "funcionesMenuInformes.h"

using namespace std;

void menuInformes(){
    int opcion;

    while (true){
        system("cls");

        cout<<"--------------ABML INFORMES--------------------"<<endl;
        cout<<"1 - LISTADO DE PRESTAMOS ACTIVOS ORDENADOS POR FECHA DE DEVOLUCION MAS CERCANA"<<endl;
        cout<<"2 - LISTADO DE PRESTAMOS VENCIDOS ORDENADOS POR FECHA DE VENCIMIENTO MÁS RECIENTE"<<endl;
        cout<<"3 - HISTORIAL DE PAGOS POR ID SOCIO"<<endl;
        cout<<"4 - LISTADO DE LIBROS MAS POPULARES"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"--------------------------------------------------"<<endl;
        cout<<"SELECCIONAR OPCION:"<<endl;
        cin>>opcion;

        system("cls");

        switch(opcion){
        case 1: prestamosActivos();
        break;
        case 2: prestamosVencidos();
        break;
        case 3: historialDePagosPorIdSocio();
        break;
        case 4: listadoLibrosMasPopulares();
        break;
        case 0: return;
        break;
        default: cout<<"LA SELECCION NO ES CORRECTA"<<endl;
        }
        system("pause");
    }
    return;

}
