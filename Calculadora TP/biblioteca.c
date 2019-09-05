#include <stdio.h>
#include "biblioteca.h"
float sumar(float numeroA, float numeroB)
{
    float resultado;

    resultado =(float) numeroA + numeroB;

    return resultado;
}
float restar(float numeroA, float numeroB)
{
    float resultado;

    resultado =(float) numeroA - numeroB;

    return resultado;
}
float dividir(float numeroA, float numeroB)
{
    float resultado;

    if(numeroB == 0)
    {
        printf("No es posible dividir por cero");
    }else
    {
      resultado = (float)  numeroA / numeroB;
    }

    return resultado;
}
float multiplicar(float numeroA, float numeroB)
{
    float resultado;

    resultado =(float) numeroA * numeroB;

    return resultado;
}
float factorial(float numeroA,float numeroB,float *facA,float *facB)
{

    float factA=1;
    float factB=1;
    int i;
    int j;

    for (i=numeroA; i >= 1; i--)
    {
        factA = factA*i;
    }

    for ( j=numeroB;j >= 1; j--)
    {
        factB = factB*j;
    }

    *facA=factA;
    *facB=factB;

    return 0;
}

