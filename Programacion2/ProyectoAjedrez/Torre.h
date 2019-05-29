
#ifndef TORRE_H
#define	TORRE_H
#include <iostream>
#include "Pieza.h"
using namespace std;

class Torre : public Pieza {
public:
    Torre();
    Torre(bool );
    int valor() const;
    bool movimientoPiezaEnCasilla(Casilla& ) const;
    void mostrar() const;
    virtual ~Torre();
private:

};

#endif	/* TORRE_H */

