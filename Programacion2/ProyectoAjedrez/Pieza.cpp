
#include "Pieza.h"
#include "Casilla.h"

Pieza::Pieza(bool piezablanco) : piezablanco(piezablanco), casillas(NULL) {
    if(esBlanco)
        color = "B";
    else
        color = "N";
}

int Pieza::valor() const {
    return 0;
}

 void Pieza::mostrar() const {
}
 
 bool Pieza::movimientoPiezaEnCasilla(Casilla& cas) const {
     bool bandera = false;
     
     return bandera;
}

bool Pieza::moverPieza(Jugador& jugador, Casilla& casillaNueva) {
    bool bandera = false;
    Pieza* pieza = NULL;
    Casilla* casillaSeleccionada = casillas;
    
    if(esBlanco == jugador.esBlanco()) {
        if(movimientoPiezaEnCasilla(casillaNueva)) {
            if(casillaNueva.casillaPieza()) {
                pieza = casillaNueva.casillaOcupadaPor()();

                if(pieza->esBlanco() != jugador.esBlanco()) {
                    bandera = true;
                }
            } else {
                bandera = true;
            }

            if(bandera) {
                if(pieza) {
                    pieza->localizacionCasilla(NULL);
                } 
                
                casillas->colocarPieza(NULL);
                casillas = &casillaNueva;
                casillas->colocarPieza(this);

                if(jugador.jugadorCreado()) {
                    bandera = false;                    
                    casillas = casillaSeleccionada;
                    casillas->colocarPieza(this);
                    casillaNueva.colocarPieza(pieza);

                    if(pieza) {
                        pieza->ingresarEnCasilla(&casillaNueva);
                    }
                } else {
                    if(pieza)
                    {
                        jugador.escogerPieza(pieza);
                    } 
                }
            }
        }
    }
    
    return bandera;
}

void Pieza::ingresarEnCasilla(Casilla* posicion) {
    casillas = posicion;
}

bool Pieza::esBlanco() const {
    return esBlanco;
}

string Pieza::obtenerColor() const {
    return color;
}

bool Pieza::piezaEnCasilla() const {
    return casillas;
}

Casilla* Pieza::localizacionCasilla() const {
    return casillas;
}

Pieza::~Pieza() {
}
