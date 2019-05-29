
#ifndef JUGADOR_H
#define	JUGADOR_H
#include <iostream>
#include <set>
#include "Pieza.h"
#include "Rey.h"
#include "Tablero.h"

using namespace std;

class Jugador {
public:
    Jugador(string, bool , Rey& , set<Pieza*>& );
    bool hacerMovimiento();
    bool jugadorCreado();
    void escogerPieza(Pieza* );
    string obtenerNombre() const;
    bool esBlanco() const;
    set<Pieza*>* piezasJugador() const;
    Rey* reyJugador() const;
    virtual ~Jugador();
    
private:
    string nombre;
    bool piezablanco;
    set<Pieza*>& piezasJugador;
    set<Pieza*> piezas;
    Rey& reyJugador;
    
};

#endif	/* JUGADOR_H */
