
#include <cstdlib>
#include <iostream>
#include "Juego.h"
#include "Jugador.h"
#include "Tablero.h"
using namespace std;

int main(int argc, char** argv) {
    
    Juego *juego = new Juego();
    Tablero *tablero = new Tablero();
    Jugador* currentPlayer = NULL;
    
    juego->inicializarJuego();
    cout<<tablero->getTablero()->mostrarTablero();
    
    while(true)
    {
        currentPlayer = juego->turnoSigJugador();
        while(!currentPlayer->hacerMovimiento())
        {
            cerr << "IMovimiento no Valido, Intente de Nuevo." << endl;
        }
        cout<<tablero->getTablero()->mostrarTablero();
    }

    return 0;
}

