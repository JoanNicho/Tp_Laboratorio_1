#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} eEmployee;

/**\brief muestra las opciones del menu
 *\param ingresa a la opcion que desea que el usuario ejecute
 * \return retorna void
 */
void Menu(eEmployee[]);


/**\brief recorre el array
 *\param incrementa cada vez que se ingresa un empleado
 * \return retorna i
 */
int findEmployeeById(eEmployee[],int);


/**\brief recorre el array
 *\param inicializa el array en VACIO
 * \return retorna void
 */
void initEmployees(eEmployee[],int);


/**\brief recorre el array
 *\param Busca VACIO luego lo cambia a LLENO
 * \return retorna aux
 */
int ArraySpace(eEmployee[],int);


/**\brief Ingresa los datos
 *\param validacion de datos
 * \return retorna void
 */
void addEmployees(eEmployee[],int,int);


/**\brief se ingresa id para modificar los datos
 *\param si el id es correcto se modifican los datos, caso contrario sale del programa
 * \return retorna void
 */
void modifyEmployee(eEmployee[],int);


/**\brief se ingresa id para dar de baja a un empleado
 *\param si el id es correcto se da de baja, caso contrario sale del programa
 * \return retorna void
 */
void removeEmployee(eEmployee[],int);


/**\brief recorre el array
 *\param  hace un intercambio de posicion hasta que el apellido quede ordenado
 * \return retorna void
 */
void sortEmployeeByLastName(eEmployee[],int);


/**\brief  recorre el array
 *\param  hace un intercambio de posicion hasta que el sector quede ordenado
 * \return retorna void
 */
void sortEmployeeBySector(eEmployee[],int);


/**\brief  recorre el array
 *\param saca el promedio del salario y que empleado lo supera
 * \return retorna void
 */
void totalAndAverageSalary(eEmployee[],int);


/**\brief  recorre el array
 *\param muestra el id,el nombre y el apellido
 * \param los datos son mostrados dentro de modificar y dar de baja
  * \param para que el usuario sepa que id desea modificar o dar de baja
 * \return retorna void
 */
void printEmployees(eEmployee[],int);

#endif // BIBLIOTECA_H_INCLUDED
