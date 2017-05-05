#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuarios.h"
#include "Productos.h"

int initProducto(eProducto* producto, int length)
{
    int retorno = 0;
    int i;
    for (i = 0; i<length ; i++)
    {
        producto[i].flag = 0;
    }
 return retorno;
}

int buscarLugarLibreP(eProducto* producto, int length)
{
    int retorno=-1, i;
    for(i= 0; i<length; i++)
    {
        if(producto[i].flag ==0)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}





int addToArrayP(eProducto* producto, int lengthP, int id, eUsuario* usuario,int lengthU)
{
    int retorno = -1, i, auxStock;
    int  auxPrecio, dato;
    char auxNombre[50];
    dato = BuscarUsuarioPorID(usuario,lengthU, id);
    if(dato>0)
    {
        for (i = 0; i<lengthP ; i++)
        {
            if (producto[i].flag == 0)
            {
                if(!getStringValidado("Nombre: ", auxNombre))
                {
                    printf("Solo debe contener letras\n");
                    system("pause");
                    system("cls");
                    break;
                }
                printf("Precio: ");
                scanf("%d", &auxPrecio);

                printf("Stock: ");
                scanf("%d", &auxStock);
               /* if(!getNumerosString("Precio: ", auxPrecio))
                {
                    printf("Solo debe contener numeros\n");
                    system("pause");
                    system("cls");
                    break;
                }
                if(!getNumerosString("Stock: ", auxStock))
                {
                    printf("Solo debe contener numeros\n");
                    system("pause");
                    system("cls");
                    break;
                }*/
                strcpy(producto[i].nombreProducto, auxNombre);
                producto[i].precio = auxPrecio;
                producto[i].stock = auxStock;
                producto[i].idUsuario = dato;//o  ID
                producto[i].flag = 1;
                retorno = 0;
                break;
            }
        }
    }

 return retorno;
}


int  mostrarProductosPorUsuario(eProducto* producto, int lengthP, int id, eUsuario* usuario,int lengthU)
{
    int retorno = -1;
    dato = BuscarUsuarioPorID(usuario,lengthU, id);
    for (i = 0; i<lengthP ; i++)
        {
            if (producto[i].flag == 1 && producto[i].idUsuario == dato )
            {
                printf("%d \t");

            }
        }

}



/*
int BuscarUsuarioPorID(eProducto* producto, int length,  int id)//devuelve -1 si  no  lo  encontro, me devuerlve el id si  lo  encuentro
{
    int retorno=-1, i;
    for(i= 0; i<length; i++)
    {
        if (producto[i].flag != -1 && producto[i].flag != 0)
        {
            if(producto[i].idUsuario ==id)
            {
                retorno = producto[i].idUsuario;
                break;
            }
        }

    }
    return retorno;
}


int ModificarProducto(eProducto* producto, int length, int id)
{
    int retorno = -1, i;
    char auxNombre[50], auxPass[50];
    int dato;
    dato = BuscarUsuarioPorID(producto, length, id);
    if(dato>0)
    {
        for (i = 0; i<length ; i++)
        {
            if(!getStringValidado("Nombre: ", auxNombre))
                {
                    printf("Solo debe contener letras\n");
                    system("pause");
                    system("cls");
                    break;
                }
                if(!getStringValidado("Password: ", auxPass))
                {
                    printf("Solo debe contener letras\n");
                    system("pause");
                    system("cls");
                    break;
                }
                strcpy(producto[i].nombreProducto, auxNombre);
                strcpy(producto[i].Password, auxPass);
                //producto[i].flag = 1;
                retorno = 0;
                break;
        }
    }
 return retorno;
}


int bajaProducto(eProducto* producto, int length, int id)
{
    int retorno =  -1, i, dato;
    dato =  BuscarUsuarioPorID(producto, length,  id);
    if(dato>0)//si  lo  encontro
    {
        for (i = 0; i<length ; i++)
        {
            producto[i].flag = -1;
            retorno = 0;
            break;
        }
    }
    return retorno;
}*/
