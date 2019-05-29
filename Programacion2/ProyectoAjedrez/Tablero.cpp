
#include "Tablero.h"
#include "Pieza.h"
#include <stdlib.h>

Tablero::Tablero() {
    for(int i=0;i<tam;i++) {
        for(int j=0; j<tam;j++) {
            tablero[i][j] = new Casilla(i,j);
        }
    }
}

Tablero*  Tablero::getTablero() {
    if (!_tablero)
        _tablero = new Tablero();
    return _tablero;
}

Casilla* Tablero::colocarCasillaEnTablero(int x, int y) const{
    return tablero[x][y];
}

bool Tablero::casillaVertical(Casilla& desde, Casilla& hasta) const {
    Casilla* comienzo = NULL;
    Casilla* final = NULL;
    bool bandera = true;

    if (desde.getY() <= hasta.getY()) {
        comienzo = &desde;
        final = &hasta;
    } else {
        comienzo = &hasta;
        final = &desde;
    }
    
    if(comienzo->getX() != final->getX()) {
        bandera = false;
    } else  {
        for(int i = comienzo->getY() + 1; i < final->getY(); i++) {
            if(colocarCasillaEnTablero(comienzo->getX(), i)->casillaPieza()) {
                bandera = false;
            }
        } 
    }
    
    return bandera;
}

bool Tablero::casillaHorizontal(Casilla& desde, Casilla& hasta) const {
    Casilla* comienzo = NULL;
    Casilla* final = NULL;
    bool bandera = true;
    
    if(desde.getX() <= hasta.getX()) {
        comienzo = &desde;
        final = &hasta;
    } else  {
        comienzo = &hasta;
        final = &desde;
    }
    
    if(comienzo->getY() != final->getY()) {
        bandera = false;
    } else {
        for(int i = comienzo->getX() + 1; i < final->getX(); i++) {
            // if a square is occupied, the vertical is not clear
            if(colocarCasillaEnTablero(i, comienzo->getY())->casillaPieza())
            {
                bandera = false;
            }
        } 
    }
    
    return bandera;
}

bool Tablero::casillaDiagonal(Casilla& desde, Casilla& hasta) const {
    bool bandera = true;
    int _x = hasta.getX() - desde.getX();
    int _y = hasta.getY() - desde.getY();
    int xDir = 1;
    int yDir = 1;
    
    if(_x < 0) {  xDir = -1; }
    
    if(_y < 0) {  yDir = -1; }
    
    if(abs(_x) != abs(_y)) { 
        bandera = false;
    } else {
        for(int i = 1; i < abs(_x); i++) {
            if(colocarCasillaEnTablero(desde.getX() + (i * xDir), desde.getY() + (i * yDir))->casillaPieza())
            {
                bandera = false;
            }
        }
    }
    
    return bandera;
}

bool Tablero::finalFila(Casilla& localizacion) const {
    return (localizacion.getY() == 0 || localizacion.getY() == (tam - 1));
}

string Tablero::mostrarTablero() const {
    stringstream salida;
    salida << endl << "   a  b  c  d  e  f  g  h" << endl;
    salida << " -------------------------" << endl;
    for (int y = tam - 1; y >= 0; y--) 
    {
        salida << y + 1;
        for (int x = 0; x < tam; x++) {
            salida << "|";
            if(tablero[x][y]->casillaPieza())
                tablero[x][y]->casillaOcupadaPor()->mostrar();
            else
                cout << "  ";
        }
        salida << "|" << y + 1 << endl << " -------------------------" << endl;
    }
   
    return salida.str();
}

Tablero::~Tablero(){
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            delete[] tablero[i][j];
        }
        delete[] tablero[i];
    }
    delete[] tablero;
}
