#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void obtenerDatosPorTeclado( char mensaje[], char input[])
{
    printf(mensaje);
    fflush(stdin);
    scanf("%s", input);
}

int validarSoloLetras(char soloString[])
{
    int i= 0;
    while (soloString[i] != '\0')
    {
        if ((soloString[i]!= ' ') && (soloString[i] < 'a' || soloString[i] > 'z') && (soloString[i]< 'A' || soloString[i]> 'Z'))
            return 0;
        i++;
    }
    return 1;
}


int getStringValidado(char mensaje[], char input[])
{
    char auxInput[50];
    obtenerDatosPorTeclado(mensaje, auxInput);
    if(validarSoloLetras(auxInput))
    {
        strcpy(input, auxInput);
        return 1;
    }
    return 0;
}

int esNumerico(char strInput[])
{
   int i=0;
   while(strInput[i] != '\0')
   {
       if(strInput[i] < '0' || strInput[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

int getNumerosString(char mensaje[],char input[])
{
    char aux[256];
    obtenerDatosPorTeclado(mensaje,input);
    if(esNumerico(aux))//&& strlen(esNumerico(aux)) > 9
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


