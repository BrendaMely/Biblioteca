# include "ArchivoSocios.h"
# include "Socio.h"
# include<iostream>
# include<cstring>

using namespace std;

    ///BUSCAR SOCIO POR DNI - Retorna la posicion del registro o error
    int ArchivoSocios:: buscarSocioXDNI(const char* dniSocio){
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
