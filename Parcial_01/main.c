#include <stdio.h>
#include <stdlib.h>
#include "Usuarios.h"
#include "Productos.h"
#define uELEMENTS 5
#define pELEMENTS 5

int main()
{
    char seguir='s';
    int opcion=0, i;
    //VARIABLES USUARIO
    eUsuario arrayUsuarios[uELEMENTS];
    int vaciarDatos, lugarLibre, altaUsuario, idUsuario =  0, modicaUsuario, idAModificar, deleteUsuario;
    vaciarDatos = initUsuario(arrayUsuarios, uELEMENTS);

    //VARIABLES PRODUCTOS
    eProducto arrayProductos[pELEMENTS];
    int vaciarDatosP, lugarFree, publicaProducto, idProducto =  0, id/* modicaUsuario, idAModificar, deleteUsuario*/;

    vaciarDatosP = initProducto(arrayProductos, pELEMENTS);
    /*for (i = 0; i<pELEMENTS ; i++)
    {
        printf("%d\n", arrayProductos[i].flag);
    }*/

    while(seguir=='s')
    {
        printf("1- Alta usuario\n");
        printf("2- Modificar usuario\n");
        printf("3- Baja del usuario\n");
        printf("4- Publicar producto\n");
        printf("5- Publicar producto\n");
        printf("6- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                lugarLibre = buscarLugarLibreU(arrayUsuarios,  uELEMENTS);
                if(lugarLibre < 0)
                {
                    printf("No hay  espacio para seguir ingresando datos!");
                    system("pause");
                    system("cls");
                    break;
                }
                else{
                    altaUsuario = addToArrayU(arrayUsuarios, uELEMENTS);

                    if(altaUsuario ==0)
                    {
                        printf("El Usurario se ha ingresado correctamente.\n");
                        system("pause");
                        system("cls");
                    }
                    idUsuario = idUsuario+1;
                    arrayUsuarios[lugarLibre].idUsuario = idUsuario;

                }
                break;
            case 2:
                printf("Ingrese el ID que desee modificar\n");
                scanf("%d", &idAModificar);
                modicaUsuario =  ModificarUsuario(arrayUsuarios, uELEMENTS, idAModificar);
                if(modicaUsuario==0)
                {
                    printf("El ID: %d, se ha modificado correctamente",idAModificar );
                    system("pause");
                    system("cls");
                    break;
                }
                else{
                    printf("No  se ha encontrado  el id\n");
                    system("pause");
                    system("cls");
                    break;
                }

                break;
            case 3:
                printf("Ingrese el ID que desee modificar\n");
                scanf("%d", &idAModificar);
                deleteUsuario = bajaUsuario(arrayUsuarios, uELEMENTS, idAModificar);
                if(deleteUsuario==0)
                {
                    printf("El usuario con ID %d se ha eliminado correctamente", idAModificar);
                }
                else{
                    printf("Something happened...");
                }
                break;
            case 4:
                lugarFree = buscarLugarLibreP(arrayProductos, pELEMENTS);
                if(lugarFree < 0)
                {
                    printf("No hay  espacio para seguir ingresando datos!");
                    system("pause");
                    system("cls");
                    break;
                }
                else{
                    printf("Ingrese el  ID del usuario: ");
                    scanf("%d", &id);
                    publicaProducto = addToArrayP(arrayProductos, pELEMENTS, id, arrayUsuarios, uELEMENTS);
                    if(publicaProducto == 0)
                    {
                        printf("Se ha publicado correctamente\n");
                        system("pause");
                        system("cls");

                        idProducto = idProducto+1;
                        arrayProductos[lugarFree].idProducto = idProducto;
                       // arrayUsuarios[lugarFree].cantProductos = idProducto;


                    }
                    else{
                        printf("Algo  pasò, probablemente el  id no  exista");
                        system("pause");
                        system("cls");
                    }
                }

                break;
            case 5:

                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                for (i = 0; i<uELEMENTS ; i++)
                {
                    printf("%d\t %d \t %s\n", arrayProductos[i].flag, arrayProductos[i].idProducto, arrayProductos[i].nombreProducto);
                }
                break;
            case 10:
                for (i = 0; i<uELEMENTS ; i++)
                {
                    printf("%d\t %d \t %s\n", arrayUsuarios[i].flag, arrayUsuarios[i].idUsuario, arrayUsuarios[i].nombreUsuario);
                }
                break;
            case 0:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
