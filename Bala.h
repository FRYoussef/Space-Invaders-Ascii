#ifndef BALA_H_INCLUDED
#define BALA_H_INCLUDED

char const DISPARO = (char)194;
int const TIEMPO_BALA = 2;
int const DIM_X_BALA = 1;
int const DIM_Y_BALA = 1;
int const LIM_TABLERO_V1 = 40;

class BALA{
   int x, y;
   int iteracion;
public:
   BALA (int _x, int _y, int _iteracion) : x(_x), y(_y), iteracion(_iteracion){}
   void gotoxy(int x, int y) const;
   void pinta() const;
   void borra() const;
   void disparaBala(bool arriba);
   bool impactoBala(int _x, int _y, int dimX, int dimY);
   bool limite(bool arriba);
   bool temporizador();
};

typedef BALA *tBALAptr;

#endif // BALA_H_INCLUDED
