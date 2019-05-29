
#ifndef TABLERO_H
#define	TABLERO_H
#include <iostream>
#include <sstream>
#include "Casilla.h"
#include "Pieza.h"
using namespace std;

class Tablero {
public:
    Tablero();
    virtual ~Tablero();
    Tablero* getTablero();
    Casilla* colocarCasillaEnTablero(int, int ) const;
    bool casillaVertical(Casilla& , Casilla& ) const;
    bool casillaHorizontal(Casilla& , Casilla& ) const;
    bool casillaDiagonal(Casilla& , Casilla& ) const;
    bool finalFila(Casilla& ) const;
    virtual string mostrarTablero() const;

    static const int tam = 8;

 private:

    Tablero* _tablero;
    Casilla* tablero[tam][tam];
};

#endif	/* TABLERO_H */


/*
 * static const int NUM_PARTES = 8;
    static const int COD_ASCII = 65;
    static const char CARACTER_A = 'A';
    static const char CARACTER_H = 'H';
 */

