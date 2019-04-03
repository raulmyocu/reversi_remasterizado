/*
Nombre: Reversi.cbp
Autores: Spaceteam
Fecha: 05 de mayo de 2018
Descripción:
*/
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <windows.h>

#include "ReconocimientoTeclado.h"
#include "TitulosMenu.h"
#include "ManejoConsola.h"
#include "FuncionesMenu.h"

int Menu();

using namespace std;

int main()
{
    int eleccion;

    EstableceColor(NEGRO, VERDECLARO);
    AjustaVentana(); //Ajusta el tamaño de la pantalla y el color
    CambiaCursor(APAGADO); //Oculta el cursor

    do{
        system("cls");
        srand(time(0));
        eleccion = Menu();

        switch(eleccion){
            case JUGAR:
                bool JuegaDeNuevo;
                do{
                    system("cls");
                    JuegaDeNuevo = Jugar();
                }while(JuegaDeNuevo);
                break;
            case INSTRUCCIONES:
                system("cls");
                Instrucciones();
                break;
            case CREDITOS:
                system("cls");
                Creditos();
                break;
            case SALIR:
                system("cls");
                ImprimeGracias();
                system("pause");
                break;
        }
    }while(eleccion != SALIR);

    return 0;
}

int Menu()
{
    int eleccion = JUGAR;
    char tecla = '\0';

    ImprimeTitulo(1); //Se imprimen los títulos

    Sleep(50);
    ImprimeJugar();
    Sleep(50);    ImprimeInstrucciones((ANCHOVENTANA - 61)/2,ALTOVENTANA / 2 + 7);    Sleep(50);    ImprimeCreditos((ANCHOVENTANA - 38)/2, ALTOVENTANA / 2 + 14);
    Sleep(50);
    ImprimeSalir();

    SubrayaMenu(eleccion, char(205));

    while(tecla != ENTER){
        tecla = getch();
        if(tecla == FLECHA_ARRIBA){
            eleccion--;
            if (eleccion < 0) eleccion += 4; //Se mantienen los límites del seleccionador
            SubrayaMenu(eleccion, char(205));
        }

        if(tecla == FLECHA_ABAJO){
            eleccion++;
            if (eleccion > 3) eleccion -= 4; //Se mantienen los límites del seleccionador
            SubrayaMenu(eleccion, char(205));
        }
    }

    return eleccion;
}

