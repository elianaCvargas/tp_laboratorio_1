#include <stdio.h>
#include <stdlib.h>



float sumar(float numUno, float numDos);
float sumar(float numUno, float numDos)
    {
        float suma;
        suma = numUno+numDos;
        return suma;
    }

float restar(float numUno, float numDos);
float restar(float numUno, float numDos)
    {
        float resta;
        resta = numUno-numDos;
        return resta;
    }

float dividir(float numUno, float numDos);
float dividir(float numUno, float numDos)
    {
        float division;
        division = numUno/numDos;
        return division;
    }

float multiplicar(float numUno, float numDos);
float multiplicar(float numUno, float numDos)
    {
        float multiplica;
        multiplica = numUno*numDos;
        return multiplica;
    }

int factorial(int numero);
int factorial(int numero)
{
    int resultado;
    if (numero ==1)
    {
        return 1;
    }
    resultado =numero * (factorial(numero -1));
    return resultado;
}

void menu();
void menu()
{
    printf("Ingresar la opcion deseada:\n");
    printf("1. Sumar\n");
    printf("2. Restar\n");
    printf("3. Multiplicar\n");
    printf("4. Dividir\n");
    printf("5. Factorial\n");

}


int main()
{

    int opcionDeseada,factoriza, numeroF;
    float numeroUno, numeroDos, divide, suma,resta, multiplica;
    printf("Ingrese primer numero: ");
    scanf("%f", &numeroUno);
    printf("Ingrese segundo numero: ");
    scanf("%f", &numeroDos);
    menu();
    scanf("%d", &opcionDeseada);

    switch (opcionDeseada)
    {
        case 1:
            //Sumar
            suma =sumar(numeroUno, numeroDos);
            printf("La suma es: %.2f", suma );
            break;
        case 2:
            resta =restar(numeroUno, numeroDos);
            printf("La resta es: %.2f", resta );
            //Restar
            break;
        case 3:
            //Multiplicar
            multiplica =multiplicar(numeroUno, numeroDos);
            printf("La multiplicacion es: %.2f", multiplica );
            break;
        case 4:
            //Dividir
            divide =dividir(numeroUno, numeroDos);
            printf("La division es: %.2f", divide);
            break;
        case 5:
            //Factorial
            printf("Ingrese numero: ");
            scanf("%d", &numeroF);
            factoriza = factorial(numeroF);
            printf("Factorial es: %d", factoriza);

            break;
        default:
            printf("La opcion ingresada no es correcta...");

    }








    divide = dividir(numeroUno, numeroDos);










    return 0;
}
