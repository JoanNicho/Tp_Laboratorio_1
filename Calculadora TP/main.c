#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
int main()
{
    float numeroA=0;
    float numeroB=0;
    int opcion;
    float suma;
    float resta;
    float multiplicacion;
    float division;
    float facA;
    float facB;

    do
    {
        system("cls");
        printf("Calculadora\n");
        printf("\n1. Ingresar 1er operando (A=%f).",numeroA);
        printf("\n2. Ingresar 2do operando (B=%f).",numeroB);
        printf("\n3. Calcular todas las operaciones");
        printf("\n. Calcular la suma (A+B)");
        printf("\n. Calcular la resta (A-B)");
        printf("\n. Calcular la division (A/B)");
        printf("\n. Calcular la multiplicacion (A*B)");
        printf("\n. Calcular el factorial (A!)");
        printf("\n4.Informar resultados");
        printf("\n5. Salir");
        printf("\nElija una opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {

        case 1://Pedir operando 1.

            printf("\n1. Ingresar 1er operando: ");
            scanf("%f",&numeroA);
            break;

        case 2://Pedir operando 2.

            printf("\n2. Ingresar 2do operando: ");
            scanf("%f",&numeroB);
            break;

        case 3:
            //Operacion de suma.

            suma=sumar(numeroA,numeroB);

            //Operacion de resta.

            resta=restar(numeroA,numeroB);

            //Operacion de division.

            division=dividir(numeroA,numeroB);

            //Operacion de multiplicacion.

            multiplicacion=multiplicar(numeroA,numeroB);

            //Operacion de factorial.

            factorial(numeroA,numeroB,&facA,&facB);

            system("pause");
            break;

        case 4:

            printf("\n.La suma (A+B): %f\n",suma);
            printf("\n.La resta (A-B): %f\n",resta);
            printf("\n.La division (A/B): %f\n",division);
            printf("\n.La multiplicacion (A*B): %f\n",multiplicacion);
            printf("\n.El factorial es (A!): %f Y el factorial de B es (B!): %f\n",facA,facB);
            system("pause");
            break;
        case 5:
            break;

        default:
            printf("\nLa operacion ingesada es incorrecta, vuelva a intentar\n");
            system("pause");
        }
    }
    while(opcion != 5);
    return 0;
}



