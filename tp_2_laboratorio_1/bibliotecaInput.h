/******************************************************************
 * Programación I – Laboratorio I
 * Programa: Trabajo práctico No 2.
 *
 * Objetivo:
 * Definir una estructura que represente una persona, con los campos nombre, edad, dni y un flag de estado.
 *
 *	    Hacer un programa que defina un array de 20 ítems de esta estructura y con un menú como el siguiente:
 *      1. Agregarunapersona
 *      2. Borrarunapersona
 *      3. Imprimirlistaordenadapornombre
 *      4. Imprimirgráficodeedades
 *
 * Aspectos a destacar:
 *
 *   Se utilizará el campo de estado para indicar si el ítem del array esta ocupado o no.
 *   El gráfico deberá ser un gráfico de barras en donde se agruparán 3 barras:
 *      • Menores de 18
 *      • De19a35
 *      • Mayores de 35.
 *      En el eje Y se marcarán la cantidad de personas en el grupo, y en el eje X el grupo
 *
 * Version: 0.2 del 06 de mayo de 2018
 * Autor: Gaston Pesoa
 *
 * *******************************************************************/

#ifndef __practicaModeloParcial_1__inputFunctions__
#define __practicaModeloParcial_1__inputFunctions__


int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);

//char getNumeroAleatorio(int desde , int hasta, int iniciar);

int esNumerico(char str[]);
int esTelefono(char str[]);
int esAlfaNumerico(char str[]);
int esSoloLetras(char str[]);
int esNumericoFlotante(char str[]);

void getString(char mensaje[],char input[]);
void getStringNombre(char mensaje[], char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringLetrasNombre(char mensaje[], char input[]);
int getStringAlfanumerico(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
int getValidFloat(char requestMessage[],char errorMessage[],float lowLimit, float hiLimit);
void getValidString(char requestMessage[],char errorMessage[], char input[]);
void getValidStringAlfanumerico(char requestMessage[],char errorMessage[], char input[]);
void getValidStringNombre(char requestMessage[],char errorMessage[], char input[]);

void cleanStdin(void);
void clearScreen(void);

#endif /* defined(__practicaModeloParcial_1__inputFunctions__) */
