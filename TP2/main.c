#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define TAM 1000
#include "biblioteca.h"

int main()
{
    eEmployee arrayEmployee[TAM];
    initEmployees(arrayEmployee,TAM);
    Menu(arrayEmployee);
    findEmployeeById(arrayEmployee,TAM);
    return 0;
}
