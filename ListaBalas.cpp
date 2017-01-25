#include "ListaBalas.h"

void inicializaListaBalas(tBalas &listaB){
    listaB.cont = 0;
}

void destruyeBala(int pos, tBalas &listaB){
    listaB.balas[pos] -> borra();
    delete listaB.balas[pos];
    for(int i = pos; i < listaB.cont - 1; i++){
        listaB.balas[i] = listaB.balas[i + 1];
    }
	listaB.cont--;
}

void destruyeListaBalas(tBalas &listaB){
    for(int i =  0; i < listaB.cont; i++){
        delete listaB.balas[i];
    }
    listaB.cont = 0;
}

void insertaBala(tBalas &listaB, BALA bala){
    for(int i = listaB.cont - 1; i >= 0; i--){
        listaB.balas[i + 1] = listaB.balas[i];
    }
    listaB.balas[0] = new BALA(bala);
    listaB.cont++;
}

void mueveBalas(bool arriba, tBalas &listaB){
    for(int i =  0; i < listaB.cont; i++){
        listaB.balas[i] -> disparaBala(arriba);
        if(listaB.balas[listaB.cont - 1] -> limite(arriba)){
            destruyeBala(listaB.cont-1, listaB);
        }
    }
}

/*
 * En base a unas coord y unas dimensiones determina si alguna bala de la lista
 * ha impactado con el objeto.
 */

bool impactoObjeto(int _x, int _y, int _dimX, int _dimY, tBalas &listaB){
    bool impacto = false;

    for(int i = 0; i < listaB.cont && !impacto; i++){
        impacto = listaB.balas[i]->impactoBala(_x, _y, _dimX, _dimY);
        if(impacto){
            destruyeBala(i, listaB);
        }
    }
    return impacto;
}
