
#include "Juego.h"
Jugador* jugador1 = NULL;
Jugador* jugador2 = NULL;
Jugador* proximoJugador = NULL;
set<Pieza*> piezasBlancas;
set<Pieza*> piezasNegras;

Juego::Juego() {
}

void Juego::inicializarJuego() {
    Pieza *_pieza;
    Rey* _rey;
    Casilla *_casilla;
    
    piezasBlancas = *(new set<Pieza*>);
    piezasNegras = *(new set<Pieza*>);
    
    _pieza = new Reina(true);
    _casilla = t->getTablero()->colocarCasillaEnTablero(3,0);
    _casilla->colocarPieza(_pieza);
    _pieza->ingresarEnCasilla(_casilla);
    piezasBlancas.insert(_pieza);
    
    _pieza = new Reina(false);
    _casilla = t->getTablero()->colocarCasillaEnTablero(3,7);;
    _casilla->colocarPieza(_pieza);
    _pieza->ingresarEnCasilla(_casilla);
    piezasNegras.insert(_pieza);
    
    _pieza = new Arfil(true);
    _casilla = t->getTablero()->colocarCasillaEnTablero(2,0);
    _casilla->colocarPieza(_pieza);
    _pieza->ingresarEnCasilla(_casilla);
    piezasBlancas.insert(_pieza);
    _pieza = new Arfil(false);
    _casilla = t->getTablero()->colocarCasillaEnTablero(2,7);;
    _casilla->colocarPieza(_pieza);
    _pieza->ingresarEnCasilla(_casilla);
    piezasNegras.insert(_pieza);
    _pieza = new Arfil(true);
    _casilla = t->getTablero()->colocarCasillaEnTablero(5,0);
    _casilla->colocarPieza(_pieza);
    _pieza->ingresarEnCasilla(_casilla);
    piezasBlancas.insert(_pieza);
    _pieza = new Arfil(false);
    _casilla = t->getTablero()->colocarCasillaEnTablero(5,7);
    _casilla->colocarPieza(_pieza);
    _pieza->ingresarEnCasilla(_casilla);
    piezasNegras.insert(_pieza);
    
    _pieza = new Caballo(true);
    _casilla = t->getTablero()->colocarCasillaEnTablero(1,0);
    _casilla->colocarPieza(_pieza);
    _pieza->ingresarEnCasilla(_casilla);
    piezasBlancas.insert(_pieza);
    _pieza = new Caballo(false);
    _casilla = t->getTablero()->colocarCasillaEnTablero(1,7);
    _casilla->colocarPieza(_pieza);
    _pieza->ingresarEnCasilla(_casilla);
    piezasNegras.insert(_pieza);
    _pieza = new Caballo(true);
    _casilla = t->getTablero()->colocarCasillaEnTablero(6,0);
    _casilla->colocarPieza(_pieza);
    _pieza->ingresarEnCasilla(_casilla);
    piezasBlancas.insert(_pieza);
    _pieza = new Caballo(false);
    _casilla = t->getTablero()->colocarCasillaEnTablero(6,7);
    _casilla->colocarPieza(_pieza);
    _pieza->ingresarEnCasilla(_casilla);
    piezasNegras.insert(_pieza);
    
    _pieza = new Torre(true);
    _casilla = t->getTablero()->colocarCasillaEnTablero(0,0);
    _casilla->colocarPieza(_pieza);
    _pieza->ingresarEnCasilla(_casilla);
    piezasBlancas.insert(_pieza);
    _pieza = new Torre(false);
    _casilla = t->getTablero()->colocarCasillaEnTablero(0,7);
    _casilla->colocarPieza(_pieza);
    _pieza->ingresarEnCasilla(_casilla);
    piezasNegras.insert(_pieza);
    _pieza = new Torre(true);
    _casilla = t->getTablero()->colocarCasillaEnTablero(7,0);
    _casilla->colocarPieza(_pieza);
    _pieza->ingresarEnCasilla(_casilla);
    piezasBlancas.insert(_pieza);
    _pieza = new Torre(false);
    _casilla = t->getTablero()->colocarCasillaEnTablero(7,7);
    _casilla->colocarPieza(_pieza);
    _pieza->ingresarEnCasilla(_casilla);
    piezasNegras.insert(_pieza);
    
    for (int i = 0; i < 8; i++)
    {
        _pieza = new Peon(true);
        _casilla = t->getTablero()->colocarCasillaEnTablero(i,1);
        _casilla->colocarPieza(_pieza);
        _pieza->ingresarEnCasilla(_casilla);
        piezasBlancas.insert(_pieza);
        _pieza = new Peon(false);
        _casilla = t->getTablero()->colocarCasillaEnTablero(i,6);
        _casilla->colocarPieza(_pieza);
        _pieza->ingresarEnCasilla(_casilla);
        piezasNegras.insert(_pieza);
    }
    
    _rey = new Rey(true);
    _casilla =  t->getTablero()->colocarCasillaEnTablero(4,0);
    _casilla->colocarPieza(_rey);
    _rey->ingresarEnCasilla(_casilla);
    piezasBlancas.insert(_rey);
    
    _rey = new Rey(false);
    _casilla =  t->getTablero()->colocarCasillaEnTablero(4,7);
    _casilla->colocarPieza(_rey);
    _rey->ingresarEnCasilla(_casilla);
    piezasNegras.insert(_rey);
    
    jugador1 = new Jugador("JugadorBlanco", true, *_rey, piezasBlancas);
    jugador2 = new Jugador("JugadorNegro", false, *_rey, piezasNegras);
    proximoJugador = jugador2;
    
}

Jugador* Juego::turnoSigJugador() {
    proximoJugador = oponente(*proximoJugador);
    return proximoJugador;
}

Jugador* Juego::oponente(Jugador& jug) {
    Jugador* jugadorOponente;
    
    if(jug.obtenerNombre() == jugador1->obtenerNombre()) {
        jugadorOponente = jugador2;
    }else {
        jugadorOponente = jugador1;
    }

    return jugadorOponente;
}

Juego::~Juego() {
    for (set<Pieza*>::iterator itr = piezasBlancas.begin();
         itr != piezasBlancas.end(); ++itr)
    {
        delete *itr;
    }
    piezasBlancas.clear();
    for (set<Pieza*>::iterator itr = piezasNegras.begin();
         itr != piezasNegras.end(); ++itr)
    {
        delete *itr;
    }
    piezasNegras.clear();
    delete &jugador1;
    delete &jugador2;
}
