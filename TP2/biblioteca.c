#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "biblioteca.h"
#define SIZE 1000
#define LLENO 1
#define VACIO -1

void Menu(eEmployee arrayEmployee[])
{
    int option;
    int indice;
    char seguir;
    int flag=0;

    do
    {
        printf("\n \tMENU DE OPCIONES\n");
        printf("\n\n1.ALTA\n\n2.BAJA\n\n3.MODIFICAR\n\n4.INFORME\n\n");
        printf(" \nElija una opcion: ");
        scanf("%d", &option);
        system("cls");
        switch(option)
        {
        case 1:
            flag=1;
            indice=ArraySpace(arrayEmployee,SIZE);
            if(indice!=VACIO)
            {
                addEmployees(arrayEmployee, SIZE,indice);
            }
            else
            {
                printf("No hay espacio\n");
            }
            break;
        case 2:
             if(flag==0)
            {
                printf("\n\nUsted debe cargar al empleado primero\n\n");
            }
            else
            {
                printEmployees(arrayEmployee,SIZE);
                printf(" \n\n                      DAR DE BAJA A EMPLEADOS   \n\n");
                removeEmployee(arrayEmployee,SIZE);
            }
            break;
        case 3:
             if(flag==0)
            {
                printf("\n\nUsted debe cargar al empleado primero\n\n");
            }
            else
            {
                printEmployees(arrayEmployee,SIZE);
                printf(" \n\n                      MODIFICAR EMPLEADOS    \n\n");
                modifyEmployee(arrayEmployee,SIZE);
            }
            break;
        case 4:
            if(flag==0)
            {
                printf("\n\nUsted debe cargar al empleado primero\n\n");
            }
            else
            {
                sortEmployeeByLastName(arrayEmployee,SIZE);
                sortEmployeeBySector(arrayEmployee,SIZE);
                totalAndAverageSalary(arrayEmployee,SIZE);
            }
            break;
        }
        printf("\n\nDesea volver al menu?\n\n1.para continuar \t2.para salir");
        seguir=getch();
        system("cls");
    }
    while(seguir =='1');
}

int findEmployeeById(eEmployee arrayEmployee[],int size)
{
    int i;
    for( i=0; i<size; i++)
    {
        if(arrayEmployee[i].isEmpty==VACIO)
        {
            arrayEmployee[i].id=i+1;
            break;
        }
    }
    return i;
}

void initEmployees(eEmployee arrayEmployee[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        arrayEmployee[i].isEmpty=VACIO;
    }

}

int ArraySpace(eEmployee arrayEmployee[],int size)
{
    int aux=VACIO;
    int i;

    for(i=0; i<size; i++)
    {
        if(arrayEmployee[i].isEmpty==VACIO)
        {
            aux=i;
            break;
        }
    }
    return aux;
}

void addEmployees(eEmployee arrayEmployee[],int size,int i)
{
    int n;
    int a;
    int flagName=0;
    int flagLastName=0;

    printf(" \n                      DAR DE ALTA A EMPLEADOS    \n\n");

    printf("ID es:%d",findEmployeeById(arrayEmployee,SIZE));

    printf("\nIngrese nombre: ");

    do
    {
        flagName= 0;

        fflush(stdin);

        gets(arrayEmployee[i].name);

        for(n=0; n<strlen(arrayEmployee[i].name); n++)
        {
            if((arrayEmployee[i].name[n] < 'a' || arrayEmployee[i].name[n] > 'z') &&
                    (arrayEmployee[i].name[n] < 'A' || arrayEmployee[i].name[n] > 'Z'))
            {
                printf("\nEl nombre solamente puede tener letras. Reingrese nombre: ");
                flagName = LLENO;
                break;
            }
        }
    }while(flagName);

    printf("\nIngrese apellido: ");
    do
    {
        flagLastName= 0;
        fflush(stdin);
        gets(arrayEmployee[i].lastName);
        for(a=0; a<strlen(arrayEmployee[i].lastName); a++)
        {
            if((arrayEmployee[i].lastName[a] < 'a' || arrayEmployee[i].lastName[a] > 'z') &&
                    (arrayEmployee[i].lastName[a] < 'A' || arrayEmployee[i].lastName[a] > 'Z'))
            {
                printf("\nEl apellido solamente puede tener letras. Reingrese apellido: ");
                flagLastName = LLENO;
                break;
            }
        }
    }while(flagLastName);

    printf("\nIngrese salario: ");
    scanf("%f", &arrayEmployee[i].salary);

    while(arrayEmployee[i].salary<0)
    {
        printf("\n\nReingrese salario: ");
        scanf("%f", &arrayEmployee[i].salary);
    }

    printf("\nIngrese sector: ");
    scanf("%d", &arrayEmployee[i].sector);

    while(arrayEmployee[i].sector<0)
    {
        printf("\n\nReingrese sector: ");
        scanf("%d", &arrayEmployee[i].sector);
    }
    arrayEmployee[i].isEmpty=LLENO;
}

void removeEmployee(eEmployee arrayEmployee[],int size)
{
    int flag=0;
    int aceptar;
    int auxId;
    int i;

    printf("\nIngrese el ID que desea dar de baja: ");
    scanf("%d", & auxId);

    for( i=0; i<size; i++)
    {
        if(arrayEmployee[i].isEmpty!=VACIO && auxId==arrayEmployee[i].id)
        {
            flag=1;
            printf("\nDesea dar de baja a este empleado?\n1.para continuar \t2.para salir");
            aceptar=getch();
            if(aceptar=='1')
            {
                printf("\n\nSe ha dado de baja a este empleado.\n");
                arrayEmployee[i].isEmpty=VACIO;
                break;
            }
            else if(aceptar!='1')
            {
                printf("\nPresione 1 para volver al menu o 2 para salir\n");
            }

        }

    }

    if(flag==0)
    {
        printf("\nNo existe ID ingresalo nuevamente\n");
    }
}

void modifyEmployee(eEmployee arrayEmployee[],int size)
{
    int option;
    int i;
    int n;
    int a;
    int auxId;
    int flag =0;
    char modify;
    int flagName=0;
    int flagLastName=0;

    printf("\nIngrese el ID que desea modificar : ");
    scanf("%d",&auxId);

    for(i=0; i<size; i++)
    {
        if(arrayEmployee[i].isEmpty!=VACIO && auxId==arrayEmployee[i].id)
        {
            do
            {
                system("cls");
                printf("\n\n1.NOMBRE\n\n2.APELLIDO\n\n3.SALARIO\n\n4.SECTOR\n\n");
                printf("\nQue desea modificar: ");
                scanf("%d",&option);
                system("cls");
                switch(option)
                {
                case 5:
                    printf("Ingrese un nuevo nombre: ");
                    do
                    {
                        flagName= 0;
                        fflush(stdin);
                        gets(arrayEmployee[i].name);
                        for( n=0; n<strlen(arrayEmployee[i].name); n++)
                        {
                            if((arrayEmployee[i].name[n] < 'a' || arrayEmployee[i].name[n] > 'z') &&
                               (arrayEmployee[i].name[n] < 'A' || arrayEmployee[i].name[n] > 'Z'))
                            {
                                printf("\nReingrese nuevo nombre: ");
                                flagName = LLENO;
                                break;
                            }
                        }
                    }
                    while(flagName);
                    break;

                case 6:
                    printf("\nIngrese nuevo apellido: ");
                    do
                    {
                        flagLastName= 0;
                        fflush(stdin);
                        gets(arrayEmployee[i].lastName);
                        for( a=0; a<strlen(arrayEmployee[i].lastName); a++)
                        {
                            if((arrayEmployee[i].lastName[a] < 'a' || arrayEmployee[i].lastName[a] > 'z') &&
                               (arrayEmployee[i].lastName[a] < 'A' || arrayEmployee[i].lastName[a] > 'Z'))
                            {
                                printf("\nReingrese nuevo apellido: ");
                                flagLastName = LLENO;
                                break;
                            }
                        }
                    }
                    while(flagLastName);
                    break;

                case 7:
                    printf("\nIngrese nuevo salario: ");
                    scanf("%f", &arrayEmployee[i].salary);
                    while(arrayEmployee[i].salary<0)
                    {
                        printf("\nReingrese nuevo salario: ");
                        scanf("%f", &arrayEmployee[i].salary);

                    }
                    break;

                case 8:
                    printf("\nIngrese nuevo sector: ");
                    scanf("%d", &arrayEmployee[i].sector);
                    while(arrayEmployee[i].sector<0)
                    {
                        printf("\nReingrese nuevo sector: ");
                        scanf("%d", &arrayEmployee[i].sector);

                    }
                    break;

                }
                printf("\nDesea modificar otro campo?\n1.para continuar \t2.para salir");
                modify=getch();
                system("cls");
            }
            while(modify=='1');

            flag=LLENO;
            break;
        }
    }
    if(flag==0)
    {
        printf("\nNo existe ID ingresalo nuevamente\n");
    }
}

void sortEmployeeByLastName(eEmployee arrayEmployee[],int size)
{
    int i;
    int j;
    eEmployee aux;
    printf("\n\nOrdenado alfabeticamente por apellido:\n\n");
    for(i=0; i< size-1; i++)
    {
        for(j=i+1; j<size; j++)
        {
            if(stricmp(arrayEmployee[i].lastName,arrayEmployee[j].lastName)>0)
            {
                aux=arrayEmployee[i];
                arrayEmployee[i]=arrayEmployee[j];
                arrayEmployee[j]=aux;
            }
        }
    }
    for (i=0; i<size; i++)
    {
        if(arrayEmployee[i].isEmpty==LLENO)
        {
            printf("  nombre:%10s  apellido:%10s  salario:%.2f  sector:%d\n",arrayEmployee[i].name,arrayEmployee[i].lastName,arrayEmployee[i].salary,arrayEmployee[i].sector);
        }
    }
}

void sortEmployeeBySector( eEmployee arrayEmployee[], int size)
{
    int i;
    int j;
    eEmployee aux;
    printf("\n\nOrdenado alfabeticamente por sector:\n\n");
    for(i=0;i<size-1;i++)
    {
        for(j=i+1; j<size; j++)
        {
            if(arrayEmployee[i].sector>arrayEmployee[j].sector)
            {
                aux=arrayEmployee[i];
                arrayEmployee[i]=arrayEmployee[j];
                arrayEmployee[j]=aux;
            }
        }
    }
    for (i=0; i<size; i++)
    {
        if(arrayEmployee[i].isEmpty==LLENO)
        {
            printf("  nombre:%10s  apellido:%10s  salario:%.2f  sector:%d\n",arrayEmployee[i].name,arrayEmployee[i].lastName,arrayEmployee[i].salary,arrayEmployee[i].sector);
        }
    }
}

void totalAndAverageSalary(eEmployee arrayEmployee[],int size)
{
    int i;
    float acum=0;
    float promedio;
    int contador=0;
    int contDePromedio=0;
    for(i=0; i<size; i++)
    {
        if(arrayEmployee[i].isEmpty==LLENO)
        {
            acum=acum+arrayEmployee[i].salary;
            contador++;
        }
    }
    promedio=(float) acum / contador;

    if(arrayEmployee[i].isEmpty<promedio)
    {
        contDePromedio++;
    }
    printf("\n\nEl salario total es:%.2f y el promedio es:%.2f\n\n",acum,promedio);
    printf("\n\nlos empleados que superaron el salario promedio son:%d\n\n",contDePromedio);
}

void printEmployees(eEmployee arrayEmployee[],int size)
{
    int i;
    for( i=0; i<size; i++)
    {
        if(arrayEmployee[i].isEmpty==LLENO)
        {
            printf("id:%d  nombre:%10s  apellido:%10s\n\n",arrayEmployee[i].id,arrayEmployee[i].name,arrayEmployee[i].lastName);
        }
    }
}
