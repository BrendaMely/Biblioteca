# include "ArchivoSocios.h"
# include<iostream>
# include<string>
# include<cstring>

using namespace std;

    ///BUSCAR SOCIO POR DNI - Retorna la posicion del registro o error
    int ArchivoSocios::buscarSocioXDNI(const char* dniSocio){
    Socio obj;///obj temp almacena datos leidos del archivo
    FILE *pSocio;
    pSocio= fopen(_nombreArchivo, "rb"); ///Abre el archivo como lectura desde el byte 0. No admite escritura.

    if(pSocio==nullptr){///error de archivo
        return -2;///archivo no abierto
    }

    int pos=0;///posicion del registro

    ///lee del inicio del archivo apuntado por pSocio, una cantidad de _tamanioRegistro
    ///y los almacena en el registro obj de tipo Socio, donde se va a guardar la informacion proveniente del archivo
    ///,1, cantidad de registros a leer a la vez, uno por vez
    ///pSocio puntero FILE apunta a un archivo en disco
    ///el ciclo continua mientras se lean registros exitosamente (retorna 1)

    while(fread(&obj, _tamanioRegistro, 1, pSocio)==1){
        if(strcmp(obj.getDni(), dniSocio)==0){
            return pos;
        }
        pos++; ///El registro del Socio con ese DNI se encuentra en la posicion
    }

    fclose(pSocio);
    return -1;
    }

    bool ArchivoSocios::agregarRegistro(Socio regSocio){
        FILE *pFile;
        bool res;

        pFile = fopen(_nombreArchivo, "ab");
        if(pFile == nullptr){
            cout<<"No se pudo abrir 'ArchivoSocios'"<<endl;
            return false;
        }

        res = fwrite(&regSocio, sizeof(regSocio), 1, pFile);

        fclose(pFile);

        return res;
    }

    int ArchivoSocios::getCantidadRegistros(){
        int total, cantidad;

        FILE* pFile;
        pFile = fopen(_nombreArchivo, "rb");

        if(pFile == nullptr){
            return 0;
        }

        fseek(pFile, 0, SEEK_END);

        total = ftell(pFile);

        cantidad = total / sizeof(Socio);

        fclose(pFile);

        return cantidad;
    }

    Socio ArchivoSocios::leer(int pos){
        FILE *pFile;
        Socio reg;

        pFile = fopen(_nombreArchivo, "rb");

        if(pFile == nullptr){
            return reg;
        }

        fseek(pFile, sizeof(Socio) * pos, SEEK_SET);

        fread(&reg, sizeof(Socio), 1, pFile);

        fclose(pFile);

        return reg;
    }

    int ArchivoSocios::buscarID(int id){
        Socio obj;
        FILE * pFile;
        pFile = fopen(_nombreArchivo, "rb");
        if(pFile==nullptr){
            cout<<"Error de Archivo"<<endl;
            return -2;
        }

        int pos=0;
        while(fread(&obj, sizeof(Socio), 1, pFile)==1){
            if(obj.getIdSocio()==id){
                return pos;
            }
            pos++;
        }

        fclose(pFile);
        return -1;
    }

     /*int ArchivoSocios::buscarDNI(char dni[9]){
        Socio obj;
        FILE * pFile;
        pFile = fopen(_nombreArchivo, "rb");
        if(pFile==nullptr){
            cout<<"Error de Archivo"<<endl;
            return -2;
        }

        int pos=0;
        while(fread(&obj, sizeof(Socio), 1, pFile)==1){
            if(obj.getDni()==dni){
                return pos;
            }
            pos++;
        }
        fclose(pFile);
        return -1;
    }*/

    bool ArchivoSocios::modificarRegistro(Socio reg, int pos){
        FILE * pFile;
        pFile = fopen(_nombreArchivo, "rb+");
        if(pFile == nullptr){
            cout<<"No se pudo abrir el archivo."<<endl;
            return false;
        }
        fseek(pFile, sizeof(Socio) * pos, 0);
        bool escrbio = fwrite(&reg, sizeof(Socio), 1, pFile);
        fclose(pFile);
        return escrbio;
    }

    bool ArchivoSocios::bajaRegistro(int id){
        ArchivoSocios archivo;
        Socio regSocio;
        int pos = archivo.buscarID(id);
        if(pos == -1) return false;
        regSocio = archivo.leer(pos);
        regSocio.setEstado(false);
        return archivo.modificarRegistro(regSocio, pos);
    }
