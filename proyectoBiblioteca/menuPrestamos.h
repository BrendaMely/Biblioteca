#include<iostream>
#include "funcionesMenuPrestamos.h"

using namespace std;

void menuPrestamos(){
    int opcion;

    while (true){
        system("cls");

        cout<<"--------------ABML PRESTAMOS--------------------"<<endl;
        cout<<"1 - REGISTRAR PRESTAMO"<<endl;
        cout<<"2 - REGISTRAR DEVOLUCION"<<endl;
        cout<<"3 - ACTUALIZAR CANTIDAD DE EJEMPLARES"<<endl;
        cout<<"4 - LISTAR PRESTAMOS REALIZADOS"<<endl;
        cout<<"5 - LISTAR PRESTAMOS POR FECHA DE PRESTAMO"<<endl;
        cout<<"6 - LISTAR PRESTAMOS POR FECHA DE DEVOLUCION"<<endl;
        cout<<"7 - LISTAR PRESTAMOS POR ID SOCIO"<<endl;
        cout<<"8 - BUSCAR PRESTAMO POR ID SOCIO"<<endl;
        cout<<"9 - BUSCAR PRESTAMO POR FECHA DE PRESTAMO"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"--------------------------------------------------"<<endl;
        cout<<"SELECCIONAR OPCION:"<<endl;
        cin>>opcion;

        system("cls");

        switch(opcion){
        case 1: agregarPrestamo();
        break;
        case 2: registrarDevolucion();
        break;
        case 3: actualizarCantidadDeEjemplares();
        break;
        case 4: listarPrestamosRealizados();
        break;
        case 5: listarPrestamosRealizadosPorFechaDePrestamo();
        break;
        case 6: listarPrestamosRealizadosPorFechaDeDevolucion();
        break;
        case 7: listarPrestamosRealizadosPorIdSocio();
        break;
         case 8: buscarPrestamoPorIdSocio();
        break;
        case 9: buscarPrestamoPorFechaDePrestamo();
        break;
        case 0: return;
        break;
        default: cout<<"LA SELECCION NO ES CORRECTA"<<endl;
        }
        system("pause");
    }
    return;

}

