#ifndef MANEJOCONSOLA_H_INCLUDED
#define MANEJOCONSOLA_H_INCLUDED

// Estados del cursor
enum estadoCursor{APAGADO, ENCENDIDO};
// Modos del cursor
enum modoCursor{MINI = 5, NORMAL = 20, SOLIDO = 80};

enum miColor{NEGRO, AZUL, VERDE, AGUAMARINA,
            ROJO, PURPURA, AMARILLO, GRISCLARO,
            GRIS, AZULCLARO, VERDECLARO, AGUAMARINACLARO,
            ROJOCLARO, PURPURACLARO, AMARILLOCLARO, BLANCO};

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Funci�n que cambia el estado del cursor para ocultarlo o mostrarlo
  *
  * @param estado Encendido o apagado
  *
  * @param modo Tama�o del cursor
  */
void CambiaCursor(estadoCursor estado, modoCursor modo = NORMAL);

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Ajustamos la ventana para que siempre tenga el mismo tama�o
  */
void AjustaVentana();

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Movemos el cursor a una posici�n (x, y)
  *
  * @param x posici�n a la que moveremos el cursor
  *
  * @param y posici�n a la que moveremos el cursor
  */
void gotoxy(int x, int y);

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Establecemos el color del fondo y del texto que se usar� en el programa
  *
  * @param colorFondo el color que tendr� el fondo
  *
  * @param colorTexto el color que tendr� el texto
  */
void EstableceColor(miColor colorFondo, miColor colorTexto);

#define ANCHOVENTANA 150
#define ALTOVENTANA 55

#endif // MANEJOCONSOLA_H_INCLUDED
