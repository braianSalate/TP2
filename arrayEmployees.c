#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "arrayEmployees.h"

int initEmployees(eEmployee employees[],int tam )
{
    int error = -1;

    if(employees != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            employees[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

void printEmployee(eEmployee employee)
{
    printf("    %4d   %5s  %s    %.2f    %d\n", employee.id, employee.name, employee.lastName, employee.salary, employee.sector);
}

int printEmployees(eEmployee employees[], int tam)
{
     int error = -1;
     int flag = 0;

    if(employees != NULL && tam > 0)
    {
        //printf("\033[2J");
        printf("         ***Listado de empleados***\n");
        printf("   Legajo  Nombre  Apellido  Sueldo  Sector\n");
        printf("----------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(employees[i].isEmpty == 0)
            {
                printEmployee(employees[i]);
                flag = 1;
            }
        }

        if(!flag)
        {
            printf("No hay empleados en la lista\n");
        }
        else
        {
            printf("\n\n");
        }
        error = 0;
    }
    return error;
}

int addEmployee(eEmployee employees[], int tam, int id)
{
    int error = -1;
    eEmployee newEmployee;
    int freePlace;
    int validacion;

    if(employees != NULL && tam > 0 && id > 0)
    {
        printf("\033[2J");
        printf("  *** Alta de empleado ***\n\n");
        freePlace = searchFreePlace(employees, tam);
        if(freePlace == -1)
        {
            printf("Sistema completo, libere espacio para cargar un nuevo empleado.\n");
        }
        else
        {
            newEmployee.id = id;
            newEmployee.isEmpty = 0;
            printf("Ingrese nombre: ");
            fflush(stdin);
            scanf("%s", newEmployee.name);
            validacion = validarCadena(newEmployee.name);
            if(!validacion)
            {
                printf("Por favor ingrese un nombre valido: ");
                fflush(stdin);
                scanf("%s", newEmployee.name);
            }
            printf("Ingrese apellido: ");
            fflush(stdin);
            scanf("%s", newEmployee.lastName);
             validacion = validarCadena(newEmployee.lastName);
            if(!validacion)
            {
                printf("Por favor ingrese un apellido valido: ");
                fflush(stdin);
                scanf("%s", newEmployee.lastName);
            }
            printf("Ingrese salario: ");
            scanf("%f", &newEmployee.salary);
            if(validarSalario(newEmployee.salary)==0)
            {
                printf("Ingrese salario mayor a cero: ");
                scanf("%f", &newEmployee.salary);
            }
            printf("ingrese sector(tenga en cuenta que los sectores de la empresa van del 1 al 5): ");
            scanf("%d", &newEmployee.sector);
             if(validarSector(newEmployee.sector)==0)
            {
                printf("Ingrese sector valido(del 1 al 5): ");
                scanf("%f", &newEmployee.salary);
            }

            employees[freePlace] = newEmployee;
        }

        error = 0;
    }
    return error;
}

int searchFreePlace(eEmployee employees[],int tam)
{
    int freePlace = -1;
    for(int i=0; i<tam;i++)
    {
        if(employees[i].isEmpty == 1)
        {
            freePlace = i;
            break;
        }
    }
    return freePlace;
}

int searchEmployee(eEmployee employees[], int tam, int id)
{
    int employeeIndex = -1;
    for(int i=0; i<tam;i++)
    {
        if(employees[i].id == id && employees[i].isEmpty == 0)
        {
            employeeIndex = i;
            break;
        }
    }
    return employeeIndex;
}

int removeEmployee(eEmployee employees[], int tam) //0 baja exitosa 1 hubo un problema 2 se cancela la baja
{
    int error = -1;
    int employeeIndex;
    int id;
    int confirm;

   if(employees != NULL && tam > 0)
    {
        printf("\033[2J");
        printf("***Baja de empleados\n");
        printEmployees(employees, tam);
        printf("Ingrese legajo del empleado que desea eliminar: \n");
        scanf("%d", &id);
        employeeIndex = searchEmployee(employees, tam, id);
        if(employeeIndex == -1)
        {
            printf("No hay ningun empleado con ese legajo\n");
        }
        else
        {
            printf("\033[2J");
            printEmployee(employees[employeeIndex]);
            printf("Confirma la baja del empleado?\n -1 para confirmar\n -2 para cancelar la baja\n ");
           scanf("%d", &confirm);


            if(confirm == 1)
            {
                employees[employeeIndex].isEmpty = 1;
                error = 0;
            }
            else
            {
               if(confirm == 2 )
               {
                    error = 2;
               }
               else
               {
                   printf("Opcion invalida por favor ingrese:\n -1 para confirmar\n -2 para cancelar la baja\n ");
                   scanf("%d", &confirm);
               }
            }
        }

    }
    return error;
}

int validarOpcion(int a)
{
    int rdo;
    if(a != 1 && a!= 2 && a !=3 && a != 4 && a != 5 && a != 6 && a!=7 )
    {
        rdo = 0;
    }else{rdo=1;}
    return rdo;
}

int modificarEmpleado(eEmployee employees[], int tam)
{
    int error = 1;
    int employeeIndex;
    int id;
    int confirm;
    int opcion;
    eEmployee newEmployee;
    float nuevoSueldo;
    int nuevoSector;


   if(employees != NULL && tam > 0)
    {
        printf("\033[2J");
        printf("***Modificar un empleado\n");
        printEmployees(employees, tam);
        printf("Ingrese legajo del empleado que desea modificar: \n");
        scanf("%d", &id);
        employeeIndex = searchEmployee(employees, tam, id);
        if(employeeIndex == -1)
        {
            printf("No hay ningun empleado con ese legajo\n");
        }
        else
        {
            printf("\033[2J");
            printEmployee(employees[employeeIndex]);
            printf("***Opciones a modificar***\n");
            printf("1 Nombre\n");
            printf("2 Apellido\n");
            printf("3 sueldo\n");
            printf("sector\n");
            printf("Elija que campo desea modificar: ");
            scanf("%d", &opcion);
            switch(opcion)
            {
                case 1:
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    scanf("%s", newEmployee.name);
                    printf("Confirma nuevo nombre?\n -1 para confirmar\n -2 para cancelar \n ");
                    scanf("%d", &confirm);


                    if(confirm == 1)
                    {
                        strcpy(employees[employeeIndex].name, newEmployee.name);
                        error = 0;
                    }
                    else
                    {
                       if(confirm == 2 )
                       {
                            error = 2;
                       }
                       else
                       {
                           printf("Opcion invalida por favor ingrese:\n -1 para confirmar\n -2 para cancelar la baja\n ");
                           scanf("%d", &confirm);
                       }
                    }
                break;
                case 2:
                    printf("Ingrese nuevo apellido: ");
                    fflush(stdin);
                    scanf("%s", newEmployee.lastName);
                    printf("Confirma nuevo apellido?\n -1 para confirmar\n -2 para cancelar \n ");
                    scanf("%d", &confirm);


                    if(confirm == 1)
                    {
                        strcpy(employees[employeeIndex].lastName, newEmployee.lastName);
                        error = 0;
                    }
                    else
                    {
                       if(confirm == 2 )
                       {
                            error = 2;
                       }
                       else
                       {
                           printf("Opcion invalida por favor ingrese:\n -1 para confirmar\n -2 para cancelar la baja\n ");
                           scanf("%d", &confirm);
                       }
                    }


                break;
                case 3:
                    printf("Ingrese nuevo sueldo: ");
                    scanf("%f", &nuevoSueldo);
                    printf("Confirma nuevo sueldo?\n -1 para confirmar\n -2 para cancelar \n ");
                    scanf("%d", &confirm);


                    if(confirm == 1)
                    {
                        employees[employeeIndex].salary = nuevoSueldo;
                        error = 0;
                    }
                    else
                    {
                       if(confirm == 2 )
                       {
                            error = 2;
                       }
                       else
                       {
                           printf("Opcion invalida por favor ingrese:\n -1 para confirmar\n -2 para cancelar la baja\n ");
                           scanf("%d", &confirm);
                       }
                    }

                break;
                case 4:
                    printf("Ingrese nuevo sector: ");
                    scanf("%d", &nuevoSector);
                    printf("Confirma nuevo apellido?\n -1 para confirmar\n -2 para cancelar \n ");
                    scanf("%d", &confirm);


                    if(confirm == 1)
                    {
                        employees[employeeIndex].sector = nuevoSector;
                        error = 0;
                    }
                    else
                    {
                       if(confirm == 2 )
                       {
                            error = 2;
                       }
                       else
                       {
                           printf("Opcion invalida por favor ingrese:\n -1 para confirmar\n -2 para cancelar la baja\n ");
                           scanf("%d", &confirm);
                       }
                    }

                break;
                default:
                printf("Opcion invalida!");
            }
        }

    }
    return error;
}

int validarSector(int a)
{
    int rdo;
    if(a != 1 && a!= 2 && a !=3 && a != 4 && a != 5 )
    {
        rdo = 0;
    }else{rdo=1;}
    return rdo;
}
int validarSalario(int a)
{
    int rdo;
    if(a <= 0 )
    {
        rdo = 0;
    }else{rdo=1;}
    return rdo;
}

int sortEmployeeByName(eEmployee employees[], int tam)
{
    int error = 1;
    eEmployee auxEmployee;
    if(employees != NULL && tam >0)
    {
        for(int i = 0; i < tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(strcmp(employees[i].lastName, employees[j].lastName)>0)
                {
                    auxEmployee = employees[i];
                    employees[i] = employees[j];
                    employees[j]=auxEmployee;
                }
            }
        }
        error = 0;
    }
    return error;
}

int sortEmployeeBySector(eEmployee employees[], int tam)
{
    int error = 1;
    eEmployee auxEmployee;
    if(employees != NULL && tam >0)
    {
        for(int i = 0; i < tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(employees[i].sector > employees[j].sector)
                {
                    auxEmployee = employees[i];
                    employees[i] = employees[j];
                    employees[j]=auxEmployee;
                }
            }
        }
        error = 0;
    }
    return error;
}

float totalSueldos(eEmployee employees[], int tam)
{
    float acumulador = 0;
    for(int i=0; i<tam; i++)
    {
        if(employees[i].isEmpty == 0)
        {
            acumulador = acumulador + employees[i].salary;
        }
    }
    return acumulador;
}

float promedioSueldos(eEmployee employees[], int tam)
{
    int divisor = 0;
    float acumulador = 0;
    float promedio = 0;
    for(int i=0; i<tam; i++)
    {
        if(employees[i].isEmpty == 0)
        {
            acumulador = acumulador + employees[i].salary;
            divisor = i;

        }
    }
    promedio = (float)acumulador/divisor;

    return promedio;
}

int cobranMasQuePromedio(eEmployee employees[], int tam)
{
    int acumulador = 0;
    float promedio = 0;
    promedio = promedioSueldos(employees, tam);
    for(int i=0; i<tam;i++)
    {
        if(employees[i].isEmpty == 0)
        {
            if(employees[i].salary > promedio)
            {
                acumulador++;
            }
        }
    }
    return acumulador;
}

int validarCadena(char cadena[])
{
    int i=0;
    while(cadena[i])
    {
        if(!isalpha(cadena[i]) && cadena[i]!=' ')
        {
            return 0;
            i++;
        }
    }
    return 1;
}
