#include <iostream>
#include<Windows.h>
using namespace std;
#include <conio.h>
#include "Bala.h"

void BALA::gotoxy(int x, int y) const{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, coord);
}

void BALA::pinta() const{
   gotoxy(x, y);
   cout << char(DISPARO);
}

void BALA::borra() const{
   gotoxy(x, y);
   cout << " ";
}

void BALA::disparaBala(bool arriba){
   if(arriba && !limite(arriba) && temporizador()){
      borra();
      y--;
      pinta();
   }else if (!arriba && !limite(arriba) && temporizador()){
      borra();
      y++;
      pinta();
   }
}

/*
 * Se pasan como parametros las coord del objeto, y las dimensiones de este,
 * ej: cuanto hacia la derecha se extiende el objeto.
 * Devuelve si ha impactado con el objeto
 */
bool BALA::impactoBala(int _x, int _y, int _dimX, int _dimY){
    return (_x <= x) && (x <= _x + _dimX) && (_y <= y) && (y <= _y + _dimY);
}

bool BALA::limite(bool arriba){
    bool alcanzado = true;
    if(arriba){
        if(y > 5) alcanzado = false;
    }else {
        if(y < LIM_TABLERO_V1 - 1) alcanzado = false;
    }
    return alcanzado;
}

bool BALA::temporizador(){
    iteracion++;
    if(iteracion == TIEMPO_BALA){
        iteracion = 0;
        return true;
    }
    return false;
}
