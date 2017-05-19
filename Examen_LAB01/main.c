#include <stdio.h>
#include <stdlib.h>
#include "Usuarios.h"
#include "Productos.h"
#define uELEMENTS 5
#define pELEMENTS 5
#define VENDIDO 2

int main()
{
    char seguir='s';
    int opcion=0, i;
    //VARIABLES USUARIO
    eUsuario arrayUsuarios[uELEMENTS];
    int vaciarDatos, lugarLibre, altaUsuario, idUsuario =  0, modicaUsuario, idAModificar, deleteUsuario, idAEliminar,  posicionUsuario, id;
    vaciarDatos = initUsuario(arrayUsuarios, uELEMENTS);
    //VARIABLES PRODUCTOS
    eProducto arrayProductos[pELEMENTS];
    int vaciarDatosP, lugarFree, publicaProducto, idProducto =  0, idP, modificaProducto, idAModificarP,idU, idAEliminarP, retorno, posicionProducto, cantidadVendida = 0, puntaje, acumuladorPuntajes = 0, promedioPuntaje;
    vaciarDatosP = initProducto(arrayProductos, pELEMENTS);

//    HarcodeoUsuarios(arrayUsuarios, uELEMENTS);
 //   HarcodeoProductos(arrayProductos, pELEMENTS);
    while(seguir=='s')
    {
        printf("1- Alta usuario\n");
        printf("2- Modificar usuario\n");
        printf("3- Baja del usuario\n");
        printf("4- Publicar producto\n");
        printf("5- Modificar Publicacion\n");
        printf("6- Cancelar Publicacion\n");
        printf("7- Comprar Producto\n");
        printf("8- Listar publicaciones de usuario\n");
        printf("9- Listar productos publicados\n");
        printf("10- Listar Usuarios\n");
        printf("0- Salir\n");

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
                scanf("%d", &idAEliminar);
                deleteUsuario = bajaUsuario(arrayUsuarios, uELEMENTS, idAEliminar);
                if(deleteUsuario==0)
                {
                    printf("El usuario con ID %d se ha eliminado correctamente", idAEliminar);
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
                    }
                    else{
                        printf("Algo  pasó, probablemente el  id no  exista");
                        system("pause");
                        system("cls");
                    }
                }

                break;
            case 5:
                printf("Ingrese el  ID del usuario: ");
                scanf("%d", &idU);
                if(BuscarYMostrarPorIDP(arrayProductos, pELEMENTS, idU, arrayUsuarios, uELEMENTS )==0)
                {
                    printf("Ingrese el  ID del producto que desea modificar: ");
                    scanf("%d", &idAModificarP);
                    modificaProducto = ModificarProducto(arrayProductos, pELEMENTS, idAModificarP);
                    if(modificaProducto ==0)
                    {
                        printf("Se ha modificado correctamente");
                    }
                }
                else{
                    printf("El usuario ingresado no tiene publicaciones\n");
                    system("pause");
                    system("cls");
                }
                break;
            case 6:
                printf("Ingrese el  ID del usuario: ");
                scanf("%d", &idU);
                retorno = BuscarYMostrarPorIDP(arrayProductos, pELEMENTS, idU, arrayUsuarios, uELEMENTS );
                printf("retornp %d\n", retorno);
                if(retorno==0)
                {
                    printf("Ingrese el  ID del producto que desea eliminar: ");
                    scanf("%d", &idAModificarP);
                    modificaProducto = DeleteProducto(arrayProductos, pELEMENTS, idAModificarP);
                    if(modificaProducto ==0)
                    {
                        printf("Se ha eliminado el producto");
                    }
                }
                else{
                    printf("El usuario ingresado no tiene publicaciones\n");
                    system("pause");
                    system("cls");
                }
                break;
            case 7:
                printf("Ingrese el  ID del Producto que desea comprar: ");
                scanf("%d", &idP);
                retorno =  ComprarProducto(arrayProductos, pELEMENTS, idP, arrayUsuarios,  uELEMENTS);
                if(retorno > 0)
                {
                    posicionProducto = BuscarPosicionPorIDP(arrayProductos, pELEMENTS, idP);
                    cantidadVendida = cantidadVendida +1;
                    arrayProductos[posicionProducto].cantidadVendida = cantidadVendida;

                    printf("Compra exitosa\n");
                    system("pause");

                    idU = BuscarPosicionPorID(arrayUsuarios, uELEMENTS, retorno);
                    //printf("____%d", idU);

                    printf("Ingrese el puntaje por la compra: \n");
                    scanf("%d", &puntaje);

                    acumuladorPuntajes = acumuladorPuntajes + puntaje;

                    //printf("acum %d", acumuladorPuntajes);

                    promedioPuntaje = acumuladorPuntajes/ arrayProductos[posicionProducto].cantidadVendida;

                    //printf("PROMEDIO %d", promedioPuntaje);
                    arrayUsuarios[idU].calificacion = promedioPuntaje;

                }
                //printf("no  entro");
                system("pause");
                system("cls");

                break;
            case 8:
                printf("Ingrese el  ID del usuario: ");
                scanf("%d", &idU);
                retorno=BuscarYMostrarPorIDP(arrayProductos, pELEMENTS, idU, arrayUsuarios, uELEMENTS);
                system("pause");
                system("cls");
                break;
            case 9:
                MostrarListaProductos(arrayProductos, pELEMENTS,arrayUsuarios, uELEMENTS);
                system("pause");
                system("cls");
                break;
            case 10:
                OrdenarUsuarioPorNombre(arrayUsuarios, uELEMENTS);
                MostrarListaUsuarios(arrayUsuarios, uELEMENTS);
                system("pause");
                system("cls");
                break;
            case 0:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
