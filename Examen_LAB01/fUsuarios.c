#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuarios.h"
#include "Validaciones.h"
/*int initUsuario(eUsuario* usuario, int length)
{
    int retorno = 0;
    int i;
    for (i = 0; i<length ; i++)
    {
        usuario[i].flag = 0;
    }
 return retorno;
}*/


int initUsuario(eUsuario* usuario, int length)
{
    int i;
    int retorno=-1;
    if(usuario != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            (usuario+i)->flag = 0;
        }
        retorno = 0;
    }
    return retorno;
}

/*int buscarLugarLibreU(eUsuario* usuario, int length)
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
}*/

int buscarLugarLibreU(eUsuario* usuario, int length)
{
    int i;
    int retorno=-1;
    if(usuario != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            if((usuario+i)->flag == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int addToArrayU(eUsuario* usuario, int length)
{
    int retorno = -1, i;
    char auxNombre[50], auxPass[50];
     if(usuario != NULL && length > 0)
    {
        for (i = 0; i<length ; i++)
        {
            if ((usuario+i)->flag == 0)
            {
                if(getValidString("\nNombre usuario: ","\nNo es un nombre valido","\nLongitud maxima 50", auxNombre,50,3)==0)
                {
                    if(getValidString("\nPassword: ","\nNo es una contraseña valida","\nLongitud maxima 50", auxPass,50,3)==0)
                    {

                        strcpy((usuario+i)->nombreUsuario, auxNombre);
                        strcpy((usuario+i)->Password, auxPass);
                        (usuario+i)->flag = 1;
                        retorno = 0;
                        break;
                    }
                }
            }
        }
    }
 return retorno;
}

int BuscarUsuarioPorID(eUsuario* usuario, int length,  int id)//devuelve -1 si  no  lo  encontro, me devuerlve el id si  lo  encuentro
{
    int retorno=-1, i;
    if(usuario != NULL && length > 0)
    {
        for(i= 0; i<length; i++)
        {
            if ((usuario+i)->flag != -1 && (usuario+i)->flag != 0)
            {
                if((usuario+i)->idUsuario ==id)
                {
                    retorno = (usuario+i)->idUsuario;
                    break;
                }
            }
        }
    }
    return retorno;
}

int BuscarPosicionPorID(eUsuario* usuario, int length,  int id)//devuelve -1 si  no  lo  encontro, me devuerlve el id si  lo  encuentro
{
    int retorno=-1, i;
    if(usuario != NULL && length > 0)
    {
        for(i= 0; i<length; i++)
        {
            if ((usuario+i)->flag != -1 && (usuario+i)->flag != 0)
            {
                if((usuario+i)->idUsuario ==id)
                {
                    retorno = i;
                    break;
                }
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
    if(usuario != NULL && length > 0)
    {
        if(dato>0)
        {
            for (i = 0; i<length ; i++)
            {



                if ((usuario+i)->flag == 1)
                {
                    if(getValidString("\nNombre usuario: ","\nNo es un nombre valido","\nLongitud maxima 50", auxNombre,50,3)==0)
                    {
                        if(getValidString("\nPassword: ","\nNo es una contraseña valida","\nLongitud maxima 50", auxPass,50,3)==0)
                        {

                            strcpy((usuario+i)->nombreUsuario, auxNombre);
                            strcpy((usuario+i)->Password, auxPass);
                            (usuario+i)->flag = 1;
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


int bajaUsuario(eUsuario* usuario, int length, int id)
{
    int retorno =  -1, i, dato;
    dato =  BuscarUsuarioPorID(usuario, length,  id);
    if(usuario != NULL && length > 0)
    {
        if(dato>0 )//FIJARSE DE QYE EL USUARIO  ECXISTA
        {

            for (i = 0; i<length ; i++)
            {
                (usuario+i)->flag = -1;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

void MostrarListaUsuarios(eUsuario* usuario,  int length)
{
    int i;
    if(usuario != NULL && length > 0)
    {
        for (i = 0; i<length ; i++)
        {
            if((usuario+i)->flag == 1)
            {
                printf("ID Usuario: %d\t Nombre Usuario: %s: \t  Calificacion: \n",(usuario+i)->idUsuario,(usuario+i)->nombreUsuario, (usuario+i)->calificacion);

            }
        }
    }
}

void OrdenarUsuarioPorNombre(eUsuario* listaUsuario, int length)
{
    int i;
    eUsuario aux;
    int flag = 1;

    while(flag)
    {
        flag = 0;
        for (i = 1; i < length; i++)
        {
            if(stricmp((listaUsuario+i)->nombreUsuario,((listaUsuario+i)-1)->nombreUsuario)<0)
            {
                aux = listaUsuario[i];
                listaUsuario[i]= listaUsuario[i-1];
                listaUsuario[i-1] = aux;
                flag = 1;
            }
        }
    }
}


/*void HarcodeoUsuarios(eUsuario* usuario, int length)
{

    (usuario+1)->idUsuario= 1;
    strcpy((usuario+1)->nombreUsuario,"Eliana" );

    strcpy((usuario+1)->Password,"contra" );
    (usuario+1)->flag= 1;
    (usuario+1)->calificacion= 8;














}*/
