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

#ifndef __TP_2_PROGRAMACION_I__funciones__
#define __TP_2_PROGRAMACION_I__funciones__

#define CANT_PER 20
#define ACTIVO 1
#define INACTIVO 0

#include <stdio.h>

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

void testPersona(EPersona personaArray[]);

void inicializarEstado(EPersona personaArray[], int arrayLenght, int value);
void cargarPersona(EPersona lista[], int indiceLibre, int dniAux, char nombreAux[], int edadAux);

int obtenerEspacioLibre(EPersona lista[], int arrayLenght);
int buscarPorDni(EPersona lista[], int arrayLenght, int dni);

void altaPersona(EPersona array[], int arrayLenght);
void borrarPersona(EPersona array[], int arrayLenght);
void mostrarPersona(EPersona persona);

void listaOrdenada(EPersona array[], int arrayLenght);

void imprimrGrafico(EPersona array[], int arrayLenght);

char confirm(char confirmMensaje[]);

#endif /* defined(__TP_2_PROGRAMACION_I__funciones__) */

