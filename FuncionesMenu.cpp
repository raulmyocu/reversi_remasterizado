/*
Nombre: FuncionesMenu.cpp
Autores: Spaceteam
Fecha: 05 de mayo de 2018
Descripción:
*/

#include <iostream>
#include <cstdlib>

#include "ManejoConsola.h"
#include "TitulosMenu.h"
#include "Juego.h"
#include "MenusAjustes.h"

using namespace std;

void Creditos(){

    ImprimeCreditos((ANCHOVENTANA - 38)/2, ALTOVENTANA / 8);
    gotoxy(1, ALTOVENTANA / 4);

    int x = (ANCHOVENTANA - 24)/ 2, y = (ALTOVENTANA - 18) / 2 - 5;

    y+=2;
    gotoxy(x, y++);
    cout << "PROYECTO FINAL \"REVERSI\"";

    x = (ANCHOVENTANA - 58)/ 2;
    y+=2;
    gotoxy(x, y++);

    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - ";

    y+=2;
    gotoxy(x, y++);

    cout << "Equipo: Spaceteam";

    y+=2;
    gotoxy(x, y++);

    cout << "Integrantes: ";

    y+=2;
    gotoxy(x, y++);

    cout << "   - Claudia Marian L\xA2pez Batriz";
    y+=2;
    gotoxy(x, y++);
    cout << "   - Ra\xA3l Octavio Murcia Yocupicio";
    y+=2;
    gotoxy(x, y++);
    cout << "   - Mar\xA1" << "a Ximena Sandoval Del Hoyo";
    y+=2;
    gotoxy(x, y++);
    cout << "   - Jes\xA3s Emanuel Vidal L\xA2pez";
    y+=2;
    gotoxy(x, y++);

    cout << "Versi\xA2n 2.54" << endl << endl;

    system("pause");
}

void Instrucciones(){
    ImprimeInstrucciones((ANCHOVENTANA - 61)/2, ALTOVENTANA / 8);

    gotoxy(1, ALTOVENTANA / 4);
    cout << "El objetivo de este juego es tener la mayor cantidad de fichas de tu color al final del juego" << endl << endl << endl;

    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl << endl << endl;

    cout << "-> Despl\xa0zate con los cursores y utiliza Enter para elegir la casilla donde se desea colocar la ficha." << endl << endl << endl;

    cout << "-> S\xA2lo puedes poner una ficha en el extremo de una hilera de fichas que tengan el color del contrincante" << endl << endl;
    cout << "    siempre y cuando al otro extremo de \x82sta haya una ficha de tu color." << endl << endl << endl;

    cout << "-> Si al poner una ficha, encierras una hilera de fichas del color contrario las fichas del color contrario" << endl << endl;
    cout << "    se convertir\xA0n a fichas de tu color esto puede ser verticalmente, horizontalmente o diagonalmente." << endl<< endl << endl;

    cout << "-> Si al poner una ficha, encierras m\xA0s de una hilera de fichas del color contrario, todas las hileras que se" << endl << endl;
    cout << "    encuentren encerradas se cambiar\xA0n a tu color." << endl << endl << endl;

    cout << "-> Si no es posible encerrar al menos una ficha, el jugador pasar\xA0 su turno sin incorporar ninguna ficha al " << endl << endl;
    cout << "    tablero." << endl << endl << endl;

    cout << "-> Si se realizan 3 movimientos incorrectos se despliegan las 'hints' representadas por un asterisco (*) " << endl << endl;
    cout << "    de color rojo en la esquina superior izquierda de las casillas en las que se puede hacer una jugada." << endl << endl << endl;

    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl << endl;

    cout << "El juego termina si se acaban las casillas del tablero o si ning\xA3n jugador puede incorporar una ficha al " << endl << endl;
    cout << "    tablero, siguiendo las reglas anteriores." << endl << endl << endl;

    system("pause");
}

bool Jugar(){

    int eleccion;

    eleccion = EligeModo();

    switch(eleccion){
        case SOLO:
            eleccion = EligeDificultad();
            switch(eleccion){
                case FACIL:
                    return JuegaReversiSolo(Facil);
                    break;
                case MEDIO:
                    return JuegaReversiSolo(Medio);
                    break;
                case DIFICIL:
                    return JuegaReversiSolo(Medio);
            }
            break;
        case VS:
            return JuegaReversiVs();

    }

    return false;
}


