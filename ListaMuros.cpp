#include "ListaMuros.h"

void inicializaListaMuros(tMuros &listaM){
    listaM.cont = 0;
    insertaMuros(listaM);
}

void insertaMuros(tMuros &listaM){
    int x = 10;
    int y = LIM_TABLERO_V - 8;
    for(int i = 0; i < N_MUROS; i++){
        MURO muro((x + (18 * i)), y, VIDA_MURO);
        listaM.muros[i] = new MURO(muro);
        listaM.cont++;
    }
}

void destruyeMuro(int pos, tMuros &listaM){
   listaM.muros[pos] -> borra();
   delete listaM.muros[pos];
   for(int i = pos; i < listaM.cont - 1; i++){
        listaM.muros[i] = listaM.muros[i + 1];
    }
    listaM.cont--;
}

void destruyeListaMuros(tMuros &listaM){
       for(int i =  0; i < listaM.cont; i++){
        delete listaM.muros[i];
    }
    listaM.cont = 0;
}

void pintaMuros(tMuros &listaM){
    for(int i = 0; i < listaM.cont; i++){
        listaM.muros[i] -> pinta();
        if(listaM.muros[i] -> dameVida() == 0){
            destruyeMuro(i, listaM);
        }
    }
}

void impactoBalaMuro(tMuros &listaM, tBalas &listaB) {
    int x, y;
    bool impacto;
    for(int i = 0; i < listaM.cont; i++){
        x = listaM.muros[i] -> dameCoordX();
        y = listaM.muros[i] -> dameCoordY();
        impacto = impactoObjeto(x, y, DIM_X_MURO, 0, listaB);
        if(impacto){
            if(listaM.muros[i] -> dameVida() != 0){
                listaM.muros[i] -> decrementaVida();
            } else {
                destruyeMuro(i, listaM);
            }
        }
    }
}
