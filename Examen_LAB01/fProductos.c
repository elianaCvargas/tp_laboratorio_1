#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuarios.h"
#include "Productos.h"
#include "Validaciones.h"
#define COMPRADO 2

int initProducto(eProducto* producto, int length)
{
    int i;
    int retorno=-1;
    if(producto != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            (producto+i)->flag = 0;
        }
        retorno = 0;
    }
    return retorno;
}


int buscarLugarLibreP(eProducto* producto, int length)
{
    int i;
    int retorno=-1;
    if(producto != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            if((producto+i)->flag == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int addToArrayP(eProducto* producto, int lengthP, int id, eUsuario* usuario,int lengthU)
{
    int retorno = -1, i, auxStock;
    int  dato;
    float auxPrecio;
    char auxNombre[50];
    //system("clear");
    if(producto != NULL && lengthP > 0)
    {
        dato = BuscarUsuarioPorID(usuario,lengthU, id);
        if(dato>0)
        {
            for (i = 0; i<lengthP ; i++)
            {

                if ((producto+i)->flag == 0)
                {

                    retorno = getValidString("\nNombre: ","\nNo es un nombre valido","\nLongitud maxima 50", auxNombre,50,5);
                    if(retorno==0)
                    {
                        retorno = getValidFloat("\nPrecio: ","\nNo es un precio valido", &auxPrecio,10,999999999, 5);
                        if(retorno ==0)
                        {
                            retorno = getValidInt("\nStock: ","\nLa cantidad no es valida", &auxStock,0,999999999,5);
                            if(retorno ==0)
                           {
                                strcpy((producto+i)->nombreProducto, auxNombre);
                                (producto+i)->precio =auxPrecio;
                                (producto+i)->stock = auxStock;
                                (producto+i)->idUsuario = dato;//o  ID
                                (producto+i)->flag= 1;
                                retorno = 0;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
 return retorno;
}
int BuscarProductoPorID(eProducto* producto, int length,  int id)//devuelve -1 si  no  lo  encontro, me devuerlve el id si  lo  encuentro
{
    int retorno=-1, i;
    if(producto != NULL && length > 0)
    {
        for(i= 0; i<length; i++)
        {
            if ((producto+i)->flag != -1 && (producto+i)->flag != 0)
            {
                if((producto+i)->idProducto ==id)
                {
                    retorno = (producto+i)->idProducto;
                    break;
                }
            }
        }
    }
    return retorno;
}


int BuscarYMostrarPorIDP(eProducto* usuarioP, int length,int id, eUsuario* usuario, int lengthU)//devuelve -1 si  no  lo  encontro, me devuerlve el id si  lo  encuentro
{
    int retorno=-1, i;
    if(usuarioP != NULL && length > 0)
    {
        for(i= 0; i<length; i++)
        {
            if ((usuarioP+i)->flag != -1 && (usuarioP+i)->flag != 0)
            {
                if((usuarioP+i)->idUsuario ==id )
                {
                    printf("El ID usuario es: %d \n", (usuarioP+i)->idUsuario);
                    printf(" ID Producto: %d\t Nombre Producto: %s Precio: %2.f\t Stock: %d\t\n", (usuarioP+i)->idProducto,(usuarioP+i)->nombreProducto, (usuarioP+i)->precio, (usuarioP+i)->stock );

                    retorno = 0;
                    continue;
                }
            }
        }
    }
    return retorno;
}

int BuscarPosicionPorIDP(eProducto* producto, int length,  int id)//devuelve -1 si  no  lo  encontro, me devuerlve el id si  lo  encuentro
{
    int retorno=-1, i;
    if(producto != NULL && length > 0)
    {
        for(i= 0; i<length; i++)
        {
            if ((producto+i)->flag != -1 && (producto+i)->flag != 0)
            {
                if((producto+i)->idProducto ==id)
                {
                    retorno = i;
                    break;
                }
            }
        }
    }
    return retorno;
}


int ModificarProducto(eProducto* producto, int length, int idP/*,eUsuario* usuario, int lengthU,int idU*/)
{
    int retorno = -1, i;
    float auxPrecio;
    int dato, auxStock, posicionP;

    dato = BuscarProductoPorID(producto, length, idP);
    posicionP = BuscarPosicionPorIDP(producto, length, idP);
    if(producto != NULL && length > 0)
    {

        if(dato==idP)
        {


            for (i = 0; i<length ; i++)
            {
                if ((producto+i)->flag ==1)
                {
                    retorno = getValidFloat("\nPrecio: ","\nNo es un precio valido", &auxPrecio,10,999999999, 5);
                    if(retorno ==0)
                    {
                        retorno = getValidInt("\nStock: ","\nLa cantidad no es valida", &auxStock,0,999999999,5);
                        if(retorno ==0)
                        {
                                        (producto+posicionP)->precio =auxPrecio;
                                        (producto+posicionP)->stock = auxStock;
                                        retorno = 0;
                                        break;
                        }
                    }
                }

            }


        }


    }
 return retorno;
}


int DeleteProducto(eProducto* producto, int length, int idP/*,eUsuario* usuario, int lengthU,int idU*/)
{
    int retorno = -1, i;
    int dato;

    dato = BuscarProductoPorID(producto, length, idP);
    //posicionP = BuscarPosicionPorIDP(producto, length, idP);
    if(producto != NULL && length > 0)
    {
        if(dato==idP)
        {

            for (i = 0; i<length ; i++)
            {
                if ((producto+i)->flag ==1)
                {
                    (producto+i)->flag = -1;
                    retorno = 0;
                    break;
                }

            }


        }

    }
 return retorno;
}
int ComprarProducto(eProducto* producto, int length, int idP, eUsuario* usuario, int lengthU)
{
    int retorno = -1, i;
    int dato,  posicionP;
    dato = BuscarProductoPorID(producto, length, idP);
    posicionP = BuscarPosicionPorIDP(producto, length, idP);
    if(producto != NULL && length > 0)
    {
        if(dato==idP)
        {
            if((producto+posicionP)->stock >0)
            {


                for (i = 0; i<length ; i++)
                {
                    if ((producto+i)->flag ==1 || (producto+i)->flag ==COMPRADO)
                    {
                        (producto+i)->flag = COMPRADO;
                        retorno =(producto+i)->idUsuario;//quiero  me devuelva el id del  usuario
                        break;
                    }

                }
                (producto+posicionP)->stock  = (producto+posicionP)->stock -1;
                //(producto+posicionP)->cantidadVendida  = (producto+posicionP)->cantidadVendida +1;
               // producto[posicionP].cantidadVendida = producto[posicionP].cantidadVendida+1;

            }
            else{
                printf("No hay  stock para vender\n");
            }
        }
        else{
            printf("El id que ingreso,  no existe o  dejo de existir\n");
        }

    }
 return retorno;
}

int BuscarYMostrarProducto(eProducto* producto, int length,int id)//devuelve -1 si  no  lo  encontro, me devuerlve el id si  lo  encuentro
{
    int retorno=-1, i;
    if(producto != NULL && length > 0)
    {
        for(i= 0; i<length; i++)
        {
            if ((producto+i)->flag != -1 && (producto+i)->flag != 0)
            {

                    //printf("El ID usuario es: %d \n", (usuarioP+i)->idUsuario);
                    printf(" ID Producto: %d\t Nombre Producto: %s Precio: %2.f\t Stock: %d\t Cantidad Vendida: %d\n", (producto+i)->idProducto,(producto+i)->nombreProducto, (producto+i)->precio, (producto+i)->stock, (producto+i)->cantidadVendida);

                    retorno = 0;
                    continue;

            }
        }
    }
    return retorno;
}
void MostrarListaProductos(eProducto* producto,  int length, eUsuario* usuario, int lengthU)
{
    int i, dato;
    if(producto != NULL && length > 0)
    {
        for(i = 0; i <length; i++)//recorro el array de producto
        {
            dato = BuscarPosicionPorID(usuario, length,producto[i].idUsuario);
            if((producto+i)->flag ==1 || (producto+i)->flag ==COMPRADO )
            {
                printf("Nombre Usuario: %s: \t ID Producto: %d\t Nombre Producto:\t %s Precio: %2.f\t Stock: %d \t Cantidad Vendida: %d\n",(usuario+dato)->nombreUsuario, (producto+i)->idProducto,(producto+i)->nombreProducto, (producto+i)->precio, (producto+i)->stock, (producto+i)->cantidadVendida );

            }

        }
    }

}




/*void HarcodeoProductos(eProducto* producto, int length)
{

        producto[0].idProducto = 1;
        producto[0].idUsuario = 1;
        strcpy(producto[0].nombreProducto, "Cuaderno");
        producto[0].precio = 120;
        producto[0].stock = 5;
        producto[0].cantidadVendida = 2;
        producto[0].flag = 1;


        producto[0].idProducto = 2;
        producto[0].idUsuario = 1;
        producto[0].precio = 200;
        strcpy(producto[0].nombreProducto, "Hojas A4");
        producto[0].stock = 9;
        producto[0].cantidadVendida = 1;
        producto[0].flag = 1;





}*/
