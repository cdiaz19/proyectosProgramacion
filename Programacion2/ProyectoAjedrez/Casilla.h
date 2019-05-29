
#ifndef CASILLA_H
#define	CASILLA_H
#include <iostream>
#include "Pieza.h"
using namespace std;

class Casilla {
public:
    Casilla();
    Casilla(int, int);
    void colocarPieza(Pieza* );
    int getX() const;
    int getY() const;
    bool casillaPieza() const;   
    Pieza* casillaOcupadaPor() const;

    virtual ~Casilla();

 private:

    int x;
    int y;
    Pieza* piezas;
};

#endif	/* CASILLA_H */

