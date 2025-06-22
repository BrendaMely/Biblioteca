# include "ArchivoLibros.h"
# include "Libro.h"
#include "Autor.h"
# include<iostream>
# include<cstring>

using namespace std;

    int ArchivoLibros::buscarLibroXISBN(int isbn){
    Libro obj;

    FILE *pLibro;
    pLibro=fopen(_nombreArchivo, "rb");

    if(pLibro==nullptr){
        return -2;
    }

    int pos=0;

    while(fread(&obj, _tamanioRegistro, 1, pLibro)==1){
        if(obj.getIsbn()==isbn){
            return pos;
        }
        pos++; ///el registro de ese libro con ese isbn se encuentra en la posicion
    }

    fclose(pLibro);
    return -1;

    }
