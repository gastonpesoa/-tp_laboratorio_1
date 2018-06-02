

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "inputFunctions.h"



int main()
{
    EMovie moviesArray[MOVIES_MAX_QTY];
    setMoviesStatus(moviesArray, MOVIES_MAX_QTY, 0);

    //testMovies(moviesArray, MOVIES_MAX_QTY);

    int opcion=0;// Menu de opciones
    char confirmar='n';

    if (cargarMoviesArrayDesdeArchivo(moviesArray)) {

        printf("\nNo se pudo abrir el archivo\n");
    }
    else {

        printf("\nSe cargaron los archivos con exito\n");
    }

    while(opcion!=5)
    {
        printf("\n\n--------------------------------------------\
                  \n|*             MENU PRINCIPAL             *|\
                  \n--------------------------------------------");

        opcion = optionMainMenu();

        switch(opcion)
        {
            case 1: // Agregar pelicula
                agregarPelicula(moviesArray,MOVIES_MAX_QTY);
                break;

            case 2: // Borrar pelicula
                borrarPelicula(moviesArray, MOVIES_MAX_QTY);
                break;

            case 3: // Modificar pelicula
                modificarPelicula(moviesArray, MOVIES_MAX_QTY);
                break;

            case 4: // Generar pagina web
                generarPagina(moviesArray, "index.html");
                break;

            case 5: // Guardar y salir
                confirmar = confirm("\nDesea guardar los cambios realizados? [s|n]: ");
                if (confirmar=='s') {
                    if (guardarMovieArrayEnArchivo(moviesArray,MOVIES_MAX_QTY)) {

                        printf("\nNo se pudo abrir el archivo\n");
                        break;
                    }
                    else {

                        printf("\nSe guardo la informacion con exito\n");
                    }
                }
                continue;
        }
    }

    return 0;
}

