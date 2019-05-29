
#include "Rey.h"
#include <stdlib.h>

Rey::Rey() {
}

Rey::Rey(bool _esBlanco) : Pieza(_esBlanco) {
}

int Rey::valor() const {
    return 0;
}

bool Rey::movimientoPiezaEnCasilla(Casilla& cas) const {
    bool movimientoValido = false;
    int _x = cas.getX() - this->localizacionCasilla()->getX();
    int _y = cas.getY() - this->localizacionCasilla()->getY();
    
    if(abs(_y) == 1 && _x == 0) {
        movimientoValido = true;
    }else if(abs(_x) == 1 && _y == 0) {
        movimientoValido = true;
    } else if(abs(_x) == 1 && abs(_y) == 1) {
        movimientoValido = true;
    }
    
    return movimientoValido;
}

void Rey::mostrar() const {
    cout<<"K";
}

Rey::~Rey() {
}

