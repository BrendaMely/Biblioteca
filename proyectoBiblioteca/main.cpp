#include <iostream>
#include <cstring>
#include "menuSocios.h"
#include "menuLibros.h"
#include "menuPrestamos.h"
#include "menuPagos.h"
#include "menuInformes.h"
#include "Fecha1.h"

using namespace std;

int main(){
    int opcion;
    ///Fecha f;
    ///f.Cargar();
    ///f.Mostrar();


    while (true){
        system("cls");

        cout<<"--------------BIENVENIDO--------------------"<<endl;
        cout<<"1 - GESTION DE SOCIOS"<<endl;
        cout<<"2 - GESTION DE LIBROS"<<endl;
        cout<<"3 - GESTION DE PRESTAMOS"<<endl;
        cout<<"4 - GESTION DE PAGOS"<<endl;
        cout<<"5 - INFORMES"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"--------------------------------------------------"<<endl;
        cout<<"SELECCIONAR OPCION:"<<endl;
        cin>>opcion;

        system("cls");

        switch(opcion){
        case 1: menuSocios();
        break;
        case 2: menuLibros();
        break;
        case 3: menuPrestamos();
        break;
        case 4: menuPagos();
        break;
       case 5: menuInformes();
        break;
        case 0: return 0;
        break;
        default: cout<<"LA SELECCION NO ES CORRECTA"<<endl;
        }
        system("pause");
    }
    return 0;
}
