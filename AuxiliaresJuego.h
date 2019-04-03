#ifndef AUXILIARESJUEGO_H_INCLUDED
#define AUXILIARESJUEGO_H_INCLUDED

struct Posicion{
    int ren, col;
};

struct Direccion{
    int i, j;
};

struct Movimiento{
    bool posible;
    int puntos, numDirecciones;
    int distancias[8];
    Direccion direcciones[8];
};

enum espacioCasilla{VACIO, BLANCA, NEGRA};

/**
  * @brief Función para jugar de nuevo
  *
  * @param Ganador de tipo espacioCasilla
  *
  * @param nombre El nombre del jugador
  */
bool JugarDeNuevo(espacioCasilla Ganador, char nombre[]);
//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Checamos si un movimiento es posible
  *
  * @param Tab arreglo bidimensional que representa el tablero de juego
  *
  * @param Jugador el jugador en turno
  *
  * @param ren renglón del tablero
  *
  * @param col columna del tablero
  */
void RevisaMovimiento(espacioCasilla Tab[][10], Movimiento PosiblesMovimientos[][9], espacioCasilla Jugador, int ren, int col);

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Realiza el movimiento necesario
  *
  * @param Tab arreglo bidimensional que representa el tablero de juego
  *
  * @param ren renglón del tablero
  *
  * @param col columna del tablero
  *
  * @param Jugador el jugador en turno
  *
  * @param scoreJugador el puntaje del jugador en turno
  *
  * @param scoreOponente el puntaje del jugador oponente
  */
void RealizaMovimiento(espacioCasilla Tab[][10], Movimiento PosiblesMovimientos[][9], Posicion posicion, espacioCasilla Jugador, int &scoreJugador, int &scoreOponente);

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Colocamos la ficha en el lugar del tablero dado
  *
  * @param y renglón del tablero
  *
  * @param x columna del tablero
  *
  * @param color color de la ficha
  */
void ColocarFicha(int x, int y, miColor color);


//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Inicializamos el tablero
  *
  * @param Tab arreglo bidimensional que representa el tablero de juego
  */
void InicializaTablero(espacioCasilla Tab[][10]);

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Imprimimos el tablero
  *
  * @param Tab arreglo bidimensional que representa el tablero de juego
  */
void ImprimeTablero(espacioCasilla Tab[][10]);

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Capturamos el movimiento
  *
  * @param color color de la ficha en juego
  */
Posicion CapturaMovimiento(miColor color);

//-------------------------------------------------------------------------------------------------------------
void CapturaNombre1(char nombre1[]);

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Capturamos los nombres de ambos jugadores
  *
  * @param nombre1 arreglo de caracteres que usaremos para el nombre del jugador 1
  *
  * @param nombre2 arreglo de caracteres que usaremos para el nombre del jugador 2
  */
void CapturaNombres(char nombre1[], char nombre2[]);

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Imprimimos el puntaje de ambos jugadores
  *
  * @param score1 el puntaje del jugador 1
  *
  * @param score2 el puntaje del jugador 2
  */
void ImprimeScores(int score1, int score2);

#endif // AUXILIARESJUEGO_H_INCLUDED
