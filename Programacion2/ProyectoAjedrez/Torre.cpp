
#include "Torre.h"
Tablero *t = new Tablero();
Casilla *c = new Casilla();

Torre::Torre() {
}

Torre::Torre(bool _esBlanco) : Pieza(_esBlanco) {
}

int Torre::valor() const {
    return 5;
}

bool Torre::movimientoPiezaEnCasilla(Casilla& cas) const {
    bool movimientoValido = false;
    
    if(t->getTablero()->casillaVertical(*(this->localizacionCasilla(), cas))) {
        movimientoValido = true;
    }else if(t->getTablero()->casillaHorizontal(*(this->localizacionCasilla(), cas))) {
        movimientoValido = true;
    }
    
    return movimientoValido;
}

void Torre::mostrar() const {
    cout<<"T";
}

Torre::~Torre() {
}

