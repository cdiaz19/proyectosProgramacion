
#include "Reina.h"
Tablero *t = new Tablero();
Casilla *c = new Casilla();

Reina::Reina() {
}

Reina::Reina(bool _esBlanco) : Pieza(_esBlanco) {
}

int Reina::valor() const {
    return 9;
}

bool Reina::movimientoPiezaEnCasilla(Casilla& cas) const {
    bool movimientoValido = false;
    
    if(t->getTablero()->casillaVertical(*(this->localizacionCasilla(), cas))) {
        movimientoValido = true;
    }else if(t->getTablero()->casillaHorizontal(*(this->localizacionCasilla(), cas))) {
        movimientoValido = true;
    }else if(t->getTablero()->casillaDiagonal(*(this->localizacionCasilla(), cas))) {
        movimientoValido = true;
    }
   
    return movimientoValido;
}

void Reina::mostrar() const {
    cout<<"R";
}

Reina::~Reina() {
}

