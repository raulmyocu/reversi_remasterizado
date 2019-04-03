/*
Nombre: .cpp
Autor: Raúl Octavio Murcia Yocupicio
Fecha:
Descripción:
*/

#include <cstdlib>
#include <windows.h>

#include "ManejoConsola.h"
#include "DibujaJuego.h"
#include "AuxiliaresJuego.h"

bool JuegaReversiVs(){
    espacioCasilla JugadorActual = NEGRA, tablero[10][10];
    Movimiento PosiblesMovimientos[9][9];
    Posicion posicion;
    bool posible;
    int score1 = 2, score2 = 2, fichasEnTablero = 4, turnosSinMov = 0, cuentaErrores;
    char nombreNegras[21], nombreBlancas[21];

    CapturaNombres(nombreNegras, nombreBlancas);
    DibujaNombres(nombreNegras, nombreBlancas);

    InicializaTablero(tablero);

    DibujaPantallaInicioJuego();

    ImprimeTablero(tablero);

    do{
        ImprimeTurnoActual(JugadorActual == NEGRA ? nombreNegras: nombreBlancas);

        posible = false; //Variable auxiliar para determinar si es posible realizar un movimiento en el turno

        for(int i = 1; i < 9; i++)
            for(int j = 1; j < 9; j++){ //Para cada casilla del tablero se revisa si es posible realizar un movimiento
                RevisaMovimiento(tablero, PosiblesMovimientos, JugadorActual, i, j);
                if (PosiblesMovimientos[i][j].posible) posible = true;
            }

        if (posible){
            turnosSinMov = 0; //Reinicia ambas variables
            cuentaErrores = 0;

            do{
                posicion = CapturaMovimiento(JugadorActual == NEGRA ? NEGRO : BLANCO);
                posible = PosiblesMovimientos[posicion.ren][posicion.col].posible;

                if (!posible) {
                    ImprimeMovimientoIncorrecto();
                    cuentaErrores++;
                    if (cuentaErrores == 3){
                        MostrarHints(PosiblesMovimientos, '*');  //Si ocurren tres errores se muestran hints
                    }
                }

            }while(!posible); //Valida la elección del usuario

            MostrarHints(PosiblesMovimientos, ' '); //Borrando hints
            RealizaMovimiento(tablero, PosiblesMovimientos, posicion, JugadorActual, (JugadorActual == NEGRA ? score1 : score2), (JugadorActual == NEGRA ? score2 : score1));
            fichasEnTablero++;

        }else{
            ImprimeSaltoTurno(JugadorActual); //Imprime mensaje de salto de turno
            turnosSinMov++;
        }

        ImprimeScores(score1, score2);

        JugadorActual = (JugadorActual == NEGRA ? BLANCA : NEGRA);

    }while(fichasEnTablero < 64 && turnosSinMov < 2);
    /* Una condición de paro es que se terminen los espacios, otra es que el número de movimientos sea 0*/

    ImprimeJuegoTerminado();

    //Se manda a la pantalla de jugar de nuevo

    if (score1 > score2) return JugarDeNuevo(NEGRA, nombreNegras);
    if (score1 < score2) return JugarDeNuevo(BLANCA, nombreBlancas);

    return JugarDeNuevo(VACIO, nombreNegras);
}


bool JuegaReversiSolo(Posicion (*dificultadMovimiento)(Movimiento[][9])){
    espacioCasilla JugadorActual = NEGRA, tablero[10][10], Jugador = NEGRA; //Por mientras
    Movimiento PosiblesMovimientos[9][9];
    Posicion posicion;
    bool posible;
    int score1 = 2, score2 = 2, fichasEnTablero = 4, turnosSinMov = 0, cuentaErrores;
    char nombreNegras[21], nombreBlancas[21] = "CPU";

    CapturaNombre1(nombreNegras);
    DibujaNombres(nombreNegras, nombreBlancas);

    InicializaTablero(tablero);

    DibujaPantallaInicioJuego();

    ImprimeTablero(tablero);



    do{
        ImprimeTurnoActual(JugadorActual == NEGRA ? nombreNegras: nombreBlancas);

        posible = false; //Variable auxiliar para determinar si es posible realizar un movimiento en el turno

        for(int i = 1; i < 9; i++)
            for(int j = 1; j < 9; j++){ //Para cada casilla del tablero se revisa si es posible realizar un movimiento
                RevisaMovimiento(tablero, PosiblesMovimientos, JugadorActual, i, j);
                if (PosiblesMovimientos[i][j].posible) posible = true;
            }

        if (posible){
            if (JugadorActual == Jugador){
                turnosSinMov = 0; //Reinicia ambas variables
                cuentaErrores = 0;

                do{
                    posicion = CapturaMovimiento(JugadorActual == NEGRA ? NEGRO : BLANCO);
                    posible = PosiblesMovimientos[posicion.ren][posicion.col].posible;

                    if (!posible) {
                        ImprimeMovimientoIncorrecto();
                        cuentaErrores++;
                        if (cuentaErrores == 3){
                            MostrarHints(PosiblesMovimientos, '*');  //Si ocurren tres errores se muestran hints
                        }
                    }
                }while(!posible); //Valida la elección del usuario

                MostrarHints(PosiblesMovimientos, ' '); //Borrando hints

            }else{
                Sleep(700);
                posicion = dificultadMovimiento(PosiblesMovimientos);

            }

            RealizaMovimiento(tablero, PosiblesMovimientos, posicion, JugadorActual, (JugadorActual == NEGRA ? score1 : score2), (JugadorActual == NEGRA ? score2 : score1));
            fichasEnTablero++;

        }else{
            ImprimeSaltoTurno(JugadorActual); //Imprime mensaje de salto de turno
            turnosSinMov++;
        }

        ImprimeScores(score1, score2);

        JugadorActual = (JugadorActual == NEGRA ? BLANCA : NEGRA);

    }while(fichasEnTablero < 64 && turnosSinMov < 2);
    /* Una condición de paro es que se terminen los espacios, otra es que el número de movimientos sea 0*/

    ImprimeJuegoTerminado();

    //Se manda a la pantalla de jugar de nuevo

    if (score1 > score2) return JugarDeNuevo(NEGRA, nombreNegras);
    if (score1 < score2) return JugarDeNuevo(BLANCA, nombreBlancas);

    return JugarDeNuevo(VACIO, nombreNegras);


}

Posicion Facil(Movimiento Posibles[][9]){
    int total = 0, eleccion;
    Posicion posicion;

    for (int i = 1; i < 9; i++)
        for (int j = 1; j < 9; j++)
            if (Posibles[i][j].posible) total++;

    eleccion = rand()%total + 1;

    for (int i = 1; i < 9; i++)
        for (int j = 1; j < 9; j++)
            if (Posibles[i][j].posible){
                eleccion--;
                if (eleccion == 0){
                    posicion.ren = i;
                    posicion.col = j;
                    return posicion;
                }
            }

    return posicion;
}

Posicion Medio(Movimiento Posibles[][9]){
    int mayorPuntos = 0;
    Posicion posicion;

    for (int i = 1; i < 9; i++)
        for (int j = 1; j < 9; j++)
            if (Posibles[i][j].posible)
                if (Posibles[i][j].puntos > mayorPuntos){
                    mayorPuntos = Posibles[i][j].puntos;
                    posicion.ren = i;
                    posicion.col = j;
                }

    return posicion;
}


