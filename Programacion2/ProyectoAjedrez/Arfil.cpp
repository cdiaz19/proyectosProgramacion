
#include "Arfil.h"
Tablero *t = new Tablero();
Casilla *c = new Casilla();

Arfil::Arfil() {
}

Arfil::Arfil(bool _esBlanco) : Pieza(_esBlanco) {
}

int Arfil::valor() const {
    return 3;
}

bool Arfil::movimientoPiezaEnCasilla(Casilla& cas) const {
    bool movimientoValido = false;
    
    if(t->getTablero()->casillaDiagonal(*(this->localizacionCasilla(), cas))) {
        movimientoValido = true;
    }
    
    return movimientoValido;
}

void Arfil::mostrar() const {
    cout<<"B";
}

Arfil::~Arfil() {
}

