# include "ArchivoAutores.h"
# include "Autor.h"
# include<iostream>
# include<cstring>

using namespace std;

    int ArchivoAutores::buscarAutorXIdAutor(int idAutor){
    Autor obj;

    FILE *pAutor;
    pAutor==fopen(_nombreArchivo, "rb");

    if(pAutor==nullptr){
        return-2;
    }

    int pos=0;

    while(fread(&obj, _tamanioRegistro, 1, pAutor)==1){
        if(obj.getIdAutor()==idAutor){
            return pos;
        }
        pos++;
    }
    fclose(pAutor);
    return -1;

    }
