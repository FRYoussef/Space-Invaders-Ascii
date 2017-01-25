#include <stdlib.h>
#include <ctime>
#include "ListaEnemigos.h"

/*
 * Hay que mejorar esta función
 */
void insertaEnemigos(tEnemigos &listaE){
    int x = 9;
    int y = 6;
    int lin = 3;
    int cont = 0;
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < (N_ENEMIGOS / lin); j++){

            // el incremento de x es para tener espaciado entre los enemigos
            ENEMIGO enemigo((x + (6 * j)), y, VIDA_ENEM, 0, true, 0);
            listaE.enemigos[cont] = new ENEMIGO(enemigo);
            listaE.cont++;
            cont++;
        }
        y += 2;
    }
}

void inicializaListaEnemigos(tEnemigos &listaE){
    listaE.cont = 0;
    insertaEnemigos(listaE);
    inicializaListaBalas(listaE.listaB);
}

void destruyeEnemigo(int pos, tEnemigos &listaE){
   listaE.enemigos[pos] -> borra();
   delete listaE.enemigos[pos];
   for(int i = pos; i < listaE.cont - 1; i++){
        listaE.enemigos[i] = listaE.enemigos[i + 1];
    }
    listaE.cont--;
}

void destruyeListaEnemigos(tEnemigos &listaE){
    destruyeListaBalas(listaE.listaB);
    for(int i =  0; i < listaE.cont; i++){
        delete listaE.enemigos[i];
    }
    listaE.cont = 0;
}

void mueveEnemigosYDispara(tEnemigos &listaE){
    mueveBalas(false, listaE.listaB);
    bool limite = limiteMarco(listaE);
    for(int i =  0; i < listaE.cont; i++){
        listaE.enemigos[i] -> mueveEnemigo(limite);
    }
    if(listaE.listaB.cont < E_DISP && listaE.cont > 0){
        int pos = rand() % listaE.cont;
        int x = listaE.enemigos[pos]->dameCoordX();
        int y = listaE.enemigos[pos]->dameCoordY();
        BALA bala(x + 1, y + 2, 0);
        insertaBala(listaE.listaB, bala);
    }
}

bool limiteMarco(const tEnemigos &listaE){
    for(int i =  0; i < listaE.cont; i++){
        int x = listaE.enemigos[i] -> dameCoordX();
        if(x <= 3 || x >= LIM_TABLERO_H - 3){
            return true;
        }
    }
    return false;
}

void impactoBalaEnemigo(int &puntos, tEnemigos &listaE, tBalas &listaB){
    int x, y;
    bool impacto = false;
    for(int i =  0; i < listaE.cont; i++){
        x = listaE.enemigos[i]->dameCoordX();
        y = listaE.enemigos[i]->dameCoordY();
        impacto = impactoObjeto(x, y, DIM_X_ENEM, DIM_Y_ENEM, listaB);
        if(impacto){
            switch(listaE.enemigos[i] -> dameTipo()){
                case 0:
                    puntos += DIEZ_PTOS;
                    break;
                case 1:
                    puntos += QUINCE_PTOS;
                    break;
                case 2:
                    puntos += VEINTE_PTOS;
            }
            destruyeEnemigo(i, listaE);
        }
    }
}

