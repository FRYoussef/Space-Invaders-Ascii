#include <iostream>
#include<Windows.h>
using namespace std;
#include <conio.h>
#include "Enemigo.h"

void ENEMIGO::gotoxy(int x, int y) const{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, coord);
}

void ENEMIGO::pinta() const{
    gotoxy(x, y);
    cout << TRIANGULO1 << CUBO << TRIANGULO1;
    gotoxy(x + 1, y + 1);
    cout << TRIANGULO1;
}

void ENEMIGO::borra() const{
    gotoxy(x, y);
    cout << "   ";
    gotoxy(x + 1, y + 1);
    cout << " ";
}

void ENEMIGO::mueveEnemigo(bool cambiaDir){
   if(temporizador()){
        borra();

        // si ha alcanzado los lim del marco cambia el sentido y baja una linea
        if(cambiaDir){
            dir = !dir;
            y++;
        }
        if(dir){
            x += 2;
        } else {
            x -= 2;
        }
        pinta();
    }
}

bool ENEMIGO::temporizador(){
    iteracion++;
    if(iteracion == TIEMPO_MOV_ENE){
        iteracion = 0;
        return true;
    }
    return false;
}
