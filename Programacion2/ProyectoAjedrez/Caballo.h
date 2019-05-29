
#ifndef CABALLO_H
#define	CABALLO_H
#include "Pieza.h"
#include "Casilla.h"
#include <iostream>
using namespace std;

class Caballo : public Pieza {
public:
    Caballo();
    Caballo(bool );
    int valor() const;
    bool movimientoPiezaEnCasilla(Casilla& ) const;
    void mostrar() const;
    virtual ~Caballo();
private:

};

#endif	/* CABALLO_H */

