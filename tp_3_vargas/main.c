#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#define cELEMENTS 20
#define EMPTY 0
#define DELETED -1
#define OCCUPIED 1

int main()
{

    int opcion=0;
    int i, lugarLibre;
    eMovie peliculas[cELEMENTS];
    iniciarDatosArray(peliculas, cELEMENTS, EMPTY);
    hardcodear(peliculas, cELEMENTS);

    while(opcion != 6)
    {
        opcion = menu();
        switch(opcion)
        {
            case 1:
                if (altaPeliculas(peliculas, cELEMENTS)== 1)
                {
                    printf("Guardado con exito!\n");
                    system("pause");
                    system("cls");

                }
                else
                {
                    printf( "No ha podido ingresar la pelicula...\n");
                }
                break;
            case 2:
                if (bajaPeliculas( peliculas, cELEMENTS)== 1)
                {
                    printf("Eliminado con exito!\n");
                    system("pause");
                    system("cls");
                }
                else{
                    printf( "No ha podido eliminar la pelicula...\n");
                }
                break;
            case 3:
                if (modificarPeliculas( peliculas, cELEMENTS)== 1)
                {
                    printf("Modificado con exito!\n");
                    system("pause");
                    system("cls");
                }
                else{
                    printf( "No ha podido modificar la pelicula...\n");
                }
               break;
            case 4:
                if(generarArchBin( peliculas) == 1)
                {
                    printf("Se ha generado  el  archivo  con  exito");
                    system("pause");
                    system("cls");
                }
                else{
                    printf("No  se pudo  guardar!");
                }
               break;
            case 5:
                if (generarHTML(peliculas, cELEMENTS)== 1)
                {
                    printf("Se genero el html");
                    system("pause");
                    system("cls");

                }
                else{

                    printf("No pudo generar el html..");
                }
               break;
            case 6:
                /*//seguir = 'n';
                printf("puebas\n");
                for (i = 0; i < cELEMENTS; i++)
                {
                    if (peliculas[i].flag_estado == EMPTY)
                    {
                        printf( " estado : %d\n", peliculas[i].flag_estado);
                    }

                }
                for (i = 0; i < cELEMENTS; i++)
                {
                    if (peliculas[i].flag_estado == OCCUPIED)
                    {
                        printf( " estado : %d\t-Titulo: %s\t-Genero: %s\t-Descripcion: %d\t-Punjae: %d\t-Duracion: %d\t", peliculas[i].flag_estado,peliculas[i].titulo,peliculas[i].genero,peliculas[i].descripcion, peliculas[i].puntaje, peliculas[i].duracion );
                    }

                }
                system("pause");
                system("cls");*/
                printf("Salio");
                break;

        }
    }

    return 0;
}
