
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "bibliotecaInput.h"


/** \brief Carga datos de prueba en el array de personas
 * \param personaArray Es el array de personas
 * \return void
 *
 */
void testPersona(EPersona personaArray[]){

    // Alta de datos para testing
    cargarPersona(personaArray, 0, 44123987, "Ricardo Mollo", 8);
    cargarPersona(personaArray, 1, 40456987, "Gustavo Cerati", 13);
    cargarPersona(personaArray, 2, 39456321, "Roberto Paez", 21);
    cargarPersona(personaArray, 3, 28159756, "Norberto Napolitano", 30);
    cargarPersona(personaArray, 4, 25789654, "Carlos Garcia", 34);
    cargarPersona(personaArray, 5, 20456789, "Luis Alberto Spinetta", 53);
    cargarPersona(personaArray, 6, 10123456, "Miguel Abuelo", 74);
}


/**
 * \brief Inicializa el estado en un array de personas
 * \param personaArray Es el array el cual se inicializara
 * \param arrayLenght Indica la longitud del array
 * \param value Es el valor que se asignara a estado
 * \return -
 *
 */
void inicializarEstado(EPersona personaArray[], int arrayLenght, int value){

    int i;

    for (i = 0; i < arrayLenght; i++){
        personaArray[i].estado = value;
    }
}


/**
 * \brief Carga los valores de la persona en el array
 * \param lista Es el array de personas
 * \param indiceLibre Indica la posicion a setear
 * \param dniAux DNI de la persona
 * \param nombreAux Nombre de la persona
 * \param edadAux Edad de la persona
 * \return -
 *
 */
void cargarPersona(EPersona lista[], int indiceLibre, int dniAux, char nombreAux[], int edadAux)
{
    lista[indiceLibre].dni = dniAux;
    strcpy(lista[indiceLibre].nombre, nombreAux);
    lista[indiceLibre].edad = edadAux;
    lista[indiceLibre].estado = ACTIVO;
}


/**
 * \brief Obtiene el primer indice libre del array.
 * \param lista El array se pasa como parametro.
 * \param arrayLenght Indica la longitud del array
 * \return Si no hay lugares libres (-1) y si la hay el primer indice disponible
 *
 */
int obtenerEspacioLibre(EPersona lista[], int arrayLenght){

    int i;

    for(i = 0; i < arrayLenght; i++){
        if (lista[i].estado == INACTIVO) {
            return i;
        }
    }
    return -1;
}


/**
 * \brief Obtiene el indice que coincide con el dni pasado por parametro.
 * \param lista El array se pasa como parametro.
 * \param arrayLenght Indica la longitud del array
 * \param dni El dni a ser buscado en el array.
 * \return Si no hay coincidencia (-1) y si la hay, el indice en donde se encuentra el elemento que coincide con el parametro dni
 *
 */
int buscarPorDni(EPersona lista[], int arrayLenght, int dni){

    int i;

    for (i = 0; i < arrayLenght; i++) {
        if (lista[i].dni == dni && lista[i].estado == ACTIVO) {
            return i;
        }
    }
    return -1;
}


/**
 * \brief Da de alta una nueva persona.
 * \param array El array donde se va a almacenar.
 * \param arrayLenght La longitud del array donde se va a almacenar.
 *
 */
void altaPersona(EPersona array[], int arrayLenght){

    int indiceLibre;
    int existe;
    int dni;
    int edad;

    char nombreAux[50];

    clearScreen();
    printf("\n-----------------------\
           \n|*  ALTA DE PERSONA  *|\
           \n-----------------------\n");

    indiceLibre = obtenerEspacioLibre(array, arrayLenght);
    if (indiceLibre == -1) {

        printf("\nNO QUEDAN INDICES LIBRES PARA DAR DE ALTA UNA NUEVA PERSONA\n\n");
    }
    else {

        dni = getValidInt("\nIngrese el DNI: ", "El DNI debe ser numerico\n\n", 1111111, 99999999);

        existe = buscarPorDni(array, arrayLenght, dni);
        if (existe != -1) {

            printf("\nEl DNI %d ya esta dado de alta en el sistema\n\n", dni);
            mostrarPersona(array[existe]);
        }
        else {

            getValidStringNombre("\nIngrese el nombre y el apellido de la persona: ", "El nombre debe estar compuesto solo por letras\n", nombreAux);
            edad = getValidInt("\nIngrese la edad de la persona: ", "La edad debe ser numerica\n", 1, 100);

            cargarPersona(array, indiceLibre, dni, nombreAux, edad);

            // Se muestra la persona dada de alta
            clearScreen();
            printf("\nSE REALIZO EL ALTA DE LA PERSONA!\n");
            printf("\n--------------------------------------------------------------------\
                   \n|    DNI   |               NOMBRE Y APELLIDO               |  EDAD |\
                   \n--------------------------------------------------------------------");
            mostrarPersona(array[indiceLibre]);
            printf("\n--------------------------------------------------------------------");
            getChar("\n\nENTER (para continuar)");

        }// if (existe != -1)
    }// if (indiceLibre == -1)
}// void altaPersona(EPersona array[], int arrayLenght)


/**
 * \brief Borra de la lista, luego de confirmar la baja, a la persona con el DNI ingresado.
 * \param array El array donde se va a buscar la persona con el DNI ingresado.
 * \param arrayLenght La longitud del array donde se va a almacenar.
 *
 */
void borrarPersona(EPersona array[], int arrayLenght){

    int dni;
    int existe;
    char confirmar;

    clearScreen();
    printf("\n-----------------------\
           \n|*  BAJA DE PERSONA  *|\
           \n-----------------------\n");

    dni = getValidInt("\nIngrese el DNI: ", "El DNI debe ser numerico\n\n", 1111111, 99999999);

    existe = buscarPorDni(array, arrayLenght, dni);
    if (existe == -1) {

        printf("\nEl DNI %d ingresado, no se encuentra registrado\n\n", dni);
    }
    else {

        // Se muestra la persona a dar de baja
        printf("\n--------------------------------------------------------------------\
               \n|    DNI   |               NOMBRE Y APELLIDO               |  EDAD |\
               \n--------------------------------------------------------------------");
        mostrarPersona(array[existe]);
        printf("\n--------------------------------------------------------------------");

        confirmar = confirm("\n\nSe esta por eliminar a la persona seleccionada, confirma la baja? [s|n]: ");
        if (confirmar == 's') {

            array[existe].estado = INACTIVO;
            printf("\nPERSONA BORRADA\n");
            getChar("\nENTER (para continuar)");
        }
        else {
            printf("\nNO SE HA BORRADO A LA PERSONA\n\n");
            getChar("\n\nENTER (para continuar)");
        }
    }
}


/**
 * \brief Muestra los datos almacenados en una estructura de persona.
 * \param persona El array que se va a mostrar.
 *
 */
void mostrarPersona(EPersona persona){

    printf("\n| %8d | %45s | %5d |", persona.dni, persona.nombre, persona.edad);
}


/**
 * \brief Ordena alfabeticamente el array ingresado.
 * \param array El array que se ordenara.
 * \param arrayLenght La longitud del array.
 *
 */
void listaOrdenada(EPersona array[], int arrayLenght){

    EPersona arrayAux;

    int i, j;

    clearScreen();
    printf("\n----------------------------------\
            \n|*  LISTA ORDENADA DE PERSONAS  *|\
            \n----------------------------------\n");

    for (i = 0; i < arrayLenght - 1; i++) {
        if (array[i].estado == INACTIVO) {
            continue;
        }
        for (j = i + 1; j < arrayLenght; j++) {
            if (array[i].estado == INACTIVO) {
                continue;
            }
            if (strcmp(array[i].nombre, array[j].nombre) > 0) {
                arrayAux = array[j];
                array[j] = array[i];
                array[i] = arrayAux;
            }
        }
    }

    printf("\n--------------------------------------------------------------------\
           \n|    DNI   |               NOMBRE Y APELLIDO               |  EDAD |\
           \n--------------------------------------------------------------------");
    for (i = 0; i < arrayLenght; i++) {
        if (array[i].estado == ACTIVO) {
            mostrarPersona(array[i]);
        }
    } // for (i = 0; i < arrayLenght; i++)
    printf("\n--------------------------------------------------------------------");
    getChar("\n\nENTER (para continuar)");

} // void listaOrdenada(EPersona array[], int arrayLenght)


/**
 * \brief Imprime grafico de barras de 3 grupos de edades, menores de 18, entre 19 a 35 y mayores de 35.
 * \param array El array que se ordenara.
 * \param arrayLenght La longitud del array.
 *
 */
void imprimrGrafico(EPersona array[], int arrayLenght){

    int i, j, mayor = 0, filas;
    int contadores[3];

    clearScreen();
    printf("\n----------------------------\
           \n|*  HISTOGRAMA DE EDADES  *|\
           \n----------------------------\n");

    // Inicializo contadores en 0
    for (i = 0; i < 3; i++) {
        contadores[i] = 0;
    }

    // Recorro el array de personas y cuento cantidad de cada grupo de edades
    for (i = 0; i < arrayLenght; i++) {
        if (array[i].edad < 19 && array[i].estado == ACTIVO) {
            contadores[0]++;
        }
        else {
            if (array[i].edad > 18 && array[i].edad < 36 && array[i].estado == ACTIVO) {
                contadores[1]++;
            }
            if (array[i].edad > 35 && array[i].estado == ACTIVO) {
                contadores[2]++;
            }
        } // if (array[i].edad < 19 && array[i].estado == ACTIVO)
    } // for (i = 0; i < arrayLenght; i++)

    // Encuentro el grupo de edades con mas personas registradas
    if (contadores[0] >= contadores[1] && contadores[0] >= contadores[2]) {
        mayor = contadores[0];
    }
    else {
        if (contadores[1] >= contadores[0] && contadores[1] >= contadores[2]) {
            mayor = contadores[1];
        }
        if (contadores[2] >= contadores[0] && contadores[2] >= contadores[1]){
            mayor = contadores[2];
        }
    }

    filas = mayor; // Declaro la cantidad de filas en base al grupo mayor

    //Imprimo el grafico
    for (i = 0; i < mayor; i++) {
        for (j = 0; j < 3; j++) {
            if (contadores[j] >= filas) {

                printf(" *   ");
            }
            else {

                printf("     ");

            } // if (contadores[j] >= filas)
        } // for (j = 0; j < 3; j++)
        filas--;
        printf("\n");

    } // for (i = 0; i < mayor; i++)
    printf("<18 19-35 >35\n\n");
    getChar("\n\nENTER (para continuar)");

} // void imprimrGrafico(EPersona array[], int arrayLenght)


/** \brief Funcion que solicita un caracter 's' o 'n', valida que sea ingresado correctamente y devuelve el resultado
 * \param char confirmMensaje[] el mensaje a ser mostrado
 * \return caracter 's' o 'n'
 *
 */
char confirm(char confirmMensaje[]){

    char confirmar = 'n';

    do {

        printf("%s", confirmMensaje);
        cleanStdin();
        scanf("%c", &confirmar);
        confirmar = tolower(confirmar);

    } while (confirmar != 's' && confirmar != 'n');

    return confirmar;
}
