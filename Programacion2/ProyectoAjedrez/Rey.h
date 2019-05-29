
#ifndef REY_H
#define	REY_H
#include <iostream>
#include "Pieza.h"
using namespace std;

class Rey : public Pieza {
public:
    Rey();
    Rey(bool );
    int valor() const;
    bool movimientoPiezaEnCasilla(Casilla& ) const;
    void mostrar() const;
    virtual ~Rey();
    
private:
    
};

#endif	/* REY_H */

