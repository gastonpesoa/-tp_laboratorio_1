//
//  main.c
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



int main()
{
    EMoviesList* moviesList = moviesList = list_initMoviesList(); // Creamos una estructura a EMovieList de forma dinamica
    EMovie* movie = movie = list_newMovie(); // Creamos una estructura a EMovie de forma dinamica
    
    char seguir='s';
    int opcion=0;
    
    while(opcion!=4)
    {
        option = optionMainMenu();
        
        switch(opcion)
        {
            case 1:
                if (!agregarPelicula(moviesList,movie)) {
                    printf("\nNo se pudo agregar la pelicula\n");
                }
                else{
                    printf("\nPelicula cargada con exito\n");
                }
                break;
                
            case 2:
                break;
                
            case 3:
                mostrarListaDePeliculas(moviesList, movie);
                /*if (!mostrarListaDePeliculas(moviesList, movie)) {
                    printf("\nNo se pudo agregar la pelicula\n");
                }
                else{
                    getchar();
                }*/
                break;
                
            case 4:
                continue;
        }
    }
    
    return 0;
}

