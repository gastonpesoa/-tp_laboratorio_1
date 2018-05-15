/******************************************************************
 * Programación I – Laboratorio I
 * Programa: Trabajo práctico No 2.
 *
 * Objetivo:
 * Definir una estructura que represente una persona, con los campos nombre, edad, dni y un flag de estado.
 *
 * Hacer un programa que defina un array de 20 ítems de esta estructura y con un menú como el siguiente:
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "bibliotecaInput.h"



int main() {

    // Array de personas
    EPersona persona[CANT_PER];
    inicializarEstado(persona, CANT_PER, INACTIVO);

    //HardCode con datos para test
    testPersona(persona);

    // Variables globales
    char menuPrinsipalMensaje[] =
            "\n\n1- Agregar persona\
            \n2- Borrar persona\
            \n3- Imprimir lista ordenada por  nombre\
            \n4- Imprimir grafico de edades\
            \n5- Salir\
            \n\nIngrese una opcion: ";

    char menuPrinsipalMensajeError[] = "\nSe debe elegir una opcion del 1 al 5";

    int opcion = 0;

    while (opcion != 5) {

        //clearScreen();
        printf("\n\n--------------------------------------------\n|*             MENU PRINCIPAL             *|\n--------------------------------------------");

        opcion = getValidInt(menuPrinsipalMensaje, menuPrinsipalMensajeError, 1, 5);

        switch(opcion) {

            case 1: // Alta de persona
                altaPersona(persona, CANT_PER);
                break;

            case 2: // Borrar persona
                borrarPersona(persona, CANT_PER);
                break;

            case 3: // Lista ordenada de personas
                listaOrdenada(persona, CANT_PER);
                break;

            case 4: // Histograma de edades
                imprimrGrafico(persona, CANT_PER);
                break;

        } // switch(opcion)
    } // while (opcion != 5)

    return 0;
} // int main()
