/*
Nombre: TitulosMenu.cpp
Autores: Spaceteam
Fecha: 05 de mayo de 2018
Descripción:
*/

#include <iostream>
#include <windows.h>

#include "TitulosMenu.h"
#include "ManejoConsola.h"

using namespace std;

void SubrayaMenu(int eleccion, char c)
{
    static int eleccionAnterior = JUGAR;
    int xMedio = ANCHOVENTANA / 2;

    switch(eleccionAnterior){ //Se borra el subrayado anterior
        case JUGAR:
            gotoxy (xMedio - 14, ALTOVENTANA / 2 + 4);
            for(int i = 0; i < 27; i++) cout << ' ';
            break;
        case INSTRUCCIONES:
            gotoxy (xMedio - 31, ALTOVENTANA / 2 + 11);
            for(int i = 0; i < 61; i++) cout << ' ';
            break;
        case CREDITOS:
            gotoxy(xMedio - 19, ALTOVENTANA / 2 + 18);
            for (int i = 0; i < 37; i++) cout << ' ';
            break;
        case SALIR:
            gotoxy (xMedio - 12, ALTOVENTANA / 2 + 25);
            for(int i = 0; i < 24; i++) cout << ' ';
    }

    EstableceColor(NEGRO, BLANCO);

    switch(eleccion){
        case JUGAR:
            gotoxy (xMedio - 14, ALTOVENTANA / 2 + 4);
            for(int i = 0; i < 27; i++) cout << c;
            break;
        case INSTRUCCIONES:
            gotoxy (xMedio - 31, ALTOVENTANA / 2 + 11);
            for(int i = 0; i < 61; i++) cout << c;
            break;
        case CREDITOS:
            gotoxy(xMedio - 19, ALTOVENTANA / 2 + 18);
            for (int i = 0; i < 37; i++) cout << c;
            break;
        case SALIR:
            gotoxy (xMedio - 12, ALTOVENTANA / 2 + 25);
            for(int i = 0; i < 24; i++) cout << c;
    }

    Beep(440, 50);

    EstableceColor(NEGRO, VERDECLARO);

    eleccionAnterior = eleccion;
}

void ImprimeGracias(){
    cout << "   ___ ___    _   ___ ___   _   ___   ___  ___  ___   _   _ _____ ___ _    ___ ____  _   ___   ___ ___ _____ ___  \n";
    cout << "  / __| _ \\  /_\\ / __|_ _| /_\\ / __| | _ \\/ _ \\| _ \\ | | | |_   _|_ _| |  |_ _|_  / /_\\ | _ \\ | __/ __|_   _| __| \n";
    cout << " | (_ |   / / _ \\ (__ | | / _ \\\\__ \\ |  _/ (_) |   / | |_| | | |  | || |__ | | / / / _ \\|   / | _|\\__ \\ | | | _|  \n";
    cout << "  \\___|_|_\\/_/ \\_\\___|___/_/ \\_\\___/ |_|  \\___/|_|_\\  \\___/  |_| |___|____|___/___/_/ \\_\\_|_\\ |___|___/ |_| |___| \n";

    cout << "  ___  ___  ___ _______      ___   ___ ___   _    ___ ___ ___ ___   ___  ___  __   _____ ___ _   _ ___ \n";
    cout << " / __|/ _ \\| __|_   _\\ \\    / /_\\ | _ \\ __| | |  |_ _| _ ) _ \\ __| |   \\| __| \\ \\ / /_ _| _ \\ | | / __|\n";
    cout << " \\__ \\ (_) | _|  | |  \\ \\/\\/ / _ \\|   / _|  | |__ | || _ \\   / _|  | |) | _|   \\ V / | ||   / |_| \\__ \\\n";
    cout << " |___/\\___/|_|   |_|   \\_/\\_/_/ \\_\\_|_\\___| |____|___|___/_|_\\___| |___/|___|   \\_/ |___|_|_\\\\___/|___/\n\n\n\n";

}

void ImprimeTitulo(int t)
{
    int c = 61;
    int x = (ANCHOVENTANA - c) / 2, y = ALTOVENTANA / 4 - 3;
    bool blanco = false;

    char var1[] = "|      |  |       ||  | |  ||       ||      |  |       ||   |";
    char var2[] = "|   | ||  |       ||  | |  ||       ||   | ||  |       ||   |";
    char var3[] = "|   | ||  |   |    |       ||   |    |   | ||  | |      |   |";
    char var4[] = "|        ||       ||       ||       ||        ||       ||   |";
    char var5[] = "|   |  | ||   |     |     | |   |    |   |  | |      | ||   |";
    char var6[] = "|   |  | ||       |  |   |  |       ||   |  | ||       ||   |";

    gotoxy(x, y++);
    gotoxy(x, y++);
    for(int i = 0; i < c; i++){
        if (var1[i] == '|'){
            EstableceColor(blanco ? NEGRO : VERDECLARO, VERDECLARO);
            blanco = !blanco;
            cout << " ";
        }else{
            cout << var1[i];
        }
        Sleep(t);
    }
    gotoxy(x, y++);
    for(int i = 0; i < c; i++){
        if (var2[i] == '|'){
            EstableceColor(blanco ? NEGRO : VERDECLARO, VERDECLARO);
            blanco = !blanco;
            cout << " ";
        }else{
            cout << var2[i];
        }
        Sleep(t);
    }
    gotoxy(x, y++);
    for(int i = 0; i < c; i++){
        if (var3[i] == '|'){
            EstableceColor(blanco ? NEGRO : VERDECLARO, VERDECLARO);
            blanco = !blanco;
            cout << " ";
        }else{
            cout << var3[i];
        }
        Sleep(t);
    }
    gotoxy(x, y++);
    for(int i = 0; i < c; i++){
        if (var4[i] == '|'){
            EstableceColor(blanco ? NEGRO : VERDECLARO, VERDECLARO);
            blanco = !blanco;
            cout << " ";
        }else{
            cout << var4[i];
        }
        Sleep(t);
    }
    gotoxy(x, y++);
    for(int i = 0; i < c; i++){
        if (var5[i] == '|'){
            EstableceColor(blanco ? NEGRO : VERDECLARO, VERDECLARO);
            blanco = !blanco;
            cout << " ";
        }else{
            cout << var5[i];
        }
        Sleep(t);
    }
    gotoxy(x, y++);
    for(int i = 0; i < c; i++){
        if (var6[i] == '|'){
            EstableceColor(blanco ? NEGRO : VERDECLARO, VERDECLARO);
            blanco = !blanco;
            cout << " ";
        }else{
            cout << var6[i];
        }
        Sleep(t);
    }
    gotoxy(x, y++);
}

void ImprimeJugar()
{
    int c = 28;
    int x = (ANCHOVENTANA - c)/2, y = ALTOVENTANA / 2;

    gotoxy(x, y++);
    cout << "    _ _   _  ___   _   ___  ";
    gotoxy(x, y++);
    cout << " _ | | | | |/ __| /_\\ | _ \\ ";
    gotoxy(x, y++);
    cout << "| || | |_| | (_ |/ _ \\|   / ";
    gotoxy(x, y++);
    cout << " \\__/ \\___/ \\___/_/ \\_\\_|_\\ ";
}

void ImprimeInstrucciones(int x, int y)
{


    gotoxy(x, y++);
    cout << " ___ _  _ ___ _____ ___ _   _  ___ ___ ___ ___  _  _ ___ ___ ";
    gotoxy(x, y++);
    cout << "|_ _| \\| / __|_   _| _ \\ | | |/ __/ __|_ _/ _ \\| \\| | __/ __|";
    gotoxy(x, y++);
    cout << " | || .` \\__ \\ | | |   / |_| | (_| (__ | | (_) | .` | _|\\__ \\";
    gotoxy(x, y++);
    cout << "|___|_|\\_|___/ |_| |_|_\\\\___/ \\___\\___|___\\___/|_|\\_|___|___/";
}

void ImprimeCreditos(int x, int y)
{

    gotoxy(x, y++);
    cout << "  ___ ___ ___ ___ ___ _____ ___  ___    ";
    gotoxy(x, y++);
    cout << " / __| _ \\ __|   \\_ _|_   _/ _ \\/ __|";
    gotoxy(x, y++);
    cout << "| (__|   / _|| |) | |  | || (_) \\__ \\ ";
    gotoxy(x, y++);
    cout << " \\___|_|_\\___|___/___| |_| \\___/|___/";
}

void ImprimeSalir()
{
    int c = 24;
    int x = (ANCHOVENTANA - c)/2, y = ALTOVENTANA / 2 + 21;

    gotoxy(x, y++);
    cout << " ___   _   _    ___ ___ ";
    gotoxy(x, y++);
    cout << "/ __| /_\\ | |  |_ _| _ \\";
    gotoxy(x, y++);
    cout << "\\__ \\/ _ \\| |__ | ||   /";
    gotoxy(x, y++);
    cout << "|___/_/ \\_\\____|___|_|_\\";
}
