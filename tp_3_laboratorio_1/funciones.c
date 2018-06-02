//
//  funciones.c
//  tp3
//
//  Created by Gaston Pesoa on 31/05/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "inputFunctions.h"


char confirm(char confirmMensaje[]){

    char confirmar = 'n';

    do {

        printf("%s", confirmMensaje);
        setbuf(stdin, NULL);
        scanf("%c", &confirmar);
        confirmar = tolower(confirmar);

    } while (confirmar != 's' && confirmar != 'n');

    return confirmar;
}


int optionMainMenu(void){

    int option = 0;

    char menuPrinsipalMensaje[] =
    "\n\n1- Agregar pelicula\
    \n2- Borrar pelicula\
    \n3- Modificar pelicula\
    \n4- Generar pagina web\
    \n5- Salir\
    \n\nIngrese una opcion: ";

    char menuPrinsipalMensajeError[] = "\nSe debe elegir una opcion del 1 al 5";

    option = getValidInt(menuPrinsipalMensaje, menuPrinsipalMensajeError, 1, 5);
    return option;
}


int optionModifyMenu(void){

    int option = 0;

    char menuModificarProductMensaje[] =
    "\n\n1- Modificar titulo\
    \n2- Modificar genero\
    \n3- Modificar duracion\
    \n4- Modificar descripcion\
    \n5- Modificar puntaje\
    \n6- Modificar link de imagen\
    \n7- Volver\
    \n\nIngrese una opcion: ";

    char menuModificarProductMensajeError[] = "\nSe debe elegir una opcion del 1 al 7";

    option = getValidInt(menuModificarProductMensaje, menuModificarProductMensajeError, 1, 7);
    return option;
}


void setMoviesStatus(EMovie moviesArray[],int moviesArrayLenght,int value){

    int i;
    for(i=0; i < moviesArrayLenght; i++){
        moviesArray[i].status = value;
    }
}


int findMovieById(EMovie moviesArray[],int moviesArrayLenght,int movieId){

    int i;
    for(i=0;i < moviesArrayLenght; i++){
        if(moviesArray[i].movieId == movieId && moviesArray[i].status == ACTIVE){
            return i;
        }
    }
    return -1;
}


int findMovieEmptyPlace(EMovie moviesArray[],int moviesArrayLenght){

    int i;
    for(i=0;i < moviesArrayLenght; i++){
        if(moviesArray[i].status == INACTIVE){
            return i;
        }
    }
    return -1;
}


void setMovie(EMovie moviesArray[],int freePlaceIndex,char titleAux[],char generoAux[],int duracionAux,char descripcionAux[],int puntajeAux,char linkImagenAux[],int movieIdAux){

    strcpy(moviesArray[freePlaceIndex].titulo,titleAux);
    strcpy(moviesArray[freePlaceIndex].genero,generoAux);
    moviesArray[freePlaceIndex].duracion = duracionAux;
    strcpy(moviesArray[freePlaceIndex].descripcion,descripcionAux);
    moviesArray[freePlaceIndex].puntaje = puntajeAux;
    strcpy(moviesArray[freePlaceIndex].linkImagen,linkImagenAux);
    moviesArray[freePlaceIndex].movieId = movieIdAux;
    moviesArray[freePlaceIndex].status = ACTIVE;
}


void testMovies(EMovie moviesArray[],int moviesArrayLenght){

    // Alta de datos para testing
    setMovie(moviesArray,0,"Rambo III","Aventura",127,"John Rambo's former Vietnam superior, Colonel Samuel Trautman, has been assigned to lead a mission to help\
              the Mujahedeen rebels who are fighting the Soviet invasion of Afghanistan, but the Buddhist Rambo turns down Trautman's request that Rambo help out.\
              When the mission goes belly up and Trautman is kidnapped and tortured by Russian Colonel Zaysen, Rambo launches a rescue effort and allies himself\
              with the Mujahedeen rebels and gets their help in trying to rescue Trautman from Zaysen.", 6, "/imagenes/ramboIII.jpg",1);
    setMovie(moviesArray,1,"Jurassic Park","Accion",102,"Huge advancements in scientific technology have enabled a mogul to create an island full of living dinosaurs.\
              John Hammond has invited four individuals, along with his two grandchildren, to join him at Jurassic Park. But will everything go according to plan?\
              A park employee attempts to steal dinosaur embryos, critical security systems are shut down and it now becomes a race for survival with dinosaurs roaming\
              freely over the island", 8, "/imagenes/jurassicpark.jpg",2);
    setMovie(moviesArray,2,"Star Wars: Episode V - The Empire Strikes Back","Ciencia Ficcion",124,"Luke Skywalker, Han Solo, Princess Leia and Chewbacca face attack\
              by the Imperial forces and its AT-AT walkers on the ice planet Hoth. While Han and Leia escape in the Millennium Falcon, Luke travels to Dagobah in search of Yoda.\
              Only with the Jedi master's help will Luke survive when the dark side of the Force beckons him into the ultimate duel with Darth Vader", 9, "/imagenes/starwars.jpg",3);
};


void showMoviesArray(EMovie moviesArray[], int moviesArrayLenght){

    int i;

    for (i=0; i<moviesArrayLenght; i++) {
        if (moviesArray[i].status==ACTIVE) {

            printf("\nTitulo: %s\nGenero: %s\nDuracion: %d\nDescripcion: %s\nPuntaje: %d\nLinkImagen: %s\nId: %d",moviesArray[i].titulo,moviesArray[i].genero,moviesArray[i].duracion,moviesArray[i].descripcion,moviesArray[i].puntaje,moviesArray[i].linkImagen,moviesArray[i].movieId);
        }
    }
}

void showMovie(EMovie moviesArray){

    if (moviesArray.status==ACTIVE) {

        printf("\nTitulo: %s\nGenero: %s\nDuracion: %d\nDescripcion: %s\nPuntaje: %d\nLinkImagen: %s\nId: %d",moviesArray.titulo,moviesArray.genero,moviesArray.duracion,moviesArray.descripcion,moviesArray.puntaje,moviesArray.linkImagen,moviesArray.movieId);
    }
}

int cargarMoviesArrayDesdeArchivo(EMovie* moviesArray){

    int flag=0;
    FILE* ptrFile;

    ptrFile = fopen("bin.dat", "rb");
    if (ptrFile==NULL) {

        ptrFile = fopen("bin.dat", "wb");
        if (ptrFile==NULL) {

            return 1;
        }
        flag=1;
    }
    if (flag==0) {

        fread(moviesArray, sizeof(EMovie), X, ptrFile);
    }
    fclose(ptrFile);
    return 0;
}


int guardarMovieArrayEnArchivo(EMovie moviesArray[],int moviesArrayLenght){

    FILE* ptrFile;

    ptrFile = fopen("bin.dat", "wb");
    if (ptrFile==NULL) {

        return 1;
    }

    fwrite(moviesArray, sizeof(EMovie), X, ptrFile);
    fclose(ptrFile);
    return 0;
}


int guardarPelicula(EMovie moviesArray[]){

    FILE* ptrFile;

    ptrFile = fopen("bin.dat", "ab+");
    if (ptrFile==NULL) {

        printf("\nError abriendo el archivo\n");
        return 0;
    }

    setbuf(stdin, NULL);
    fwrite(moviesArray, sizeof(EMovie), 1, ptrFile);
    printf("\nSe guardo la pelicula en el archivo\n");
    fclose(ptrFile);
    return 1;
}


int agregarPelicula(EMovie moviesArray[], int moviesArrayLenght){

    char titleAux[50];
    char generoAux[20];
    int duracionAux;
    char descripcionAux[500];
    int puntajeAux;
    char linkImagenAux[200];
    int movieIdAux;

    int freePlaceIndex;

    printf("\n----------------------------------------------\
            \n|            *  AGREGAR PELICULA  *          |\
            \n----------------------------------------------\n\n");

    freePlaceIndex = findMovieEmptyPlace(moviesArray, moviesArrayLenght);
    if (freePlaceIndex == -1) {

        printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
        getChar("\n\nENTER (para continuar)");
        return 0;

    }
    else{

        getValidStringTitle("Ingrese el titulo: ", titleAux);
        getValidStringGenero("Ingrese el genero: ", "\nEl genero debe estar compuesto por letras", generoAux);
        duracionAux = getValidInt("Ingrese la duracion en minutos: ", "\nLa duracion debe estar compuesta por numeros enteros", 1, 300);
        getValidStringDescription("Ingrese una descripcion: ", "\nLa descripcion debe estar compuesta solo por letras", descripcionAux);
        puntajeAux = getValidInt("Ingrese un puntaje: ", "\nEl puntaje debe ser numerico", 1, 10);
        getValidStringLink("Ingrese el link de imagen: ", linkImagenAux);
        movieIdAux = freePlaceIndex+1;

        setMovie(moviesArray, freePlaceIndex, titleAux, generoAux, duracionAux, descripcionAux, puntajeAux, linkImagenAux, movieIdAux);

        /*if (!guardarPelicula(moviesArray)) {
            printf("\nNo se pudo guardar la pelicula\n");
            return 0;
        }*/

        printf("\nSe ha agregado la pelicula con exito!\n");
        showMovie(moviesArray[freePlaceIndex]);
        getChar("\n\nPresione una tecla para ontinuar\n");
        return 1;
    }
}


int borrarPelicula(EMovie moviesArray[],int moviesArrayLenght){

    int movieIdAux;
    int foundMovieIndex;
    char confirmar='n';

     printf("\n-----------------------------\
             \n|  *   BORRAR PELICULA   *  |\
             \n-----------------------------\n");

    showMoviesArray(moviesArray, moviesArrayLenght);

    movieIdAux = getValidInt("\nIngrese el ID de la pelicula a dar de baja: ", "El ID debe ser numerico", 1, 200);

    foundMovieIndex = findMovieById(moviesArray, moviesArrayLenght, movieIdAux);
    if (foundMovieIndex==-1) {

        printf("\nNo se encontro ese ID\n");
        getChar("\nPresione una tecla para continuar");
        return 0;
    }
    else {

        showMovie(moviesArray[foundMovieIndex]);

        confirmar = confirm("\n\nSe esta por eliminar la pelicula seleccionada, confirma la baja? [s|n]: ");

        if (confirmar == 's') {

            moviesArray[foundMovieIndex].status = INACTIVE;
            printf("\nSe ha dado de baja a la pelicula\n\n");
            getChar("\n\nENTER (para continuar)");
            return 1;
        }
        else {

            printf("\nNo se ha realizado la baja\n\n");
            getChar("\n\nENTER (para continuar)");
            return 0;
        }// if (confirmar == 's')
    }// if (foundMovieIndex==-1)
}//int borrarPelicula(EMovie moviesArray[],int moviesArrayLenght)

void modificarPelicula(EMovie moviesArray[], int moviesArrayLenght){

    char titleAux[50];
    char generoAux[20];
    int duracionAux;
    char descripcionAux[500];
    int puntajeAux;
    char linkImagenAux[200];
    int movieIdAux;

    int foundMovieIndex;
    char confirmar='n';
    int opcion = 0;

    printf("\n-----------------------------------\
            \n|  *  MODIFICACION DE PELICULA  * |\
            \n-----------------------------------\n");

    showMoviesArray(moviesArray, moviesArrayLenght);

    movieIdAux = getValidInt("\nIngrese el ID de la pelicula a modificar: ", "El ID debe ser numerico", 1, 200);

    foundMovieIndex = findMovieById(moviesArray, moviesArrayLenght, movieIdAux);
    if (foundMovieIndex==-1) {

        printf("\nNo se encontro ese ID\n");
        getChar("\nPresione una tecla para continuar");

    }
    else {

        showMovie(moviesArray[foundMovieIndex]);

        strcpy(titleAux, moviesArray[foundMovieIndex].titulo);
        strcpy(generoAux, moviesArray[foundMovieIndex].genero);
        duracionAux = moviesArray[foundMovieIndex].duracion;
        strcpy(descripcionAux, moviesArray[foundMovieIndex].descripcion);
        puntajeAux = moviesArray[foundMovieIndex].puntaje;
        strcpy(linkImagenAux, moviesArray[foundMovieIndex].linkImagen);
        movieIdAux = moviesArray[foundMovieIndex].movieId;

        while (opcion!=7) {

            opcion = optionModifyMenu();

            switch (opcion) {

                case 1:
                    getValidStringTitle("Ingrese el titulo: ", titleAux);
                    break;

                case 2:
                    getValidStringGenero("Ingrese el genero: ", "\nEl genero debe estar compuesto por letras", generoAux);
                    break;

                case 3:
                    duracionAux = getValidInt("Ingrese la duracion en minutos: ", "\nLa duracion debe estar compuesta por numeros enteros", 1, 300);

                case 4:
                    getValidStringDescription("Ingrese una descripcion: ", "\nLa descripcion debe estar compuesta solo por letras", descripcionAux);
                    break;

                case 5:
                    puntajeAux = getValidInt("Ingrese un puntaje: ", "\nEl puntaje debe ser numerico", 1, 10);
                    break;

                case 6:
                    getValidStringLink("Ingrese el link de imagen: ", linkImagenAux);
                    break;

                case 7:
                    continue;

            }// switch (opcion)

            confirmar = confirm("\n\nSe esta por modifcar la pelicula seleccionada, confirma la modificacion? [s|n]: ");

            if (confirmar=='s') {

                setMovie(moviesArray, foundMovieIndex, titleAux, generoAux, duracionAux, descripcionAux, puntajeAux, linkImagenAux, movieIdAux);

                printf("\nSe ha modificado la pelicula\n\n");

                showMovie(moviesArray[foundMovieIndex]);
                getChar("\nPresione una tecla para continuar");

            }
            else {

                printf("\nNo se ha modificado la pelicula\n\n");
                getChar("\n\nENTER (para continuar)");

            }// if (confirmar == 's')
        }//while (opcion!=7)
    }//if (foundMovieIndex==-1)

}//int modificarPelicula(EMovie moviesArray[], int moviesArrayLenght)


void generarPagina(EMovie moviesArray[], char nombre[]){

    int i;
    FILE* ptrFile;
    ptrFile = fopen(nombre, "w");
    if (ptrFile==NULL) {

        printf("\nError abriendo el archivo\n");
        exit(1);
    }

    fprintf(ptrFile, "<!DOCTYPE html>\
            <!-- Template by Quackit.com -->\
            <html lang='en'>\
            <head>\
            <meta charset='utf-8'>\
            <meta http-equiv='X-UA-Compatible' content='IE=edge'>\
            <meta name='viewport' content='width=device-width, initial-scale=1'>\
            <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\
            <title>Lista peliculas</title>\
            <!-- Bootstrap Core CSS -->\
            <link href='css/bootstrap.min.css' rel='stylesheet'>\
            <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\
            <link href='css/custom.css' rel='stylesheet'>\
            <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\
            <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\
            <!--[if lt IE 9]>\
            <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\
            <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\
            <![endif]-->\
            </head>\
            <body>\
            <div class='container'>\
            <div class='row'>");

    for (i=0; i<X; i++) {
        if (moviesArray[i].status!=INACTIVE) {

            fprintf(ptrFile, "<!-- Repetir esto para cada pelicula -->\
                    <article class='col-md-4 article-intro'>\
                    <a href='#'>\
                    <img class='img-responsive img-rounded'\
                    src='%s' alt=''>\
                    </a>\
                    <h3>\
                    <a href='#'>%s</a>\
                    </h3>\
                    <ul>\
                    <li>Género:%s</li>\
                    <li>Puntaje:%d</li>\
                    <li>Duración:%d</li>\
                    </ul>\
                    <p>%s</p>\
                    </article>\
                    <!-- Repetir esto para cada pelicula -->",moviesArray[i].linkImagen,moviesArray[i].titulo,moviesArray[i].genero,moviesArray[i].puntaje,moviesArray[i].duracion,moviesArray[i].descripcion);
        }
    }

    fprintf(ptrFile, "</div>\
            <!-- /.row -->\
            </div>\
            <!-- /.container -->\
            <!-- jQuery -->\
            <script src='js/jquery-1.11.3.min.js'></script>\
            <!-- Bootstrap Core JavaScript -->\
            <script src='js/bootstrap.min.js'></script>\
            <!-- IE10 viewport bug workaround -->\
            <script src='js/ie10-viewport-bug-workaround.js'></script>\
            <!-- Placeholder Images -->\
            <script src='js/holder.min.js'></script>\
            </body>\
            </html>");

    fclose(ptrFile);
    printf("\nPagina web generada\n");
    getChar("\nPresione una tecla para continuar\n");
}



