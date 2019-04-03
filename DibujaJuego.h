#ifndef DIBUJAJUEGO_H_INCLUDED
#define DIBUJAJUEGO_H_INCLUDED

#include "AuxiliaresJuego.h"

enum simSimple{ESD = 191, EII, CSAB, EID = 217, ESI, CSA = 194, CSI, EH, CRUZ, EV = 179, CSD};

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Dibujamos la pantalla del inicio del juego
  */
void DibujaPantallaInicioJuego();

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Dibujamos los nombres de los jugadores
  *
  * @param nombre1 cadena de caracteres nombre del jugador 1
  *
  * @param nombre2 cadena de caracteres nombre del jugador 2
  */
void DibujaNombres(char nombre1[], char nombre2[]);

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Imprime cuadro verde
  *
  * @param x Coordenada en x donde comienza la impresi�n del cuadro verde
  *
  * @param y Coordenada en y donde comienza la impresi�n del cuadro verde
  */
void ImprimeCuadroVerde(int x, int y);

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Se dibuja la ficha
  *
  * @param x rengl�n del tablero
  *
  * @param y columna del tablero
  *
  * @param color color de la ficha
  */
void DibujaFicha(int x, int y, miColor color);


//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Dibujamos el tablero
  */
void DibujaTablero();

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Imprimimos un mensaje si el movimiento es incorrecto
  */
void ImprimeMovimientoIncorrecto();

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Imprimimos un mensaje si el juego ha terminado
  */
void ImprimeJuegoTerminado();

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Imprimimos un mensaje si un jugador no puede poner ficha y es necesario saltar su turno
  *
  * @param Jugador el jugador el cual no puede poner ficha y debe de saltarse su turno
  */
void ImprimeSaltoTurno(espacioCasilla Jugador);

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Imprimimos la casilla
  *
  * @param col columna de la casilla con respecto al tablero
  *
  * @param ren rengl�n de la casilla con respecto al tablero
  */
void ImprimeCasilla(int col, int ren);

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Se dibuja un marco alrededor de la casilla en la que se encuentra el cursor
  *
  * @param col columna de la casilla con respecto al tablero
  *
  * @param ren rengl�n de la casilla con respecto al tablero
  *
  * @param color color del jugador en turno
  */
void ResaltaCasilla(int col, int ren, miColor color);

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Imprimimos el n�mero del score
  *
  * @param num el score que tiene el jugador
  *
  * @param x la posici�n del n�mero
  *
  * @param y la posici�n del n�mero
  */
void ImprimirNumero(int num, int x, int y);

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Imprimimos el nombre del jugador 1 en el tablero
  *
  * @param x la posici�n en la que se imprimir� el nombre
  *
  * @param y la posici�n en la que se imprimir� el nombre
  */
void ImprimeJugador1(int x, int y);

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Imprimimos el nombre del jugador 2 en el tablero
  *
  * @param x la posici�n en la que se imprimir� el nombre
  *
  * @param y la posici�n en la que se imprimir� el nombre
  */
void ImprimeJugador2(int x, int y);

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Imprimimos el marco que rodea al nombre
  *
  * @param x posici�n en la cu�l se imprimir� el marco
  *
  * @param y posici�n en la cu�l se imprimir� el marco
  *
  * @param alto el valor del alto que tendr� el marco
  *
  * @param ancho el valor del ancho que tendr� el marco
  */
void ImprimeMarcoSimple(int x, int y, int alto, int ancho);

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Imprimimos un mensaje cuando el juego queda en empate
  */
void ImprimeEmpate();

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Imprimimos un mensaje preguntando si quieren volver a jugar
  */
void ImprimeVolverAJugar();

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Imprimimos la selecci�n "Si" al cuestionamiento anterior
  */
void ImprimeSi();

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Imprimimos la selecci�n "No" al cuestionamiento anterior
  */
void ImprimeNo();

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Imprimimos un mensaje cuando termina el juego
  */
void ImprimeFinDelJuego();

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Imprimimos un mensaje mostrando el jugador que gan� la partida
  */
void ImprimeGana();

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Subraya las opciones disponibles para la elecci�n de volver a jugar dentro de la pantalla de fin de juego
  *
  * @param eleccion Recibe la elecci�n entre si y no para volver a jugar
  *
  * @param c caracter con el que se va a imprimir el subrayado
  */
void SubrayaFinDelJuego(bool eleccion, char c);

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Funci�n que imprime hints para el usuario donde se pueden realizar movimientos
  *
  * @param PosiblesMovimientos Tablero que guarda los lugares donde se pueden realizar movimientos
  *
  * @param c caracter con el que se va a imprimir para mostrar una hint
  */
void MostrarHints(Movimiento PosiblesMovimientos[][9], char c);

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Funci�n que imprimie un mensaje especificando el turno del jugador actual
  *
  * @param nombre Cadena que contiene el nombre del jugador en turno
  */

void ImprimeTurnoActual(char nombre[]);

#endif // DIBUJAJUEGO_H_INCLUDED
