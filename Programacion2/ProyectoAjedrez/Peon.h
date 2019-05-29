
#ifndef PEON_H
#define	PEON_H
#include <iostream>
#include "Pieza.h"
#include "Tablero.h"
#include "Jugador.h"
using namespace std;

class Peon : public Pieza{
public:
    Peon(bool );
    ~Peon();
    void nuevaPosicion(Casilla* );
    int valor() const;
    bool moverPieza(Jugador& , Casilla& );
    bool movimientoPiezaEnCasilla(Casilla& ) const;
    virtual bool movimentoPeon(Jugador& , Casilla&);
    bool obtenerMovimiento() const;
    void mostrar() const;
 
 private:
     
    Pieza* peonPieza;
    bool movimiento;

};

#endif	/* PEON_H */

