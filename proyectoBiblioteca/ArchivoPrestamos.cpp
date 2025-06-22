# include "ArchivoPrestamos.h"
# include "Prestamo.h"
# include<iostream>
# include<cstring>

using namespace std;

    int ArchivoPrestamos::buscarPrestamoXIdSocio(int idSocio){
    Prestamo obj;

    FILE *pPrestamo;
    pPrestamo=fopen(_nombreArchivo, "rb");

    if(pPrestamo==nullptr){///error de archivo
        return -2; ///archivo no abierto
    }

    int pos=0;

    while(fread(&obj, _tamanioRegistro, 1, pPrestamo)==1){
        if(obj.getIdSocio() == idSocio){
            return pos;
        }
        pos++; ///el registro de ese prestamo con ese idSocio se encuentra en la posicion
    }

    fclose(pPrestamo);
    return -1;

    }
