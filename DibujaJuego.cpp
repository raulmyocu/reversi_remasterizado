/*
Nombre: DibujaJuego.cpp
Autores: Spaceteam
Fecha: 05 de mayo de 2018
Descripción:
*/
#include <iostream>
#include <windows.h>

#include "ManejoConsola.h"
#include "DibujaJuego.h"

using namespace std;

void DibujaPantallaInicioJuego(){

    DibujaTablero();
    ImprimeScores(2, 2);

    ImprimeCuadroVerde((ANCHOVENTANA - 57) / 4 - 3, ALTOVENTANA / 2 - 1);
    ImprimeCuadroVerde(((ANCHOVENTANA + 57) / 2 + ANCHOVENTANA) / 2 - 3, ALTOVENTANA / 2 - 1);

    DibujaFicha((ANCHOVENTANA - 57) / 4 - 2, ALTOVENTANA / 2, NEGRO);
    DibujaFicha(((ANCHOVENTANA + 57) / 2 + ANCHOVENTANA) / 2 - 2, ALTOVENTANA / 2, BLANCO);
}

void DibujaNombres(char nombre1[], char nombre2[]){
    int x = ((ANCHOVENTANA - 57) / 2 - 24) / 2, y = 3*(ALTOVENTANA)/8;

    ImprimeMarcoSimple(x, y, 3, 24);
    gotoxy(x + 2, y + 1);

    EstableceColor(NEGRO, BLANCO);
    cout << nombre1;
    EstableceColor(NEGRO, VERDECLARO);

    x = ((ANCHOVENTANA + 57) / 2 + ANCHOVENTANA - 24) / 2;

    ImprimeMarcoSimple(x, y, 3, 24);
    gotoxy(x + 2, y + 1);

    EstableceColor(NEGRO, BLANCO);
    cout << nombre2;
    EstableceColor(NEGRO, VERDECLARO);
}

void ImprimeCuadroVerde(int x, int y){
    EstableceColor(VERDE, VERDECLARO);
    for(int i = 0; i < 6; i++){
        gotoxy(x, y++);
        cout << "        ";
    }
    EstableceColor(NEGRO, VERDECLARO);
}

void DibujaFicha(int x, int y, miColor color)
{
    int t = 5;

    gotoxy(x, y++);
    EstableceColor(miColor(VERDE), miColor(color));
    cout << " " << char (220);
    EstableceColor(miColor(color), miColor(color));
    cout << "  ";
    EstableceColor(miColor(VERDE), miColor(color));
    cout << char (220);
    Sleep(t);
    gotoxy(x, y++);
    EstableceColor(miColor(color), miColor(color));
    cout << "      ";
    EstableceColor(miColor(VERDE), miColor(color));

    Sleep(t);
    gotoxy(x, y++);
    EstableceColor(miColor(color), miColor(color));
    cout << "      ";
    EstableceColor(miColor(VERDE), miColor(color));

    Sleep(t);
    gotoxy(x, y++);
    cout << " ";
    cout << char (223);
    EstableceColor(miColor(color), miColor(color));
    cout << "__";
    EstableceColor(miColor(VERDE), miColor(color));
    cout << char (223);
    EstableceColor(miColor(NEGRO), miColor(VERDECLARO));
    Sleep(t);
}

void DibujaTablero(){

    enum simSimple{ESD = 191, EII, EID = 217, ESI, EH = 196, EV = 179};

    int x = (ANCHOVENTANA - 57) / 2, y =(ALTOVENTANA - 40) / 2;

    EstableceColor(VERDE, BLANCO);

    gotoxy(x, y);

    cout << char(ESI);
    for(int j = 0; j < 8; j++){
        for (int i = 0; i < 6; i++) cout << char(EH);
        cout << char(194); //Cruz sin arriba
    }
    cout << '\b' << char(ESD);
    gotoxy(x, ++y);

    for(int k = 0; k < 7; k++){
        for(int j = 0; j < 4; j++){
            cout << char(EV);
            for (int i = 0; i < 8; i++) cout << "      " << char(EV);
            gotoxy(x, ++y);
        }

        cout << char(195); //Cruz sin izq
        for(int j = 0; j < 8; j++){
            for (int i = 0; i < 6; i++) cout << char(EH);
            cout << char(197); //Cruz
        }
        cout << '\b' << char(180); //Cruz sin derecha

        gotoxy(x, ++y);
    }

    for(int j = 0; j < 4; j++){
        cout << char(EV);
        for (int i = 0; i < 8; i++) cout << "      " << char(EV);
        gotoxy(x, ++y);
    }

    cout << char(EII);
    for(int j = 0; j < 8; j++){
        for (int i = 0; i < 6; i++) cout << char(EH);
        cout << char(193); //Cruz sin abajo
    }
    cout << '\b' << char(EID);
}

void ResaltaCasilla(int col, int ren, miColor color){
    static int renAnt = 4, colAnt = 4;

    EstableceColor(miColor(VERDE), miColor(BLANCO));
    ImprimeCasilla(colAnt, renAnt);
    EstableceColor(miColor(color), miColor(color));
    ImprimeCasilla(col, ren);
    EstableceColor(miColor(NEGRO), miColor(BLANCO));

    renAnt = ren;
    colAnt = col;
}

void ImprimeMovimientoIncorrecto(){
    int x = (ANCHOVENTANA - 23) / 2;
    int y = (ALTOVENTANA - 40) / 4;
    EstableceColor(miColor(ROJOCLARO), miColor(NEGRO));

    gotoxy(x, y);
    cout << " MOVIMIENTO INCORRECTO ";
    Beep(200, 100);
    Sleep(10);
    Beep(200, 100);
    Sleep(400);

    EstableceColor(miColor(NEGRO), miColor(VERDECLARO));

    gotoxy(x, y);
    cout << "                       ";
}

void ImprimeSaltoTurno(espacioCasilla Jugador){
    int x = (ANCHOVENTANA - 35) / 2;
    int y = (ALTOVENTANA - 40) / 4;
    EstableceColor(miColor(AZULCLARO), miColor(NEGRO));

    gotoxy(x, y);
    cout << (Jugador == BLANCA ? " BLANCAS" : " NEGRAS");
    cout << " NO PUEDEN REALIZAR MOVIMIENTOS ";
    Beep(320, 100);
    Sleep(10);
    Beep(320, 100);
    Sleep(1800);

    EstableceColor(miColor(NEGRO), miColor(VERDECLARO));

    gotoxy(x, y);
    cout << "                                          ";
}

void ImprimeJuegoTerminado(){
    int x = (ANCHOVENTANA - 23) / 2;
    int y = (ALTOVENTANA - 40) / 4;
    EstableceColor(miColor(AZULCLARO), miColor(NEGRO));

    gotoxy(x, y);
    cout << " EL JUEGO HA TERMINADO ";

    Beep(261, 800);
    Beep(330, 800);
    Beep(392, 1600);

    EstableceColor(miColor(NEGRO), miColor(VERDECLARO));

    gotoxy(x, y);
    cout << "                       ";

}

void ImprimeCasilla(int col, int ren){

    int x = ((ANCHOVENTANA - 57) / 2) + ((col - 1) * 7), y = ((ALTOVENTANA - 40) / 2) + ((ren - 1) * 5);

    gotoxy(x, y++);

    if (ren > 1){
        if (col > 1) cout << char(CRUZ);
        else cout << char(CSI);
    }else{
        if (col > 1) cout << char(CSA);
        else cout << char(ESI);
    }

    for(int i = 0; i < 6; i++) cout << char(EH);

    if (ren > 1){
        if (col < 8) cout << char(CRUZ);
        else cout << char(CSD);
    }else{
        if (col < 8) cout << char(CSA);
        else cout << char(ESD);
    }

    for(int i = 0; i < 5; i++){
        gotoxy(x += 7, y);
        cout << char(EV);
        gotoxy(x -= 7, y++);
        cout << char(EV);
    }
    cout << '\b';
    if (ren < 8){
        if (col > 1) cout << char(CRUZ);
        else cout << char(CSI);
    }else{
        if (col > 1) cout << char(CSAB);
        else cout << char(EII);
    }

    for(int i = 0; i < 6; i++) cout << char(EH);

    if (ren < 8){
        if (col < 8) cout << char(CRUZ);
        else cout << char(CSD);
    }else{
        if (col < 8) cout << char(CSAB);
        else cout << char(EID);
    }
}

void ImprimirNumero(int num, int x, int y){
     string L1, L2, L3, L4;

    switch(num){
        case 1:
            L1 = "   _ ";
            L2 = "  | |";
            L3 = "  | |";
            L4 = "  |_|";
            break;
        case 2:
            L1 = " ___ ";
            L2 = "|_  |";
            L3 = "|  _|";
            L4 = "|___|";
            break;
        case 3:
            L1 = " ___ ";
            L2 = "|_  |";
            L3 = "|_  |";
            L4 = "|___|";
            break;
        case 4:
            L1 = " ___ ";
            L2 = "| | |";
            L3 = "|_  |";
            L4 = "  |_|";
            break;
        case 5:
            L1 = " ___ ";
            L2 = "|  _|";
            L3 = "|_  |";
            L4 = "|___|";
            break;
        case 6:
            L1 = " ___ ";
            L2 = "|  _|";
            L3 = "| . |";
            L4 = "|___|";
            break;
        case 7:
            L1 = " ___ ";
            L2 = "|_  |";
            L3 = "  | |";
            L4 = "  |_|";
            break;
        case 8:
            L1 = " ___ ";
            L2 = "| . |";
            L3 = "| . |";
            L4 = "|___|";
            break;
        case 9:
            L1 = " ___ ";
            L2 = "| . |";
            L3 = "|_  |";
            L4 = "|___|";
            break;
        case 0:
            L1 = " ___ ";
            L2 = "|   |";
            L3 = "| | |";
            L4 = "|___|";
            break;
    }

    gotoxy(x, y++);
    cout << L1;
    gotoxy(x, y++);
    cout << L2;
    gotoxy(x, y++);
    cout << L3;
    gotoxy(x, y);
    cout << L4;

}

void ImprimeJugador1(int x, int y)
{
    EstableceColor(NEGRO, BLANCO);
    gotoxy(x, y++);
    cout << "     _                   _           _ ";
    gotoxy(x, y++);
    cout << "  _ | |_  _ __ _ __ _ __| |___ _ _  / |";
    gotoxy(x, y++);
    cout << " | || | || / _` / _` / _` / _ \\ \'_| | |";
    gotoxy(x, y++);
    cout << "  \\__/ \\_,_\\__, \\__,_\\__,_\\___/_|   |_|";
    gotoxy(x, y++);
    cout << "           |___/                       ";
    EstableceColor(NEGRO, VERDECLARO);
}

void ImprimeJugador2(int x, int y)
{
    EstableceColor(NEGRO, BLANCO);
    gotoxy(x, y++);
    cout << "     _                   _           ___ ";
    gotoxy(x, y++);
    cout << "  _ | |_  _ __ _ __ _ __| |___ _ _  |_  )";;
    gotoxy(x, y++);
    cout << " | || | || / _` / _` / _` / _ \\ \'_|  / / ";
    gotoxy(x, y++);
    cout << "  \\__/ \\_,_\\__, \\__,_\\__,_\\___/_|   /___|";
    gotoxy(x, y++);
    cout << "           |___/                         ";
    EstableceColor(NEGRO, VERDECLARO);
}

void ImprimeMarcoSimple(int x, int y, int alto, int ancho){
    gotoxy(x, y++);
    cout << char(ESI);
    for(int i = 0; i < ancho - 2; i++) cout << char(EH);
    cout << char(ESD);

    for(int i = 0; i < alto - 2; i++) {
        gotoxy(x, y);
        cout << char(EV);
        gotoxy(x += ancho - 1, y++);
        cout << char(EV);
        x -= ancho - 1;
    }
    gotoxy(x, y);

    cout << char(EII);
    for(int i = 0; i < ancho - 2; i++) cout << char(EH);
    cout << char(EID);

}

void ImprimeFinDelJuego()
{
    int x = (ANCHOVENTANA - 59)/2, y = ALTOVENTANA / 5;

    gotoxy(x, y++);
    cout << "  ___ ___ _  _   ___  ___ _         _ _   _ ___ ___  ___  ";
    gotoxy(x, y++);
    cout << " | __|_ _| \\| | |   \\| __| |     _ | | | | | __/ __|/ _ \\ ";
    gotoxy(x, y++);
    cout << " | _| | || .` | | |) | _|| |__  | || | |_| | _| (_ | (_) |";
    gotoxy(x, y++);
    cout << " |_| |___|_|\\_| |___/|___|____|  \\__/ \\___/|___\\___|\\___/ ";
}

void ImprimeGana()
{
    int x = (ANCHOVENTANA - 26)/2, y = ALTOVENTANA / 4 + 5;

    gotoxy(x, y++);
    cout << "   ___                  _ ";
    gotoxy(x, y++);
    cout << "  / __|__ _ _ _  __ _  (_)";
    gotoxy(x, y++);
    cout << " | (_ / _` | \' \\/ _` |  _ ";
    gotoxy(x, y++);
    cout << "  \\___\\__,_|_||_\\__,_| (_)";
}


void ImprimeEmpate()
{
    int x = (ANCHOVENTANA - 31)/2, y = ALTOVENTANA / 4 + 5;

    gotoxy(x, y++);
    cout << "  ___                  _       ";
    gotoxy(x, y++);
    cout << " | __|_ __  _ __  __ _| |_ ___ ";
    gotoxy(x, y++);
    cout << " | _|| \'  \\| \'_ \\/ _` |  _/ -_)";
    gotoxy(x, y++);
    cout << " |___|_|_|_| .__/\\__,_|\\__\\___|";
    gotoxy(x, y++);
    cout << "           |_|                 ";
}

void ImprimeVolverAJugar()
{
    int x = (ANCHOVENTANA - 68)/2, y = ALTOVENTANA / 2 + 5;

    gotoxy(x, y++);
    cout << "   _   __   __   _                        _                      ___ ";
    gotoxy(x, y++);
    cout << "  (_)  \\ \\ / /__| |_ _____ _ _   __ _    (_)_  _ __ _ __ _ _ _  |__ \\";
    gotoxy(x, y++);
    cout << " / /_   \\ V / _ \\ \\ V / -_) \'_| / _` |   | | || / _` / _` | \'_|   /_/";
    gotoxy(x, y++);
    cout << " \\___|   \\_/\\___/_|\\_/\\___|_|   \\__,_|  _/ |\\_,_\\__, \\__,_|_|    (_) ";
    gotoxy(x, y++);
    cout << "                                       |__/     |___/                ";
}

void ImprimeSi()
{
    int x = (ANCHOVENTANA - 8)/3, y = ALTOVENTANA / 2 + 11;

    gotoxy(x, y++);
    cout << "  ___ _ ";
    gotoxy(x, y++);
    cout << " / __(_)";
    gotoxy(x, y++);
    cout << " \\__ \\ |";
    gotoxy(x, y++);
    cout << " |___/_|";
}

void ImprimeNo()
{
    int x = 2*(ANCHOVENTANA - 11)/3, y = ALTOVENTANA / 2 + 11;

    gotoxy(x, y++);
    cout << "  _  _     ";
    gotoxy(x, y++);
    cout << " | \\| |___ ";
    gotoxy(x, y++);
    cout << " | .` / _ \\";
    gotoxy(x, y++);
    cout << " |_|\\_\\___/";
}

void SubrayaFinDelJuego(bool eleccion, char c)
{
    static bool eleccionAnterior = false;

    if(eleccionAnterior){
        gotoxy ((ANCHOVENTANA - 8)/3 + 1, ALTOVENTANA / 2 + 15);
        for(int i = 0; i < 7; i++) cout << ' ';
    }else{
        gotoxy (2*(ANCHOVENTANA - 11)/3 + 1, ALTOVENTANA / 2 + 15);
        for(int i = 0; i < 10; i++) cout << ' ';
    }

    EstableceColor(NEGRO, BLANCO);

    if(eleccion){
        gotoxy ((ANCHOVENTANA - 8)/3 + 1, ALTOVENTANA / 2 + 15);
        for(int i = 0; i < 7; i++) cout << c;
    }else{
        gotoxy (2*(ANCHOVENTANA - 11)/3 + 1, ALTOVENTANA / 2 + 15);
        for(int i = 0; i < 10; i++) cout << c;
    }

    Beep(440, 50);
    EstableceColor(NEGRO, VERDECLARO);

    eleccionAnterior = eleccion;

}

void MostrarHints(Movimiento PosiblesMovimientos[][9], char c){
    EstableceColor(VERDE, ROJO);

    for(int i = 1; i < 9; i++)
        for(int j = 1; j < 9; j++){
            if(PosiblesMovimientos[i][j].posible){
                gotoxy((j - 1) * 7 + ((ANCHOVENTANA - 57) / 2) + 1, (i - 1) * 5 + ((ALTOVENTANA - 40) / 2) + 1);
                cout << c;
            }
        }

    EstableceColor(NEGRO, VERDECLARO);
}

void ImprimeTurnoActual(char nombre[]){
    static int longitudCadena = 0;
    gotoxy((ANCHOVENTANA - longitudCadena) / 2, (15 * ALTOVENTANA) / 16 + 1);
    for (int i = 0; i < longitudCadena; ++i) cout << " ";
    longitudCadena = 0;

    gotoxy((ANCHOVENTANA - 13) / 2, (15 * ALTOVENTANA) / 16);
    cout << "TURNO ACTUAL:";
    while (nombre[longitudCadena]!='\0') longitudCadena++;
    gotoxy((ANCHOVENTANA - longitudCadena) / 2, (15 * ALTOVENTANA) / 16 + 1);

    EstableceColor(NEGRO, VERDECLARO);
    cout << nombre;
    EstableceColor(NEGRO, VERDECLARO);
}
