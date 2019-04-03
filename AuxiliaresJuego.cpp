/*
Nombre: AuxiliaresJuego.cpp
Autores: Spaceteam
Fecha: 05 de mayo de 2018
Descripción:
*/

#include <iostream>
#include <conio.h>
#include <windows.h>

#include "ManejoConsola.h"
#include "DibujaJuego.h"
#include "AuxiliaresJuego.h"
#include "ReconocimientoTeclado.h"

using namespace std;

void RevisaMovimiento(espacioCasilla Tab[][10], Movimiento PosiblesMovimientos[][9], espacioCasilla Jugador, int ren, int col){

    PosiblesMovimientos[ren][col].posible = false; //se inicializa como false
    PosiblesMovimientos[ren][col].numDirecciones = 0;
    PosiblesMovimientos[ren][col].puntos = 0;

    if(Tab[ren][col] != VACIO) return;

    espacioCasilla Oponente = (Jugador == BLANCA ? NEGRA : BLANCA);
    int casillasVolteadas;



    for(int i = -1; i < 2; i++)
        for(int j = -1; j < 2; (i == 0 ? j += 2 : j++)){ //Saltando el caso i = 0, j = 0, considerando las 8 direcciones
            casillasVolteadas = 0;
            int dI = i, dJ = j;
            //Se avanza en la misma dirección mientras haya casillas del oponente
            while(Tab[ren + dI][col + dJ] == Oponente && ren + dI > 0 && ren + dI < 9 && col + dJ > 0 && col + dJ < 9){
                casillasVolteadas++;
                dI += i;
                dJ += j;
            }
            //Si la casilla de al final es del jugador, y avanzó más de una casilla
            if(Tab[ren + dI][col + dJ] == Jugador && (dI != i || dJ != j)){
                PosiblesMovimientos[ren][col].posible = true; //Se hace verdadera la primera vez que entra a este condicional

                int indice = PosiblesMovimientos[ren][col].numDirecciones;

                PosiblesMovimientos[ren][col].distancias[indice] = casillasVolteadas;
                PosiblesMovimientos[ren][col].puntos += casillasVolteadas;

                PosiblesMovimientos[ren][col].direcciones[indice].i = i;
                PosiblesMovimientos[ren][col].direcciones[indice].j = j;

                PosiblesMovimientos[ren][col].numDirecciones++;
            }
        }

}

void RealizaMovimiento(espacioCasilla Tab[][10], Movimiento PosiblesMovimientos[][9], Posicion posicion, espacioCasilla Jugador, int &scoreJugador, int &scoreOponente){

    int ren = posicion.ren, col = posicion.col;
    ColocarFicha(col, ren, (Jugador == NEGRA ? NEGRO : BLANCO));
    scoreJugador++;
    Tab[ren][col] = Jugador;
    Beep(440, 30);
    Beep(660, 50);
    Sleep(70);

    for(int c = 0; c < PosiblesMovimientos[ren][col].numDirecciones; c++){

        int dRen = 0, dCol = 0;
        for(int d = 0; d < PosiblesMovimientos[ren][col].distancias[c]; d++){
            dRen += PosiblesMovimientos[ren][col].direcciones[c].i;
            dCol += PosiblesMovimientos[ren][col].direcciones[c].j;

            Tab[ren + dRen][col + dCol] = Jugador;

            Beep(440, 30);
            Beep(660, 50);
            ColocarFicha(col + dCol, ren + dRen, (Jugador == NEGRA ? NEGRO : BLANCO));
            Sleep(70);

            scoreJugador++;
            scoreOponente--;
        }
    }
}

void ColocarFicha(int x, int y, miColor color){
    DibujaFicha((x - 1) * 7 + ((ANCHOVENTANA - 57) / 2) + 1, (y - 1) * 5 + ((ALTOVENTANA - 40) / 2) + 1 , miColor(color));
}

void InicializaTablero(espacioCasilla Tab[][10]){
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            Tab[i][j] = VACIO;

    Tab[4][4] = BLANCA;
    Tab[4][5] = NEGRA;
    Tab[5][4] = NEGRA;
    Tab[5][5] = BLANCA;
}

void ImprimeTablero(espacioCasilla Tab[][10]){
    for (int i = 1; i < 9; i++)
        for (int j = 1; j < 9; j++)
            if (Tab[i][j] == BLANCA) ColocarFicha(i, j, BLANCO);
            else if (Tab[i][j] == NEGRA) ColocarFicha(i, j, NEGRO);
}

Posicion CapturaMovimiento(miColor color){
    char tecla = '\0';
    int x = 4, y = 4;
    Posicion posicion;

    ResaltaCasilla(x, y, color);

    while(tecla != ENTER)
        if (kbhit()){
            tecla = getch();

            if(tecla == FLECHA_ARRIBA){
                y--;
                if (y < 1) y += 8;
                ResaltaCasilla(x, y, color);
            }
            if(tecla == FLECHA_ABAJO){
                y++;
                if (y > 8) y -= 8;
                ResaltaCasilla(x, y, color);
            }
            if(tecla == FLECHA_IZQ){
                x--;
                if (x < 1) x += 8;
                ResaltaCasilla(x, y, color);
            }
            if(tecla == FLECHA_DER){
                x++;
                if (x > 8) x -= 8;
                ResaltaCasilla(x, y, color);
            }
        }

    posicion.col = x;
    posicion.ren = y;

    return posicion;
}

void ImprimeScores(int score1, int score2){
    int x = ((ANCHOVENTANA - 57) / 2) / 2 - 5;
    int y = (ALTOVENTANA  / 4);
    int dig1 = score1 / 10;
    int dig0 = score1 % 10;

    gotoxy(x,y);

    ImprimeJugador1(((ANCHOVENTANA - 57) / 2 - 39) / 2, y - 6);    ImprimirNumero(dig1, x, y);
    ImprimirNumero(dig0, x + 5, y);

    x = ((ANCHOVENTANA + 57) / 2 + ANCHOVENTANA) / 2 - 5;
    dig1 = score2 / 10;
    dig0 = score2 % 10;

    gotoxy(x,y);

    ImprimeJugador2(((ANCHOVENTANA + 57) / 2 + ANCHOVENTANA - 39) / 2, y - 6);
    ImprimirNumero(dig1, x, y);
    ImprimirNumero(dig0, x + 5, y);

}

void CapturaNombre1(char nombre1[]){
    CambiaCursor(ENCENDIDO);

    char c = '\0';

    ImprimeJugador1((ANCHOVENTANA - 39)/2, 10);
    ImprimeMarcoSimple((ANCHOVENTANA - 24)/2, 20, 3, 24);
    gotoxy((ANCHOVENTANA - 22)/2 + 1, 21);

    int i = 0;

    EstableceColor(NEGRO, BLANCO);
    while(c != ENTER || i == 0){
        c = getch();
        if(i < 20 && c != BACKSPACE && c != TAB){
            nombre1[i] = c;
            cout << c;
            i++;
        }
        if (c == BACKSPACE && i != 0){
            cout << "\b \b";
            i--;
        }
    }
    nombre1[i] = '\0';
    EstableceColor(NEGRO, VERDECLARO);

    CambiaCursor(APAGADO);

}

void CapturaNombres(char nombre1[], char nombre2[]){

    CambiaCursor(ENCENDIDO);

    char c = '\0';

    ImprimeJugador1((ANCHOVENTANA - 39)/2, 10);
    ImprimeMarcoSimple((ANCHOVENTANA - 24)/2, 20, 3, 24);
    gotoxy((ANCHOVENTANA - 22)/2 + 1, 21);

    int i = 0;

    EstableceColor(NEGRO, BLANCO);
    while(c != ENTER || i == 0){
        c = getch();
        if(i < 20 && c != BACKSPACE && c != TAB){
            nombre1[i] = c;
            cout << c;
            i++;
        }
        if (c == BACKSPACE && i != 0){
            cout << "\b \b";
            i--;
        }
    }
    nombre1[i] = '\0';
    EstableceColor(NEGRO, VERDECLARO);


    ImprimeJugador2((ANCHOVENTANA - 39)/2, 30);
    ImprimeMarcoSimple((ANCHOVENTANA - 24)/2, 40, 3, 24);
    gotoxy((ANCHOVENTANA - 22)/2 + 1, 41);

    i = 0;
    c = '\0';

    EstableceColor(NEGRO, BLANCO);
    while(c != ENTER || i == 0){
        c = getch();
        if(i < 20 && c != BACKSPACE && c != TAB){
            nombre2[i] = c;
            cout << c;
            i++;
        }
        if (c == BACKSPACE && i != 0){
            cout << "\b \b";
            i--;
        }
    }
    nombre2[i] = '\0';
    EstableceColor(NEGRO, VERDECLARO);

    CambiaCursor(APAGADO);
}

bool JugarDeNuevo(espacioCasilla Resultado, char nombre[]){

    system("cls");
    char tecla = '\0';
    bool eleccion = true;

    ImprimeFinDelJuego();
    int longitudCadena = 0;

    switch (Resultado){
        case NEGRA:
            ImprimeGana();
            ImprimeJugador1((ANCHOVENTANA - 39)/2, ALTOVENTANA / 4 + 9);
            ImprimeMarcoSimple((ANCHOVENTANA - 24)/2, ALTOVENTANA / 4 + 15, 3, 24);

            while (nombre[longitudCadena]!='\0') longitudCadena++;
            gotoxy((ANCHOVENTANA - longitudCadena)/2, ALTOVENTANA / 4 + 16);

            EstableceColor(NEGRO, BLANCO);
            cout << nombre;
            EstableceColor(NEGRO, VERDECLARO);

            break;
        case BLANCA:
            ImprimeGana();
            ImprimeJugador2((ANCHOVENTANA - 41) / 2, ALTOVENTANA / 4 + 9);
            ImprimeMarcoSimple((ANCHOVENTANA - 24)/2, ALTOVENTANA / 4 + 15, 3, 24);

            while (nombre[longitudCadena]!='\0') longitudCadena++;
            gotoxy((ANCHOVENTANA - longitudCadena)/2, ALTOVENTANA / 4 + 16);

            EstableceColor(NEGRO, BLANCO);
            cout << nombre;
            EstableceColor(NEGRO, VERDECLARO);

            break;
        default:
            ImprimeEmpate();
    }

    ImprimeVolverAJugar();
    ImprimeSi();
    ImprimeNo();
    SubrayaFinDelJuego(eleccion, char(205));

     while(tecla != ENTER){
        if (kbhit()){
            tecla = getch();

            if(tecla == FLECHA_IZQ){
                eleccion = !eleccion;
                SubrayaFinDelJuego(eleccion, char(205));
            }

            if(tecla == FLECHA_DER){
                eleccion = !eleccion;
                SubrayaFinDelJuego(eleccion, char(205));
            }
        }
    }
    return eleccion;
}



