#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param arrayLenght Indica la longitud del array
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int arrayLenght);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);



float getFloat(char mensaje[]);
int getInt(char mensaje[]);
char getChar(char mensaje[]);
void getString(char mensaje[], char input[]);

int esNumerico(char str[]);
int esSoloLetras(char str[]);
int esAlfanumerico(char str[]);

int getStringNumeros(char mensaje[], char input[]);
int getStringLetras(char mensaje[], char input[]);

#endif // FUNCIONES_H_INCLUDED





