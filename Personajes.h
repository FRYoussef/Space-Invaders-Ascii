#ifndef PERSONAJES_H_INCLUDED
#define PERSONAJES_H_INCLUDED

#include "ListaBalas.h"

char const CUBO = (char)220;
char const TRIANGULO = (char)158;
char const TRIANGULO1 = (char)206;
int const LIM_TABLERO_H = 78;
int const LIM_TABLERO_V = 40;

/*
 * Es una clase abstracta de la que derivarán el resto
 */

class PERSONAJE{
protected:
	int x, y, vida;
public:
	PERSONAJE(int _x, int _y, int _vida) : x(_x), y(_y), vida(_vida){}
	virtual void pinta() const = 0;
	virtual void borra() const = 0;
	virtual int dameCoordX() = 0;
	virtual int dameCoordY() = 0;
};

#endif // PERSONAJES_H_INCLUDED
