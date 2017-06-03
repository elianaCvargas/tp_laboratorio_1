#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#define cELEMENTS 20
#define EMPTY 0
#define DELETED -1
#define OCCUPIED 1


int altaPeliculas(eMovie *peliculas,int cantElementos)
{
    char auxTitulo[50], auxGenero[25],auxDuracion[4],auxPuntaje[3], auxLinkImagen[100], auxIdPeli[4] ;
    int ultimo_id = 0;


    int freeIndex;

    freeIndex = buscarLugarLibre(peliculas,cELEMENTS,-1);
        if (freeIndex == -1)
        {
            printf("No hay  espacio suficiente para seguir ingresando");
        }
    else
    {

        while(!getStringValidado("Ingrese titulo: ",auxTitulo))
        {
            printf("Error, solo letras!!\n");
        }
        while(!getStringValidado("Ingrese genero: ",auxGenero))
        {
            printf("Error, solo letras!!\n");
        }

        while(!getNumerosString("Ingrese duracion: ",auxDuracion))
        {
            printf("Error, solo numeros!\n");
        }

        obtenerDatosPorTeclado("Ingrese descripcion: ",peliculas[freeIndex].descripcion);

        while(!getNumerosString("Ingrese el puntaje: ",auxPuntaje))
        {
            printf("Error, solo numeros!\n");
        }

        obtenerDatosPorTeclado("Ingrese link de imagen: ",peliculas[freeIndex].linkImagen);

        strcpy(peliculas[freeIndex].titulo,auxTitulo);
        strcpy(peliculas[freeIndex].genero,auxGenero);
        peliculas[freeIndex].duracion=atoi(auxDuracion);
        peliculas[freeIndex].puntaje=atoi(auxPuntaje);
        peliculas[freeIndex].flag_estado = OCCUPIED;
        ultimo_id = ultimo_id +1;
        peliculas[freeIndex].id_movie = ultimo_id;

        return 1;
    }
    return 0;

}

/** \brief Realiza la baja logica de un elemento del array peliculas
 * \param el array peliculas
 * \param la cantidad de elementos que posee el array
 * \return 1 si la tarea se realizo, caso contrario 0
 *
 */

int bajaPeliculas(eMovie *peliculas,int cantElementos)
{
    int valFound, i;

    char auxID[4];

    for (i = 0 ; i < cantElementos ; i++)
    {
        if (peliculas[i].flag_estado == OCCUPIED)
        {
            printf( "\t Titulo: %s \t- ID: %d\n",peliculas[i].titulo,peliculas[i].id_movie);
        }
    }
    while (getNumerosString("Ingrese el  ID que desee eliminar: ", auxID) == -1)
    {
        printf("Error,  solo  numeros!\n");
    }

    valFound=buscarLugarLibre(peliculas,cantElementos,atoi(auxID));
    if(valFound ==1)
    {
        peliculas[valFound].flag_estado= DELETED;
        return 1;
    }
    else
    {
        printf("No se encuentra el  ID!");
    }
    return 0;
}

int modificarPeliculas(eMovie *peliculas,int cantElementos)
{
    int indice,valFound, i;

    char auxTituloStr[25],auxGeneroStr[25],auxDuracionStr[10],auxPuntajeStr[10];

    for (i = 0 ; i < cantElementos ; i++)
    {
        if (peliculas[i].flag_estado == OCCUPIED)
        {
            printf( "\t Titulo: %s \n",peliculas[i].titulo);
        }
    }
    indice=buscarLugarLibre(peliculas,cantElementos);

    if(indice == -1)
    {
        printf("Para esta opcion debe ingresar peliculas primero\n");
    }
    else
    {
        while(!getStringValidado("Ingrese el titulo de la pelicula a modificar: ",auxTituloStr))
        {
            printf("El titulo debe estar en letras!!\n");
        }

        valFound=buscarLugarLibre(peliculas,cantElementos,auxTituloStr);

        if(valFound == -1)
        {
            printf("La pelicula no existe.\n");
        }
        else
        {
            obtenerDatosPorTeclado("Ingrese titulo: ",peliculas[indice].titulo);

            while(!getStringValidado("Ingrese genero: ",auxGeneroStr))
            {
                printf("Solo letras por favor!\n");
            }

            while(!getNumerosString("Ingrese duracion: ",auxDuracionStr))
            {
                printf("Solo numeros por favor!\n");
            }

            obtenerDatosPorTeclado("Ingrese sinopsis: ",peliculas[valFound].descripcion);

            while(!getNumerosString("Ingrese el puntaje: ",auxPuntajeStr))
            {
                printf("Solo numeros por favor!\n");
            }

            obtenerDatosPorTeclado("Ingrese direccion URL: ",peliculas[valFound].linkImagen);

            strncpy(peliculas[valFound].genero,auxGeneroStr,100);
            peliculas[valFound].puntaje=atoi(auxPuntajeStr);
            peliculas[valFound].duracion=atoi(auxDuracionStr);

            return 1;
        }
    }
    return 0;
}
