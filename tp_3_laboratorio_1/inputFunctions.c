//
//  inputFunctions.c
//  practica_modelo_parcial_2
//
//  Created by Gaston Pesoa on 01/05/18.
//  Copyright (c) 2018 Gaston Pesoa. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "inputFunctions.h"



void cleanStdin(void){
    //setbuf(stdin,NULL);
    int c;
    do {
        c = getchar();
    } while 	(c != '\n' && c != EOF);
}


void clearScreen(void){
    
    system("@cls||clear");
}



char getChar(char mensaje[]){
    
    char auxiliar;
    printf("%s",mensaje);
    setbuf(stdin,NULL);
    scanf("%c",&auxiliar);
    return auxiliar;
}

int getInt(char mensaje[]){
    
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}


int esNumerico(char str[]){
    
    int i=0;
    while(str[i] != '\0'){
        
        if(str[i] < '0' || str[i] > '9'){
            return 0;
        }
        i++;
    }
    return 1;
}


int esSoloLetras(char str[]){
    
    int i=0;
    while(str[i] != '\0'){
        
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')){
            return 0;
        }
        i++;
    }
    return 1;
}

void getString(char mensaje[],char input[]){
    
    setbuf(stdin,NULL);
    printf("%s",mensaje);
    scanf ("%s", input);
}


void getStringSpace(char mensaje[], char input[]){
    
    setbuf(stdin,NULL);
    printf("%s", mensaje);
    scanf("%[^\n]", input);
}

int getStringNumeros(char mensaje[],char input[]){
    
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringLetras(char mensaje[],char input[]){
    
    char aux[600];
    int i;
    unsigned long auxiliarLenght;
    
    getStringSpace(mensaje,aux);
    if(esSoloLetras(aux)){
        
        auxiliarLenght = strlen(aux);
        for (i = 0; i < auxiliarLenght; i++) {
            aux[i] = tolower(aux[i]);
        }
        aux[0] = toupper(aux[0]);
        
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


void getValidStringTitle(char mensaje[], char input[]){
    
    char auxiliar[50];
    int i;
    unsigned long auxiliarLenght;
    
    while (1) {
        
        getStringSpace(mensaje, auxiliar);
        
        auxiliarLenght = strlen(auxiliar);
        if (auxiliarLenght>50) {
            
            printf("El titulo debe tener como maximo 49 caracteres");
            continue;
        }
        break;
    }
    
    for (i = 0; i < auxiliarLenght; i++) {
        auxiliar[i] = tolower(auxiliar[i]);
    }
    auxiliar[0] = toupper(auxiliar[0]);
    
    strcpy(input, auxiliar);
}

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit){
    
    char auxStr[256];
    int auxInt;
    while(1){
        
        if (!getStringNumeros(requestMessage,auxStr)){
            printf ("%s\n",errorMessage);
            continue;
        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit){
            printf ("\nEl numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;
        }
        return auxInt;
    }
}

void getValidStringDescription(char requestMessage[],char errorMessage[], char input[]){
    
    unsigned long stringLen;
    while(1){
        if (!getStringLetras(requestMessage,input)){
            printf ("%s\n",errorMessage);
            continue;
        }
        
        stringLen = strlen(input);
        if(stringLen > 500){
            
            printf ("\nLa descripcion debe tener como maximo 499 caracteres\n");
            continue;
        }
        break;
    }
}


void getValidStringGenero(char requestMessage[],char errorMessage[], char input[]){
    
    unsigned long stringLen;
    while(1){
        if (!getStringLetras(requestMessage,input)){
            printf ("%s\n",errorMessage);
            continue;
        }
        
        stringLen = strlen(input);
        if(stringLen > 20){
            
            printf ("\nEl genero debe tener como maximo 19 caracteres\n");
            continue;
        }
        break;
    }
}

void getValidStringLink(char mensaje[], char input[]){
    
    char auxiliar[200];
    int i;
    unsigned long auxiliarLenght;
    
    while (1) {
        
        getStringSpace(mensaje, auxiliar);
        
        auxiliarLenght = strlen(auxiliar);
        if (auxiliarLenght>200) {
            
            printf("El link debe tener como maximo 199 caracteres");
            continue;
        }
        break;
    }
    
    for (i = 0; i < auxiliarLenght; i++) {
        auxiliar[i] = tolower(auxiliar[i]);
    }
    auxiliar[0] = toupper(auxiliar[0]);
    
    strcpy(input, auxiliar);
}
