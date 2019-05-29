
#ifndef PIEZA_H
#define	PIEZA_H
#include <iostream>
#include <string>
#include "Casilla.h"
#include "Jugador.h"
#include "Tablero.h"
using namespace std;

class Pieza {
public:
    Pieza();
    Pieza(bool);
    virtual ~Pieza();
    virtual bool moverPieza(Jugador&, Casilla& );
    virtual void ingresarEnCasilla(Casilla*  );
    virtual int valor() const;
    bool esBlanco() const;
    string obtenerColor() const;    
    virtual void mostrar() const;   
    virtual bool movimientoPiezaEnCasilla(Casilla& ) const ;
    bool piezaEnCasilla() const;
    Casilla* localizacionCasilla() const;

private:

    Casilla* casillas;
    bool piezablanco;
    string color;
    
};

#endif	/* PIEZA_H */

