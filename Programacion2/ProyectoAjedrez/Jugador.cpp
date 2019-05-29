
#include "Jugador.h"
#define X_MIN 'a'
#define X_MAX 'h'
#define Y_MIN '1'
#define Y_MAX '8'
set<Pieza*>& piezasJugador;
set<Pieza*> piezas;
Rey& reyJugador;
Tablero *t = new Tablero();

Jugador::Jugador(string nombre, bool esBlanco, Rey& reyJugador, set<Pieza*>& piezasJugador) 
: nombre(nombre), piezablanco(esBlanco), piezasJugador(piezasJugador), Rey(reyJugador) {
}

bool Jugador::hacerMovimiento() {
    string badInput; 
    string fromSquare =  "  ";
    string toSquare = "  ";
    int fromX;
    int fromY;
    int toX;
    int toY;

    if(jugadorCreado()) {
        cout << nombre << ", es su turno" << endl;
    }
    cout << nombre << ", por favor realizar el movimiento (Ejemplo:  a2 a4): ";
    cin >> fromSquare >> toSquare;
    
    while(fromSquare.length() != 2 ||
          toSquare.length() != 2 ||
          tolower(fromSquare.at(0)) < X_MIN ||
          tolower(fromSquare.at(0)) > X_MAX ||
          tolower(toSquare.at(0)) < X_MIN ||
          tolower(toSquare.at(0)) > X_MAX ||
          tolower(fromSquare.at(1)) < Y_MIN ||
          tolower(fromSquare.at(1)) > Y_MAX ||
          tolower(toSquare.at(1)) < Y_MIN ||
          tolower(toSquare.at(1)) > Y_MAX ||
          !(t->getTablero()->colocarCasillaEnTablero(tolower(fromSquare.at(0)) - X_MIN, tolower(fromSquare.at(1)) - Y_MIN)
            ->casillaPieza())) {
        cerr << "Invalid move. Try again." << endl;
        cin.clear();
        getline(cin, badInput);
        cout << nombre << " player enter move (e.g. a2 a4): ";
        cin >> fromSquare >> toSquare;
    }

    fromX = tolower(fromSquare.at(0)) - X_MIN;
    fromY = tolower(fromSquare.at(1)) - Y_MIN;
    toX = tolower(toSquare.at(0)) - X_MIN;
    toY = tolower(toSquare.at(1)) - Y_MIN;
    
    return  t->getTablero()->colocarCasillaEnTablero(fromX, fromY)->casillaOcupadaPor()
                    ->moverPieza(*this,*t->getTablero()->colocarCasillaEnTablero(toX,toY));
}

bool Jugador::jugadorCreado() {
    bool bandera = false;
    
   /* for (set<Pieza*>::iterator itr = Juego::opponentOf(*this)->myPieces()->begin(); 
         itr != Juego::opponentOf(*this)->myPieces()->end(); ++itr)
    {
        if (((Pieza*)*itr)->location() && 
            ((Pieza*)*itr)->canMoveTo(*(reyJugador()->location())))
        {
            bandera = true;
        }
    }*/
    
    return bandera;
}

void Jugador::escogerPieza(Pieza* pieza) {
    pieza->ingresarEnCasilla(NULL)
    piezas.insert(pieza);
}

string Jugador::obtenerNombre() const {
    return nombre;
}

bool Jugador::esBlanco() const {
    return esBlanco;
}

set<Pieza*>* Jugador::piezasJugador() const{
    return &piezasJugador;
}

Rey* Jugador::reyJugador() const {
    return &reyJugador;
}

Jugador::~Jugador() {
}

