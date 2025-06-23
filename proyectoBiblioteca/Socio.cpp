#include "Socio.h"
#include "ArchivoSocios.h"

#include <iostream>
#include<cstring> ///funciones libreria estandar c/c++: strln, strncpy, strcmp
#include <cctype> ///funciones libreria: isdigit, isalpha, isalnum


using namespace std;

///getters y setters:

    ///Validacion DNI tamaño y digitos
    bool Socio:: setDni(const char* dni){
        int cantidadDigitos=strlen(dni);
        bool longitudValida=(cantidadDigitos>=7 && cantidadDigitos<=8);

        bool sonNumeros=true;

        for(int i=0; i<cantidadDigitos; i++){
            if(!isdigit(dni[i])){
                sonNumeros=false;
                break;
            }
        }

        if(longitudValida&&sonNumeros){
            strncpy(_dni, dni, 9);
            _dni[8]='\0';
            return true;
        }

        if(!longitudValida){
            cout<<"DNI debe tener 7 u 8 digitos"<<endl;
        }
        else{
            cout<<"DNI solo puede contener numeros"<<endl;
        }
        return false;
    }



    void Socio:: setNombre(const char* nombre){

        ///verifica si el puntero es nulo o longitud cadena es 0
        ///asigna cadena vacia a _nombre y sale de la funcion
        if(nombre==nullptr || strlen(nombre)==0){
            cout<<"Nombre vacio"<<endl;
            _nombre[0]='\0';
            return;
        }

        ///valida si son letras y espacio
        for(int i=0; nombre[i]!='\0'; i++){
            if(!isalpha(nombre[i]) && nombre[i]!=' '){
                cout<<"Caracter ingresado no valido"<<endl;
                _nombre[0]='\0';
                return;
            }
        }
        ///************validar longitud maxima
        if(strlen(nombre)>=30){
            cout<<"Nombre demasiado largo"<<endl;
            _nombre[0]='\0';
            return;
        }
        ///si pasa todas las validaciones
        strcpy(_nombre, nombre);
    }




    void Socio:: setApellido(const char* apellido){

        ///verifica si el puntero es nulo o longitud cadena es 0
        ///asigna cadena vacia a _nombre y sale de la funcion
        if(apellido==nullptr || strlen(apellido)==0){
            cout<<"Nombre vacio"<<endl;
            _apellido[0]='\0';
            return;
        }

        ///valida si son letras y espacio
        for(int i=0; apellido[i]!='\0'; i++){
            if(!isalpha(apellido[i]) && apellido[i]!=' '){
                cout<<"Caracter ingresado no valido"<<endl;
                _apellido[0]='\0';
                return;
            }
        }
        ///************validar longitud maxima
        if(strlen(apellido)>=30){
            cout<<"Apellido demasiado largo"<<endl;
            _apellido[0]='\0';
            return;
        }
        ///si pasa todas las validaciones
        strcpy(_apellido, apellido);
    }




    void Socio:: setTelefono(const char* telefono){
        ///validar puntero nulo o cadena vacia
        if(telefono==nullptr || strlen (telefono)==0){
            cout<<"Telefono vacio"<<endl;
            _telefono[0]='\0';
            return;
        }
        ///validar longitud exacta de 11 caracteres
        if(strlen(telefono) !=11){
            cout<<"El telefono debe tener 11 digitos"<<endl;
            _telefono[0]='\0';
            return;
        }
        ///validar que sean digitos numericos
        for(int i=0; telefono[i]!='\0'; i++){
            if(!isdigit(telefono[i])){
                cout<<"El telefono solo puede contener numeros"<<endl;
                _telefono[0]='\0';
               return;
            }
        }
        ///Si pasa las validaciones copia el valor
        strncpy(_telefono, telefono, 11);
        _telefono[11]='\0';
    }



    void Socio:: setDireccion(const char* direccion){
        if(direccion==nullptr || strlen(direccion)==0){
            cout<<"Direccion no puede estar vacia"<<endl;
            _direccion[0]='\0';
            return;
        }

        if(strlen(direccion)>49){
            cout<<"La direccion excede el maximo de caracteres"<<endl;
            _direccion[0]='\0';
            return;
        }

        for(int i=0; direccion[i]!='\0'; i++){
            ///isalnum verifica caracter alfanumerico
            if(!isalnum(direccion[i])&& direccion[i]!=' '){
                cout<<"Caracter invalido"<<endl;
                 _direccion[0]='\0';
                return;
            }
        }
        strncpy(_direccion, direccion, 49);
        _direccion[49]='\0';
    }



    void Socio:: setEmail(const char*email){

        if(email==nullptr || strlen (email)==0){
            cout<<"El email no puede estar vacio"<<endl;
            _email[0]='\0';
            return;
        }

        if(strlen(email)>49){
            cout<<"Email demasiado largo (max 49 caracteres)"<<endl;
            _email[0]='\0';
            return;
        }

        ///caracteres permitidos
        for(int i=0; email[i]!='\0'; i++){
            if(!isalnum(email[i])&&
                email[i] !=  '@' &&
                email[i] !=  '.' &&
                email[i] !=  '_' &&
                email[i] !=  '+' &&
                email[i] !=  '-' ){
                cout<<"Caracter no valido"<<endl;
                _email[0]='\0';
                return;
                }
        }

        int contadorArroba=0;
        for(int i=0; email[i] !='\0'; i++){
            if(email[i]=='@'){
                contadorArroba++;
            }
        }
        if(contadorArroba!=1){
            cout<<"El email debe contener exactamente un @"<<endl;
            _email[0]='\0';
            return;
        }

        strncpy(_email, email, 49);
        _email[49]='\0';
    }


    void Socio:: setFechaDeNacimiento(Fecha fechaDeNacimiento){
        _fechaDeNacimiento= fechaDeNacimiento;
    }

///Es un identificador numérico  que se usa para búsquedas
///y relaciones en la base de datos

    void Socio:: setIdSocio(int idSocio){
        if(idSocio>=10000000 && idSocio<=99999999){
            _idSocio=idSocio;
        }
        else{
            cout<<"IdSocio debe contener 8 digitos"<<endl;
            _idSocio=-1; ///valor no valido
        }
    }

    void Socio::setEstado(bool estado){
        _estado = estado;
    }

    char* Socio:: getDni(){
        return _dni;
    }
    char* Socio:: getNombre(){
        return _nombre;
    }
    char* Socio:: getApellido(){
        return _apellido;
    }
    char* Socio:: getTelefono(){
        return _telefono;
    }
    char* Socio:: getDireccion(){
        return _direccion;
    }
    char* Socio:: getEmail(){
        return _email;
    }
    Fecha Socio:: getFechaDeNacimiento(){
        return _fechaDeNacimiento;
    }
    int Socio:: getIdSocio(){
        return _idSocio;
    }

    bool Socio:: getEstado(){return _estado;}


///metodos:

    bool Socio:: Cargar(const char* nuevoDni){
        ArchivoSocios archiSocio;
        char ingresoDeDatosParaValidar[100];

        ///

        if(strcmp(nuevoDni, "NADA")==0){

        char dniIngresado[9];
        bool dniValido=false;


            while(!dniValido){
                cout<<"Ingrese DNI (Formato Ej: 35470890, 9345678)"<<endl;
                cin>> dniIngresado;

                ///SI SE VALIDA  EL DNI INGRESADO. EN CASO DE SERLO LO ASIGNA A _dni
                if(setDni(dniIngresado)){
                    dniValido=true;

                    ///VALIDA SI YA EXISTE UN UN USUARIO CON ESE DNI

                    if(archiSocio.buscarSocioXDNI(dniIngresado)>=0){
                        cout<<"Ya existe un usuario con ese dni"<<endl;
                        return false;
                    }
                }
                ///SI EL DNI INGRESADO NO ES VALIDO EN EL SET
                else{
                    cout<<"DNI invalido. Debe tener 7 u 8 digitos numericos"<<endl;
                    cin.clear();
                    cin.ignore(1000, '\n');

                }
            }
        }


        ///

        else{

            if(setDni(nuevoDni)){
                if(archiSocio.buscarSocioXDNI(nuevoDni)>=0){
                    cout<<"Error: DNI ya existe en el sistema"<<endl;
                    return false;
                }
                ///Si no esta en el archivo de socio ya copio nuevoDni validado en _dni
            }
            else{
                ///CUANDO DIO INVALIDO EL FORMATO DEL NUEVO DNI EN EL SET
                return false;
            }
        }

        ///EN CASO DE SER VALIDO EL SETDNI POR INGRESO POR TECLADO O POR PARAMETRO
        ///SE CONTINUA CON EL INGRESO DEL RESTO DE LOS DATOS

        ///Limpia antes de un getline
        cin.ignore(1000, '\n');


        _nombre[0]='\0';
        while(_nombre[0]== '\0'){
           cout<<"Ingrese Nombre Completo: (Ej. Lucas Martin): ";
           ///cin.getline evita errores de salto de linea residuales
           ///evita el cin.ignore() despues de cada cin
            cin.getline(ingresoDeDatosParaValidar, 100);
            setNombre(ingresoDeDatosParaValidar);
        }


        _apellido[0]='\0';
        while(_apellido[0]=='\0'){
            cout<<"Ingrese Apellido Completo: ";
            cin.getline(ingresoDeDatosParaValidar, 100);
            setApellido(ingresoDeDatosParaValidar);
        }


        _telefono[0]='\0';
        while(_telefono[0]=='\0'){
            cout<<"Ingrese Telefono (Codigo de area sin 0 - Ej. 3511234567): ";
            cin.getline(ingresoDeDatosParaValidar, 100);
            setTelefono(ingresoDeDatosParaValidar);
        }


        _direccion[0]='\0';
        while(_direccion[0]=='\0'){
            cout<<"Ingrese Direccion (Calle y Numero): ";
            cin.getline(ingresoDeDatosParaValidar, 100);
            setDireccion(ingresoDeDatosParaValidar);
        }


        _email[0]='\0';
        while(_email[0]=='\0'){
            cout<<"Ingrese Email: ";
            cin.getline(ingresoDeDatosParaValidar, 100);
            setEmail(ingresoDeDatosParaValidar);
        }


        Fecha fechaTemporal;
        bool fechaValida=false;

        while(!fechaValida){
            cout<<"Ingrese Fecha de Nacimiento: "<<endl;
            int dia, mes, anio;
            cout<<"Dia: ";
            cin>>dia;
            cout<<"Mes: ";
            cin>>mes;
            cout<<"Anio: ";
            cin>>anio;

            cin.ignore(1000, '\n');

            if(fechaTemporal.setDia(dia) && fechaTemporal.setMes(mes)
            && fechaTemporal.setAnio(anio)){
                _fechaDeNacimiento=fechaTemporal;
                fechaValida=true;
            }
            else{
                cout<<"Ingrese nuevamente la fecha de nacimiento: "<<endl;
            }
        }


        cout<<"Ingrese ID Socio: ";
        cin>>_idSocio;
        setIdSocio(_idSocio);
        cin.ignore(1000, '\n');

        while(_idSocio==-1){
            cout<<"Vuelve a ingresar IdSocio (8 digitos): " <<endl;
            cin>>_idSocio;
            setIdSocio(_idSocio);
            cin.ignore(1000, '\n');
        }

        _estado = true;

        return true;

    }

    void Socio:: Mostrar(){
        cout<<"---- Datos del Socio ----"<<endl;
        cout<<"DNI       : "<<_dni<<endl;
        cout<<"Nombre    : "<<_nombre<<endl;
        cout<<"Apellido  : "<<_apellido<<endl;
        cout<<"Telefono  : "<<_telefono<<endl;
        cout<<"Direccion : "<<_direccion<<endl;
        cout<<"Email     : "<<_email<<endl;
        cout<<"Fecha Nac.: ";
        _fechaDeNacimiento.Mostrar();
        cout<<"ID Socio  : "<<_idSocio<<endl;
    }



