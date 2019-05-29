
#ifndef JUEGO_H
#define	JUEGO_H
#include <iostream>
#include <set>
#include "Tablero.h"
#include "Pieza.h"
#include "Caballo.h"
#include "Arfil.h"
#include "Peon.h"
#include "Reina.h"
#include "Rey.h"
#include "Torre.h"
#include "Casilla.h"
#include "Jugador.h"

class Juego {
public:
    Juego();
    void inicializarJuego();
    Jugador* turnoSigJugador();
    Jugador* oponente(Jugador& );
    virtual ~Juego();
    
private:
    
};

#endif	/* JUEGO_H */

