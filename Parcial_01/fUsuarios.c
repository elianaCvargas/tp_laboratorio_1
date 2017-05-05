#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuarios.h"
int initUsuario(eUsuario* usuario, int length)
{
    int retorno = 0;
    int i;
    for (i = 0; i<length ; i++)
    {
        usuario[i].flag = 0;
    }
 return retorno;
}

int buscarLugarLibreU(eUsuario* usuario, int length)
{
    int retorno=-1, i;
    for(i= 0; i<length; i++)
    {
        if(usuario[i].flag ==0)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int addToArrayU(eUsuario* usuario, int length)
{
    int retorno = -1, i;
    char auxNombre[50], auxPass[50];

    for (i = 0; i<length ; i++)
    {
        if (usuario[i].flag == 0)
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
            strcpy(usuario[i].nombreUsuario, auxNombre);
            strcpy(usuario[i].Password, auxPass);
            usuario[i].flag = 1;
            retorno = 0;
            break;
        }

    }
 return retorno;
}


int BuscarUsuarioPorID(eUsuario* usuario, int length,  int id)//devuelve -1 si  no  lo  encontro, me devuerlve el id si  lo  encuentro
{
    int retorno=-1, i;
    for(i= 0; i<length; i++)
    {
        if (usuario[i].flag != -1 && usuario[i].flag != 0)
        {
            if(usuario[i].idUsuario ==id)
            {
                retorno = usuario[i].idUsuario;
                break;
            }
        }

    }
    return retorno;
}


int ModificarUsuario(eUsuario* usuario, int length, int id)
{
    int retorno = -1, i;
    char auxNombre[50], auxPass[50];
    int dato;
    dato = BuscarUsuarioPorID(usuario, length, id);
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
                strcpy(usuario[i].nombreUsuario, auxNombre);
                strcpy(usuario[i].Password, auxPass);
                //usuario[i].flag = 1;
                retorno = 0;
                break;
        }
    }
 return retorno;
}


int bajaUsuario(eUsuario* usuario, int length, int id)
{
    int retorno =  -1, i, dato;
    dato =  BuscarUsuarioPorID(usuario, length,  id);
    if(dato>0)//si  lo  encontro
    {
        for (i = 0; i<length ; i++)
        {
            usuario[i].flag = -1;
            retorno = 0;
            break;
        }
    }
    return retorno;
}


