#ifndef LISTABALAS_H_INCLUDED
#define LISTABALAS_H_INCLUDED

#include "Bala.h"

int const N_DISP = 5;

typedef tBALAptr tArrayBala[N_DISP];

typedef struct{
   int cont;
   tArrayBala balas;
}tBalas;

void inicializaListaBalas(tBalas &listaB);
void destruyeBala(int pos, tBalas &listaB);
void destruyeListaBalas(tBalas &listaB);
void insertaBala(tBalas &listaB, BALA bala);
void mueveBalas(bool arriba, tBalas &listaB);
bool impactoObjeto(int _x, int _y, int _dimX, int _dimY, tBalas &listaB);

#endif // LISTABALAS_H_INCLUDED
