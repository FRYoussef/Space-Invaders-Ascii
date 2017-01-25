#include <iostream>
#include <conio.h>
#include<Windows.h>
using namespace std;

#include "Nave.h"

void NAVE::gotoxy(int x, int y) const{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, coord);
}

void NAVE::pinta() const{
	gotoxy(x, y);
	cout << char(CUBO) << "$ $" << char(CUBO);
    gotoxy(x + 1, y - 1);
	cout << "(x)";
	gotoxy(x + 2, y - 2);
	cout << char(TRIANGULO);
}

void NAVE::borra() const{
	gotoxy(x, y);
	cout << "     ";
    gotoxy(x + 1, y - 1);
	cout << "   ";
	gotoxy(x + 2, y - 2);
	_putch(' ');
}

void NAVE::leeTecla(){
    if(_kbhit()){
        char tecla = _getch();
        borra();
        switch (tecla){
        case IZQ:
         if(x > 2){
            x--;
         }
          break;
        case DER:
         if(x + DIM_X_NAVE < LIM_TABLERO_H){
            x++;
         }
          break;
        case SPACE_BAR:
            if(listaB.cont < N_DISP){
                BALA bala(x + 2, y - 3, 0);
                insertaBala(listaB, bala);
            }
       }
       pinta();
    }
    mueveBalas(true, listaB);
}

void NAVE::impctoNaveBala(tBalas &listaB){
    if(impactoObjeto(x, y, DIM_X_NAVE, DIM_Y_NAVE, listaB)){
        vida--;
    }
}
