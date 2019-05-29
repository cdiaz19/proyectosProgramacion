
#include "Caballo.h"
#include <stdlib.h>

Caballo::Caballo() {
}

Caballo::Caballo(bool _esBlanco) : Pieza(_esBlanco) {
}

int Caballo::valor() const {
    return 3;
}

bool Caballo::movimientoPiezaEnCasilla(Casilla& cas) const {
    bool movimientoValido = false;
    int _x = cas.getX() - this->localizacionCasilla()->getX();
    int _y = cas.getY() - this->localizacionCasilla()->getY();
    
    if(abs(_y) == 1 && abs(_x) == 2) {
        movimientoValido = true;
    }else if(abs(_x) == 1 && abs(_y) == 2) {
        movimientoValido = true;
    }
    
    return movimientoValido;
}

void Caballo::mostrar() const {
    cout<<"C";
}

Caballo::~Caballo() {
}

