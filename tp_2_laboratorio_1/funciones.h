
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

