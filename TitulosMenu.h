#ifndef TITULOSMENU_H_INCLUDED
#define TITULOSMENU_H_INCLUDED

enum {JUGAR, INSTRUCCIONES, CREDITOS, SALIR};

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Dibuja una linea debajo de la selecci�n del men� en la que se encuentra el usuario
  *
  * @param eleccion la opci�n del men� en la que se encuentra
  *
  * @param c caracter con el que subraya
  */
void SubrayaMenu(int eleccion, char c);

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Imprime el t�tulo "Reversi" con arte de ascii
  *
  * @param t tiempo que tarda entre cada s�mbolo para formar el t�tulo
  */
void ImprimeTitulo(int t);

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Imprime la palabra "Jugar"
  */
void ImprimeJugar();

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Imprime las instrucciones de juego
  *
  * @param x Coordenada en el eje horizontal donde comenzar a imprimir
  *
  * @param y Coordenada en el eje vertical donde
  */
void ImprimeInstrucciones(int x, int y);

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Imprime los cr�ditos
  *
* @param x Coordenada en el eje horizontal donde comenzar a imprimir
  *
  * @param y Coordenada en el eje vertical donde
  */
void ImprimeCreditos(int x, int y);

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Imprime la palabra "Salir"
  */
void ImprimeSalir();

//-------------------------------------------------------------------------------------------------------------
/**
  * @brief Imprime la despedida al usuario
  */
void ImprimeGracias();

#endif // TITULOSMENU_H_INCLUDED
