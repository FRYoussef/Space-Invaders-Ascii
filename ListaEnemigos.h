#ifndef LISTAENEMIGOS_H_INCLUDED
#define LISTAENEMIGOS_H_INCLUDED

#include "Enemigo.h"

int const N_ENEMIGOS = 33;
int const E_DISP = 2;
int const DIEZ_PTOS = 10;
int const QUINCE_PTOS = 15;
int const VEINTE_PTOS = 20;

typedef tEnemigoPtr tArrayEnemigo[N_ENEMIGOS];

typedef struct {
    int cont;
    tArrayEnemigo enemigos;
    tBalas listaB;
}tEnemigos;

void inicializaListaEnemigos(tEnemigos &listaE);
void destruyeEnemigo(int pos, tEnemigos &listaE);
void destruyeListaEnemigos(tEnemigos &listaE);
void insertaEnemigos(tEnemigos &listaE);
void mueveEnemigosYDispara(tEnemigos &listaE);
bool limiteMarco(const tEnemigos &listaE);
void impactoBalaEnemigo(int &puntos, tEnemigos &listaE, tBalas &listaB);

#endif // LISTAENEMIGOS_H_INCLUDED
