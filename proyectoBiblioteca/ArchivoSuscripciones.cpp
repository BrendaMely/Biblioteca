# include "ArchivoSuscripciones.h"
# include "Suscripcion.h"
#include"Socio.h"
# include<iostream>
# include<cstring>

using namespace std;

    int ArchivoSuscripciones::buscarSuscriptorXIdSocio(int idSocio){
    Suscripcion obj;

    FILE *pSuscripcion;
    pSuscripcion=fopen(_nombreArchivo, "rb");

    if(pSuscripcion==nullptr){///error de archivo
        return -2; ///archivo no abierto
    }

    int pos=0;

    while(fread(&obj, _tamanioRegistro, 1, pSuscripcion)==1){
        if(obj.getIdSocio() == idSocio){
            return pos;
        }
        pos++; ///el registro de esa suscripcion con ese idSocio se encuentra en la posicion
    }

    fclose(pSuscripcion);
    return -1;

    }
