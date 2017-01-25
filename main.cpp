#include <iostream>
#include<Windows.h>
using namespace std;
#include <conio.h>
#include <stdlib.h>
#include <ctime>
#include "Nave.h"
#include "ListaEnemigos.h"
#include "ListaMuros.h"

char const ESQUINA_SUP_IZQ = (char)218;
char const ESQUINA_SUP_DRCHA = (char)191;
char const ESQUINA_INF_IZQ = (char)192;
char const ESQUINA_INF_DRCHA = (char)217;
char const LIN_H = (char)196;
char const LIN_V = (char)179;

void pintaMarco();
void ocultarCursor();
void muestraDatos(NAVE nave, int puntos);
void motorDeImpactos(int &ptos, NAVE &nave,tEnemigos &listaE, tMuros &listaM);
//void inicia_allegro(int ANCHO_ , int ALTO_);

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, coord);
}

int main(){
	NAVE nave (LIM_TABLERO_H / 2, LIM_TABLERO_V - 2, VIDA_NAVE);
	tEnemigos listaE;
	tMuros listaM;
    bool gameOver = false;
    int puntos = 0;

    srand(time(NULL));
    ocultarCursor();
    inicializaListaEnemigos(listaE);
    inicializaListaMuros(listaM);
	muestraDatos(nave, puntos);
	pintaMarco();
	nave.pinta();
	while(!gameOver){
       pintaMuros(listaM);
       mueveEnemigosYDispara(listaE);
       nave.leeTecla();
       motorDeImpactos(puntos, nave, listaE, listaM);
       muestraDatos(nave, puntos);
       gameOver = nave.dameVidas() == 0 || listaE.cont == 0;
       Sleep(30);
	}
	system("cls");
	destruyeListaBalas(nave.listaB);
	destruyeListaEnemigos(listaE);
	destruyeListaMuros(listaM);
	cin.get();
	return 0;
}

void pintaMarco(){

   // pintaNave primera linea
   cout << char(ESQUINA_SUP_IZQ);
   for(int i = 1; i < LIM_TABLERO_H; i++){
      cout << char(LIN_H);
   }
   cout << char(ESQUINA_SUP_DRCHA);

   // pintaNave los margenes
   for(int i = 5; i < LIM_TABLERO_V; i++){
      gotoxy(1, i);
      cout << char(LIN_V);
      gotoxy(LIM_TABLERO_H + 1, i);
      cout << char(LIN_V);
   }

   // pintaNave linea final
   gotoxy(1, LIM_TABLERO_V);
   cout << char(ESQUINA_INF_IZQ);
   for(int i = 1; i < LIM_TABLERO_H; i++){
      cout << char(LIN_H);
   }
   cout << char(ESQUINA_INF_DRCHA);
}

void ocultarCursor(){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hCon, &cci);
}

void muestraDatos(NAVE nave, int puntos){
    gotoxy(30, 2);
    cout << "Puntos: " << puntos << "  Vidas: " << nave.dameVidas() << endl << endl;
}

void motorDeImpactos(int &ptos, NAVE &nave, tEnemigos &listaE, tMuros &listaM){
    impactoBalaEnemigo(ptos, listaE, nave.listaB);
    nave.impctoNaveBala(listaE.listaB);
    impactoBalaMuro(listaM, nave.listaB);
    impactoBalaMuro(listaM, listaE.listaB);
}

/*void inicia_allegro(int ANCHO_ , int ALTO_){
   allegro_init();
   install_keyboard();

   set_color_depth(32);
   set_gfx_mode(GFX_AUTODETECT_WINDOWED, ANCHO_, ALTO_, 0, 0);
}*/
