//
//  functions.c
//  tp_3_laboratorio_1
//
//  Created by Gaston Pesoa on 27/05/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "movies.h"
#include "functions.h"
#include "inputFunctions.h"


int guardarPelicula(EMovie* movie){
    
    FILE* ptrFile;
    
    ptrFile = fopen("bin.dat", "ab+");
    if (ptrFile==NULL) {
        
        printf("\nError abriendo el archivo\n");
        return 0;
    }
    
    fwrite(movie, sizeof(EMovie), 1, ptrFile);
    printf("\nSe guardo\n");
    fclose(ptrFile);
    return 1;
}


int agregarPelicula(void){
    
    int seguir = 1;
    /*int seguirCargando;
    int auxNuevaLongitud;
    int longitudPeliculas=1;
    EMovie* moviesAux;
    FILE* ptrFile;*/
    
    clearScreen();
    printf("\n------------------------\
            \n| * ALTA DE PELICULA * |\
            \n------------------------\n");
    
    EMoviesList* moviesList = list_initMoviesList();
    
    EMovie* movie = list_newMovie();
    
    while (seguir==1) {
        
        list_enterMovie(movie);
        
        list_addMovie(moviesList, movie);
        
        if (!guardarPelicula(movie)) {
            printf("\nNo se pudo agregar la pelicula\n");
            return 0;
        }
        
        movie = list_newMovie();
        
        seguir = getValidInt("Si desea cargar otra pelicula ingrese 1, para salir 0: ", "Se debe ingresar '1' para seguir, o '0' para salir", 0, 1);
    }
    free(movie);
    return 1;
    
    /*movie = (EMovie*)malloc(sizeof(EMovie));
    if (movie==NULL) {
        
        printf("\nNo hay lugar en memoria");
        return 0;
    }
    
    while (1) {
        
        getValidStringTitle("Ingrese el titulo: ", (movie+longitudPeliculas-1)->titulo);
        getValidStringGenero("Ingrese el genero: ", "El genero debe estar compuesto por letras", (movie+longitudPeliculas-1)->genero);
        (movie+longitudPeliculas-1)->duracion = getValidInt("Ingrese la duracion en minutos: ", "La duracion debe estar compuesta por numeros enteros", 1, 300);
        getValidStringDescription("Ingrese una descripcion: ", "La descripcion debe estar compuesta solo por letras", (movie+longitudPeliculas-1)->descripcion);
        (movie+longitudPeliculas-1)->puntaje = getValidInt("Ingrese un puntaje: ", "El puntaje debe ser numerico", 1, 10);
        getValidStringLink("Ingrese el link de imagen: ", (movie+longitudPeliculas-1)->linkImagen);
        
        seguirCargando = getValidInt("Si desea cargar otra pelicula ingrese 1, para salir 0: ", "Se debe ingresar '1' para seguir, o '0' para salir", 0, 1);
        if (seguirCargando==1) {
            
            longitudPeliculas++;
            
            auxNuevaLongitud = sizeof(EMovie)*longitudPeliculas;
            
            moviesAux = (EMovie*)realloc(movie, auxNuevaLongitud);
            if (moviesAux==NULL) {
                printf("\nNo hay lugar en memoria");
                return 0;
            }
            movie = moviesAux;
        }
        else {
            break;
        }
    }
  
    ptrFile = fopen("bin.dat", "ab+");
    if (ptrFile==NULL) {
        
        printf("Error abriendo el archivo");
        return 0;
    }
    
    fwrite(movie, sizeof(EMovie), 1, ptrFile);
    
    fclose(ptrFile);
    return 1;*/
}