#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED

#include "Personajes.h"

int const TIEMPO_MOV_ENE = 18;
int const DIM_X_ENEM = 3;
int const DIM_Y_ENEM = 1;
int const VIDA_ENEM = 1;

class ENEMIGO : public PERSONAJE{
    int iteracion;
    bool dir;
    int tipo;
public:
    ENEMIGO(int x, int y, int vida, int _iteracion, bool _dir, int _tipo) :
                    PERSONAJE(x, y, vida), iteracion(_iteracion), dir(_dir), tipo(_tipo){}
	void gotoxy(int x, int y) const;
    void pinta() const;
    void borra() const;
    void mueveEnemigo(bool cambiaDir);
    int dameCoordX() { return x;};
    int dameCoordY(){return y;};
    int dameTipo(){ return tipo; };
    bool temporizador();
};

typedef ENEMIGO *tEnemigoPtr;

#endif // ENEMIGO_H_INCLUDED
