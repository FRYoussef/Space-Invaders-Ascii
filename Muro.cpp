#include <iostream>
#include<Windows.h>
using namespace std;
#include <conio.h>

#include "Muro.h"

void MURO::gotoxy(int x, int y) const{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, coord);
}

void MURO::pinta() const{
    gotoxy(x, y);
    cout << "------";
}

void MURO::borra() const{
    gotoxy(x, y);
    cout << "      ";
}
