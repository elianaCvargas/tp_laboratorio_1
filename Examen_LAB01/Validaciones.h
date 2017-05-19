#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString( char mensaje[], char input[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[]);

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error de tipo
 * \param errorMessageLenght Es el mensaje a ser mostrado en caso de error de longitud
 * \param input Array donde se cargará el texto ingresado
 * \param maxLenght int Longitud maxima del texto ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el String -1 si no
 *
 */
int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps);

//NUMEROS FLOTANTES
/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char* mensaje);



/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumericoFlotante(char str[]);


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char mensaje[],char input[]);

/**
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Es el limite inferior aceptado
 * \param lowLimit Es el limite superior aceptado
 * \param input puntero al lugar donde se cargará el numero ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el Numero -1 si no
 *
 */
int getValidFloat(char requestMessage[],char errorMessage[], float* input,float lowLimit, float hiLimit,int attemps);

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char* mensaje);
/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumerico(char str[]);
/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[]);
/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param errorMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Es el limite inferior aceptado
 * \param lowLimit Es el limite superior aceptado
 * \param input puntero al lugar donde se cargará el numero ingresado
 * \param attemps indica la cantidad de reintentos ante un error
 * \return 0 si consiguio el Numero -1 si no
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,int attemps);

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char* mensaje);
/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[]);
/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[]);

