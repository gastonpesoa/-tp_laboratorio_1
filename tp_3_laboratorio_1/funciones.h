//
//  funciones.h
//  tp3
//
//  Created by Gaston Pesoa on 31/05/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#ifndef __tp3__funciones__
#define __tp3__funciones__

#include <stdio.h>

#define MOVIES_MAX_QTY 200

#define X 3

#define ACTIVE 1
#define INACTIVE 0

typedef struct{
    char titulo[50];
    char genero[20];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkImagen[200];
    int movieId;
    int status;
}EMovie;


/** Funcion que solicita un caracter 's' o 'n', valida que sea ingresado correctamente
 *  y devuelve el resultado
 *  @param char confirmMensaje[] el mensaje a ser mostrado
 *  @return caracter 's' o 'n'
 */
char confirm(char confirmMensaje[]);

/** \brief
 * Funcion para mostrar las opciones del menu principal en consola y pedir el ingreso de la seleccion al usuario.
 * \return option Retorna el valor elegido por el usuario.
 *
 */
int optionMainMenu(void);

/** \brief
 * Funcion para mostrar las opciones del menu modificar en consola y pedir el ingreso de la seleccion al usuario.
 * \return option Retorna el valor elegido por el usuario.
 *
 */
int optionModifyMenu(void);

/**
 * \brief Inicializa el status en un array de peliculas
 * \param moviesArray Es el array en el cual buscar
 * \param moviesArrayLenght Indica la logitud del array
 * \param value Es el valor que se asignara a status
 * \return -
 *
 */
void setMoviesStatus(EMovie moviesArray[],int moviesArrayLenght,int value);

/**
 * \brief Busca la primer ocurrencia de una pelicula mediante su Id
 * \param moviesArray Es el array en el cual buscar
 * \param moviesArrayLenght Indica la logitud del array
 * \param movieId Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
int findMovieById(EMovie moviesArray[],int moviesArrayLenght,int movieId);

/**
 * \brief Busca el primer lugar no utilizado en el array
 * \param moviesArray Es el array en el cual buscar
 * \param moviesArrayLenght Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 *
 */
int findMovieEmptyPlace(EMovie moviesArray[],int moviesArrayLenght);

/**
 * \brief Carga los valores de la pelicula
 * \param moviesArray Es el array de peliculas
 * \param freePlaceIndex Indica la posicion a setear
 * \param titleAux Descripcion de la pelicula
 * \param generoAux Genero de la pelicula
 * \param duracionAux duracion de la pelicula
 * \param descripcionAux descripcion de la pelicula
 * \param puntajeAux puntaje de la pelicula
 * \param linkImagenAux link a la imagen de la pelicula
 * \param movieIdAux id de la pelicula
 * \return -
 *
 */
void setMovie(EMovie moviesArray[],int freePlaceIndex,char titleAux[],char generoAux[],int duracionAux,char descripcionAux[],int puntajeAux,char linkImagenAux[],int movieIdAux);

/** \brief Carga datos de prueba en el array de peliculas
 * \param moviesArray El array de peliculas
 * \param moviesArrayLenght Longitud del array
 * \return void
 */
void testMovies(EMovie moviesArray[],int moviesArrayLenght);

/**
 * \brief Muestra las peliculas activas por pantalla
 * \param moviesArray Es el array de peliculas
 * \param moviesArrayLenght Indica la logitud del array
 * \return -
 */
void showMoviesArray(EMovie moviesArray[], int moviesArrayLenght);

/**
 * \brief Muestra el pelicula seleccionado por pantalla
 * \param moviesArray Es el array a mostrar
 * \param moviesArrayLenght Indica la logitud del array
 * \return -
 */
void showMovie(EMovie moviesArray);

/**
 * \brief Carga datos al array de peliculas desde un archivo binario
 * \param moviesArray Es el array a donde se cargaran los datos
 * \return -
 */
int cargarMoviesArrayDesdeArchivo(EMovie* moviesArray);

/**
 * \brief Guarda la informacion del array de peliculas al archivo binario
 * \param moviesArray Es el array desde donde se guardara la informacion
 * \return -
 */
int guardarMovieArrayEnArchivo(EMovie moviesArray[],int moviesArrayLenght);

/**
 *  Guarda una pelicula en el archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int guardarPelicula(EMovie moviesArray[]);

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie moviesArray[], int moviesArrayLenght);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie moviesArray[],int moviesArrayLenght);

/** \brief Pide al usuario el Id del pelicula a ser modificado, despliega un menu de opciones de los campos disponibles y luego de confirmar los modifica
 * \param moviesArray el array de peliculas donde se buscara la pelicula a ser modificada
 * \param moviesArrayLenght Longitud del array
 * \return -
 */
void modificarPelicula(EMovie moviesArray[], int moviesArrayLenght);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie moviesArray[], char nombre[]);



#endif /* defined(__tp3__funciones__) */
