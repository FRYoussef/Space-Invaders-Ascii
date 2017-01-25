#ifndef MURO_H_INCLUDED
#define MURO_H_INCLUDED
#include "Personajes.h"

int const DIM_X_MURO = 6;
int const DIM_Y_MURO = 1;

class MURO : public PERSONAJE{
public:
    MURO(int x , int y, int vida) : PERSONAJE(x, y, vida){}
	void gotoxy(int x, int y) const;
    void pinta() const;
    void borra() const;
    int dameCoordX() {return x; };
    int dameCoordY() {return y; };
    int dameVida() { return vida; };
    void decrementaVida() { vida--; }
};

typedef MURO *tMuroPtr;

#endif // MURO_H_INCLUDED
