#include <iostream>
#include "funcionesMenuSocios.h"
#include <string>
#include <algorithm>

using namespace std;

void ordenar(int vec[], int tam){
    int i, j, posmin, aux;

    for(i=0; i<tam-1; i++){
        posmin = i;
        for(j=i+1; j<tam; j++){
            if(vec[j] < vec[posmin]){
                posmin = j;
            }
        }
        aux = vec[i];
        vec[i] = vec[posmin];
        vec[posmin] = aux;
    }
}

void agregarSocio(){
    ArchivoSocios archivoSocios;
    Socio reg;
    reg.Cargar();
    archivoSocios.agregarRegistro(reg);
}


bool bajaSocio(){
    ArchivoSocios archivo;
    Socio reg;
    int id;
    cin.ignore();
    cout<<"Ingrese ID a dar de baja: "<<endl;
    cin>>id;
    bool res = archivo.bajaRegistro(id);
    if(res){
        cout<<"El registro fue eliminado."<<endl;
    }else{
        cout<<"Hubo un error";
    }
}

void modificarTelefono(){
    ArchivoSocios archivo;
    Socio regSocio;
    int id;
    char numero[12];
    cin.ignore();
    cout<<"Ingrese ID para cambiar teléfono: ";
    cin>>id;
    cin.ignore();
    cout<<"Ingrese nuevo teléfono: ";
    cin>>numero;

    int pos = archivo.buscarID(id);
    regSocio = archivo.leer(pos);
    regSocio.setTelefono(numero);
    int res = archivo.modificarRegistro(regSocio, pos);
    if(res){
        cout<<"Se cambio el telefono correctamente."<<endl;
    }else{
        cout<<"Hubo un error."<<endl;
    }
}

void listarSocios(){
    ArchivoSocios archivo;
    Socio regSocio;

    int cantidadRegistros = archivo.getCantidadRegistros();
    if(cantidadRegistros != 0){
        for(int i=0; i<cantidadRegistros; i++){
            regSocio = archivo.leer(i);
            if(regSocio.getEstado()) regSocio.Mostrar();
            cout<<endl<<"-------------------------"<<endl;
        }
    }else{
        cout<<"No hay registros"<<endl;
    }
}

void listarSociosPorIdSocios(){
    ArchivoSocios archivo;
    Socio regSocio;

    int cantRegistros = archivo.getCantidadRegistros();
    int * vecIDs = new int[cantRegistros];
    if(vecIDs == nullptr){
        cout<<"Error de memoria!"<<endl;
        return;
    }

    for(int i=0; i<cantRegistros; i++){
        regSocio = archivo.leer(i);
        vecIDs[i] = regSocio.getIdSocio();
    }

    ordenar(vecIDs, cantRegistros);
    int pos;
    for(int i=0; i<cantRegistros; i++){

        pos = archivo.buscarID(vecIDs[i]);
        regSocio = archivo.leer(pos);
        if(regSocio.getEstado()) regSocio.Mostrar();

    }

    delete [] vecIDs;
}

void listarSociosPorApellido(){
    ArchivoSocios archivo;
    Socio regSocio;
    int cantRegistros = archivo.getCantidadRegistros();
    string * vecApellidos = new string[cantRegistros];

    if(vecApellidos == nullptr){
        cout<<"Error de memoria!"<<endl;
        return;
    }

    // Cargar apellidos
    for (int i = 0; i < cantRegistros; i++) {
        regSocio = archivo.leer(i);
        vecApellidos[i] = regSocio.getApellido();
    }

    // Ordenamiento burbuja (ascendente A-Z)
    for(int i = 0; i<cantRegistros-1; i++) {
        for(int j = 0; j < cantRegistros - i - 1; j++) {
            if (vecApellidos[j] > vecApellidos[j + 1]) {
                std::swap(vecApellidos[j], vecApellidos[j + 1]);
            }
        }
    }

    // Mostrar apellidos ordenados
    cout << "Listado de apellidos ordenados:" << endl;
    for (int i = 0; i < cantRegistros; i++) {
        cout << vecApellidos[i] << endl;
    }

    // Liberar memoria
    delete[] vecApellidos;
}


void buscarSocioPorDNI(){
    ArchivoSocios archivo;
    Socio regSocio;
    char dni[9];
    cin.ignore();
    cout<<"Ingrese DNI a buscar: ";
    cin>>dni;

    int pos = archivo.buscarSocioXDNI(dni);
    if(pos==-1){
        cout<<"No hay registros"<<endl;

    }else{
        cout<<"-------------------------"<<endl;
        regSocio = archivo.leer(pos);
        if(regSocio.getEstado() == true){
            regSocio.Mostrar();
        }
        cout<<"-------------------------"<<endl;
    }
}
void buscarSocioPorIdSocio(){
    ArchivoSocios archivo;
    Socio regSocio;
    int id;
    cin.ignore();
    cout<<"Ingrese ID a buscar: ";
    cin>>id;

    int res = archivo.buscarID(id);
    if(res==-1){
        cout<<"No se pudo encontrar el ID";
    }else{
        regSocio = archivo.leer(res);
        regSocio.Mostrar();
    }
}
