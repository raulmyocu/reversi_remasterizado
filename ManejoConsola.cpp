/*
Nombre: ManejoConsola.cpp
Autores: Spaceteam
Fecha: 05 de mayo de 2018
Descripción:
*/
#include <windows.h>
#include <cstdio>

#include "ManejoConsola.h"

void CambiaCursor(estadoCursor estado, modoCursor modo/* = NORMAL*/)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConCurInf;

    ConCurInf.dwSize = modo;
    ConCurInf.bVisible = estado;

    SetConsoleCursorInfo(hOut, &ConCurInf);
}

void AjustaVentana(){


    char str[60];
    sprintf(str, "mode con: cols=%d lines=%d", ANCHOVENTANA, ALTOVENTANA);
    system(str); //Enviamos la cadena con la instrucción a la consola

    EstableceColor(NEGRO, VERDECLARO);
}

void gotoxy(int x, int y)
{
    HANDLE handle = GetStdHandle (STD_OUTPUT_HANDLE);
    COORD coord = {short(x-1), short(y-1)};
    SetConsoleCursorPosition (handle, coord);
}

void EstableceColor(miColor colorFondo, miColor colorTexto)
{
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorFondo*16 + colorTexto);
}
