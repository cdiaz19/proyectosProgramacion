
#ifndef REINA_H
#define	REINA_H
#include "Pieza.h"
#include "Casilla.h"
#include <iostream>
using namespace std;

class Reina : public Pieza{
public:
    Reina();
    Reina(bool );
    int valor() const;
    bool movimientoPiezaEnCasilla(Casilla& ) const;
    void mostrar() const;
    virtual ~Reina();
private:

};

#endif	/* REINA_H */

