#ifndef LISTAMUROS_H_INCLUDED
#define LISTAMUROS_H_INCLUDED
#include "Muro.h"

int const N_MUROS = 4;
int const VIDA_MURO = 3;

typedef tMuroPtr tArrayM[N_MUROS];

typedef struct{
    int cont;
    tArrayM muros;
}tMuros;

void inicializaListaMuros(tMuros &listaM);
void insertaMuros(tMuros &listaM);
void destruyeMuro(int pos, tMuros &listaM);
void destruyeListaMuros(tMuros &listaM);
void pintaMuros(tMuros &listaM);
void impactoBalaMuro(tMuros &listaM, tBalas &listaB);

#endif // LISTAMUROS_H_INCLUDED
