/*
Nombre: MenusAjustes.cpp
Autores: Spaceteam
Fecha: 06 de Junio de 2018
Descripción:
*/

#include "MenusAjustes.h"
#include "ManejoConsola.h"
#include "ReconocimientoTeclado.h"

#include <windows.h>
#include <conio.h>

#include <iostream>

using namespace std;

void SubrayaModo(int eleccion, char c)
{
    static int eleccionAnterior = SOLO;
    int xMedio = ANCHOVENTANA / 2;

    switch(eleccionAnterior){ //Se borra el subrayado anterior
        case SOLO:
            gotoxy (xMedio - 11, ALTOVENTANA / 2 - 4);
            for(int i = 0; i < 21; i++) cout << ' ';
            break;
        case VS:
            gotoxy (xMedio - 6, ALTOVENTANA / 2 + 8);
            for(int i = 0; i < 11; i++) cout << ' ';
    }

    EstableceColor(NEGRO, BLANCO);

    switch(eleccion){
        case SOLO:
            gotoxy (xMedio - 11, ALTOVENTANA / 2 - 4);
            for(int i = 0; i < 21; i++) cout << c;
            break;
        case VS:
            gotoxy (xMedio - 6, ALTOVENTANA / 2 + 8);
            for(int i = 0; i < 11; i++) cout << c;
    }

    Beep(440, 50);

    EstableceColor(NEGRO, VERDECLARO);

    eleccionAnterior = eleccion;
}

void ImprimeSolo(){
    int c = 21;
    int x = (ANCHOVENTANA - c)/2, y = ALTOVENTANA / 2 - 8;

    gotoxy(x, y++);
    cout << " ___  ___  _    ___";
    gotoxy(x, y++);
    cout << "/ __|/ _ \\| |  / _ \\";
    gotoxy(x, y++);
    cout << "\\__ \\ (_) | |_| (_) |";
    gotoxy(x, y++);
    cout << "|___/\\___/|____\\___/";

}

void ImprimeVs(){

    int c = 11;
    int x = (ANCHOVENTANA - c)/2, y = ALTOVENTANA / 2 + 4;

    gotoxy(x, y++);
    cout << "__   _____";
    gotoxy(x, y++);
    cout << "\\ \\ / / __|";
    gotoxy(x, y++);
    cout << " \\ V /\\__ \\";
    gotoxy(x, y++);
    cout << "  \\_/ |___/";

}

int EligeModo(){

    int eleccion = SOLO;
    char tecla = '\0';

    ImprimeSolo();
    Sleep(50);    ImprimeVs();    Sleep(50);

    SubrayaModo(eleccion, char(205));

    while(tecla != ENTER){
        tecla = getch();
        if(tecla == FLECHA_ARRIBA){
            eleccion--;
            if (eleccion < 0) eleccion += 2; //Se mantienen los límites del seleccionador
            SubrayaModo(eleccion, char(205));
        }

        if(tecla == FLECHA_ABAJO){
            eleccion++;
            if (eleccion > 1) eleccion -= 2; //Se mantienen los límites del seleccionador
            SubrayaModo(eleccion, char(205));
        }
    }

    system("cls");

    return eleccion;
}

void SubrayaDificultad(int eleccion, char c)
{
    static int eleccionAnterior = SOLO;
    int xMedio = ANCHOVENTANA / 2;

    switch(eleccionAnterior){ //Se borra el subrayado anterior
        case FACIL:
            gotoxy (xMedio - 11, ALTOVENTANA / 2 - 4);
            for(int i = 0; i < 22; i++) cout << ' ';
            break;
        case MEDIO:
            gotoxy (xMedio - 13, ALTOVENTANA / 2 + 2);
            for(int i = 0; i < 25; i++) cout << ' ';
            break;
        case DIFICIL:
            gotoxy (xMedio - 15, ALTOVENTANA / 2 + 8);
            for(int i = 0; i < 30; i++) cout << ' ';
    }

    EstableceColor(NEGRO, BLANCO);

    switch(eleccion){
        case FACIL:
            gotoxy (xMedio - 11, ALTOVENTANA / 2 - 4);
            for(int i = 0; i < 22; i++) cout << c;
            break;
        case MEDIO:
            gotoxy (xMedio - 13, ALTOVENTANA / 2 + 2);
            for(int i = 0; i < 25; i++) cout << c;
            break;
        case DIFICIL:
            gotoxy (xMedio - 15, ALTOVENTANA / 2 + 8);
            for(int i = 0; i < 30; i++) cout << c;
    }

    Beep(440, 50);

    EstableceColor(NEGRO, VERDECLARO);

    eleccionAnterior = eleccion;
}

void ImprimeFacil(){

    int c = 22;
    int x = (ANCHOVENTANA - c)/2, y = ALTOVENTANA / 2 - 8;

    gotoxy(x, y++);
    cout << " ___ _   ___ ___ _";
    gotoxy(x, y++);
    cout << "| __/_\\ / __|_ _| |";
    gotoxy(x, y++);
    cout << "| _/ _ \\ (__ | || |__";
    gotoxy(x, y++);
    cout << "|_/_/ \\_\\___|___|____|";
}

void ImprimeMedio(){

    int c = 25;
    int x = (ANCHOVENTANA - c)/2, y = ALTOVENTANA / 2 - 2;

    gotoxy(x, y++);
    cout << " __  __ ___ ___ ___ ___";
    gotoxy(x, y++);
    cout << "|  \\/  | __|   \\_ _/ _ \\";
    gotoxy(x, y++);
    cout << "| |\\/| | _|| |) | | (_) |";
    gotoxy(x, y++);
    cout << "|_|  |_|___|___/___\\___/";
}

void ImprimeDificil(){

    int c = 30;
    int x = (ANCHOVENTANA - c)/2, y = ALTOVENTANA / 2 + 4;


    gotoxy(x, y++);
    cout << " ___ ___ ___ ___ ___ ___ _";
    gotoxy(x, y++);
    cout << "|   \\_ _| __|_ _/ __|_ _| |";
    gotoxy(x, y++);
    cout << "| |) | || _| | | (__ | || |__";
    gotoxy(x, y++);
    cout << "|___/___|_| |___\\___|___|____|";

}

int EligeDificultad(){

    int eleccion = SOLO;
    char tecla = '\0';

    ImprimeFacil();
    Sleep(50);
    ImprimeMedio();
    Sleep(50);
    ImprimeDificil();
    SubrayaDificultad(eleccion, char(205));

    while(tecla != ENTER){
        tecla = getch();
        if(tecla == FLECHA_ARRIBA){
            eleccion--;
            if (eleccion < 0) eleccion += 3; //Se mantienen los límites del seleccionador
            SubrayaDificultad(eleccion, char(205));
        }

        if(tecla == FLECHA_ABAJO){
            eleccion++;
            if (eleccion > 2) eleccion -= 3; //Se mantienen los límites del seleccionador
            SubrayaDificultad(eleccion, char(205));
        }
    }

    system("cls");

    return eleccion;
}
