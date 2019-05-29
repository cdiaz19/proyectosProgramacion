
#ifndef ARFIL_H
#define	ARFIL_H
#include "Pieza.h"
#include "Casilla.h"
#include <iostream>
using namespace std;

class Arfil : public Pieza {
public:
    
    Arfil();
    Arfil(bool );
    int valor() const;
    bool movimientoPiezaEnCasilla(Casilla& ) const;
    void mostrar() const;
    virtual ~Arfil();
    
private:

};

#endif	/* ARFIL_H */

