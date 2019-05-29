
#include "Peon.h"
#include "Reina.h"

Tablero *t = new Tablero();
Pieza *p = new Pieza();
Casilla *c = new Casilla();

Peon::Peon(bool esBlanco) :  peonPieza(NULL) {
}

void Peon::nuevaPosicion(Casilla* nuevaPos) {
    p->ingresarEnCasilla(nuevaPos);
}

int Peon::valor() const {
    return 1;
}

bool Peon::moverPieza(Jugador& juga, Casilla& cas) {
    bool bandera = false;
    if(peonPieza) {
        
        bandera = peonPieza->moverPieza(juga, cas);

        if(bandera) {
            p->localizacionCasilla()->colocarPieza(NULL);
            nuevaPosicion(&cas);
            p->localizacionCasilla()->colocarPieza(this);
        }
    } else  {
        bandera =movimentoPeon(juga, cas);

        if(bandera)
        {
            if(t->getTablero()->finalFila(*localizacionCasilla())) {
                peonPieza = new Reina(esBlanco());
                peonPieza->localizacionCasilla(localizacionCasilla());
            }
        }
    }
    
    return bandera;
}

bool Peon::movimientoPiezaEnCasilla(Casilla& casillaNueva) const {
    bool bandera = false;
    int _x = casillaNueva.getX() - this->localizacionCasilla()->getX();
    int _y = casillaNueva.getY() - this->localizacionCasilla()->getY();
 
    if(peonPieza) {
        bandera = peonPieza->movimientoPiezaEnCasilla(casillaNueva);
    }else {
        if(!esBlanco()) {
            _x *= -1;
            _y *= -1;
        }
        
        if(!casillaNueva.casillaPieza() && _y == 1 && _x == 0) {
            bandera = true;
        } else if(!obtenerMovimiento() && _y == 2 && _x == 0 &&
                t->getTablero()->casillaVertical(*(this->localizacionCasilla(), casillaNueva))) {
            bandera = true;
        } else if(casillaNueva.casillaPieza() && _y == 1 &&  (_x == 1 || _x == -1)) {
            bandera = true;
        }        
    }

    return bandera;
}

void Peon::mostrar() const
{
    if(peonPieza) {
        peonPieza->mostrar();
    }else{
        cout << "P";
    }
}

bool Peon::movimentoPeon(Jugador& jug, Casilla& cas) {
    bool movimientoValido = p->moverPieza(jug,cas);
    movimiento = false;
  
    if(movimientoValido && !movimiento) {
        movimiento = true;
    }
    
    return movimientoValido;
}

bool Peon::obtenerMovimiento() const{
    return movimiento;
}

Peon::~Peon() {
    if(peonPieza)
        delete peonPieza;
}
