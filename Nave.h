#ifndef NAVE_H_INCLUDED
#define NAVE_H_INCLUDED

#include "Personajes.h"

char const IZQ = 'a';
char const DER = 'd';
char const ARRIBA = 'w';
char const ABAJO = 's';
char const SPACE_BAR = (char)32;
int const VIDA_NAVE = 3;
int const DIM_X_NAVE = 5;
int const DIM_Y_NAVE = 3;
int const NUM_BALAS_NAVE = 5;

class NAVE : public PERSONAJE{
public:
    tBalas listaB;

	NAVE(int _x, int _y, int vida) : PERSONAJE (_x, _y, vida){inicializaListaBalas(listaB);}
	void gotoxy(int x, int y) const;
	void pinta() const;
	void borra() const;
	void leeTecla();
	int dameCoordX() {return x; };
	int dameCoordY() { return y - 4; };
	int dameVidas() { return vida; };
	void impctoNaveBala(tBalas &listaB);
	//void impactoNaveEnemigo();
};

#endif // NAVE_H_INCLUDED
