#include<iostream>
#include "funcionesMenuLibros.h"

using namespace std;

void menuLibros(){
    int opcion;

    while (true){
        system("cls");

        cout<<"--------------ABML LIBROS--------------------"<<endl;
        cout<<"1 - ALTA DE LIBRO"<<endl;
        cout<<"2 - BAJA DE LIBRO"<<endl;
        cout<<"3 - MODIFICAR CANTIDAD DE EJEMPLARES"<<endl;
        cout<<"4 - LISTAR LIBROS"<<endl;
        cout<<"5 - LISTAR LIBROS POR ISBN"<<endl;
        cout<<"6 - LISTAR LIBROS POR TITULO"<<endl;
        cout<<"7 - LISTAR LIBROS POR FECHA DE PUBLICACION"<<endl;
        cout<<"8 - LISTAR LIBROS POR APELLIDO DEL AUTOR"<<endl;
        cout<<"9 - LISTAR LIBROS POR DISPONIBILIDAD"<<endl;

        cout<<"11 - BUSCAR LIBRO POR AUTOR"<<endl;
        cout<<"12 - BUSCAR LIBRO POR DISPONIBILIDAD"<<endl;
        cout<<"13 - BUSCAR LIBRO POR FECHA DE PUBLICACION"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"--------------------------------------------------"<<endl;
        cout<<"SELECCIONAR OPCION:"<<endl;
        cin>>opcion;

        system("cls");

        switch(opcion){
        case 1: agregarLibro();
        break;
        case 2: bajaLibro();
        break;
        case 3: modificarCantidadDeEjemplares();
        break;
        case 4: listarLibros();
        break;
        case 5: listarLibrosPorISBN();
        break;
        case 6: listarLibrosPorTitulo();
        break;
        case 7: listarLibrosPorFechaDePublicacion();
        break;
        case 8: listarLibrosPorApellidoDelAutor();
        break;
        case 9: listarLibrosPorDisponibilidad();
        break;
        case 10: buscarLibroPorISBN();
        break;
        case 11: buscarLibroPorAutor();
        break;
        case 12: buscarLibroPorDisponibilidad();
        break;
        case 13: buscarLibroPorFechaDePublicacion();
        break;
        case 0: return;
        break;
        default: cout<<"LA SELECCION NO ES CORRECTA"<<endl;
        }
        system("pause");
    }
    return;

}
