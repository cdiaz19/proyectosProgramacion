
#include "Casilla.h"

Casilla::Casilla() {
}

Casilla::Casilla(int x, int y) : x(x), y(y), piezas(NULL) {
}

void Casilla::colocarPieza(Pieza* p) {
    piezas = p;
}

int Casilla::getX() const {
    return x;
}

int Casilla::getY() const {
    return y;
}

bool Casilla::casillaPieza() const {
    return piezas;
}

Pieza* Casilla::casillaOcupadaPor() const {
    return piezas;
}

Casilla::~Casilla() {
}