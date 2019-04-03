#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include "AuxiliaresJuego.h"

bool JuegaReversiVs();

bool JuegaReversiSolo(Posicion (* dificultad)(Movimiento[][9]));

Posicion Facil(Movimiento Posibles[][9]);

Posicion Medio(Movimiento Posibles[][9]);

#endif // JUEGO_H_INCLUDED
