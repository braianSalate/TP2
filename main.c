#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "arrayEmployees.h"

#define TAM 1000


char menu();


int main()
{
    int nextId = 1;
    eEmployee listEmployees[TAM];
    char seguir = 's';
    char confirma;
    int flagAltaEmpleado = 0;
    int baja;
    int modificar;
    int opcionOrdenar;
    int opcionInformes;
    float total;
    float promedio;
    int cobranMas;



    if(initEmployees(listEmployees, TAM))
    {
        printf("Inicializacion fallida");
    }
    else
    {
        printf("Se ha inicializado el alta\n");
    }

    do
    {
        switch(menu())
        {

        case 1:
            if(addEmployee(listEmployees, TAM, nextId) == 0)
            {
                nextId++;
                printf("Empleado agregado exitosamente\n");
                flagAltaEmpleado = 1;
            }
            else
            {
                printf("no se pudo agregar el empleado\n");
            }

            break;
        case 2:
                if(flagAltaEmpleado)
                {
                   baja = removeEmployee(listEmployees, TAM);
                   if(baja == -1)
                   {
                       printf("Problema al intentar la baja");
                   }
                   else
                   {
                       if(baja == 0)
                       {
                           printf("Se ha realizado la baja con exito!");
                       }
                       else
                       {
                           if(baja == 2)
                           {
                               printf("Has cancelado la baja!");
                           }
                       }
                   }
                }
                else
                {
                    printf("Aun no hay empleados cargados.");
                }


            break;
        case 3:
               if(flagAltaEmpleado)
                {
                    modificar = modificarEmpleado(listEmployees, TAM);
                    if(modificar)
                    {
                        printf("Hubo un problema al intentar modificar");
                    }
                    else
                    {
                        if(modificar == 0)
                        {
                            printf("modificacion exitosa");
                        }
                        else
                        {
                            if(modificar == 2)
                            {
                                printf("modificacion cancelada");
                            }
                        }
                    }
                }
                else
                {
                    printf("Aun no hay empleados");
                }
            break;
        case 4:
                if(flagAltaEmpleado)
                {
                    printf("\033[2J");
                    printEmployees(listEmployees, TAM);
                }
                else
                {
                    printf("No hay empleados que mostrar!!");
                }

            break;
        case 5:
                if(flagAltaEmpleado)
                {
                    printf("\033[2J");
                    printf("Desea ordenar por:\n 1-Apellido \n 2-Sector");
                    scanf("%d", &opcionOrdenar);
                    if(opcionOrdenar)
                    {
                        sortEmployeeByName(listEmployees, TAM);
                        printEmployees(listEmployees, TAM);
                    }
                    else
                    {
                        if(opcionOrdenar == 2)
                        {
                            sortEmployeeBySector(listEmployees, TAM);
                            printEmployees(listEmployees, TAM);
                        }
                    }
                }
                else
                {
                    printf("Aun no hay empleados cargados.");
                }

            break;
        case 6:
            if(flagAltaEmpleado)
            {
                printf("\033[2J");
                printf("***Informes***\n");
                printf("1 Total de sueldos\n");
                printf("2 Promedio de sueldos\n");
                printf("3 Empleados que cobran mas que el promedio\n");
                printf("Que informe desea?: \n");
                scanf("%d", &opcionInformes);

                switch(opcionInformes)
                {
                case 1:
                    total = totalSueldos(listEmployees, TAM);
                    printf("El total de sueldos es: %.2f", total);
                break;
                case 2:
                    promedio = promedioSueldos(listEmployees, TAM);
                    printf("El promedio de sueldos es: %.2f", promedio);
                break;
                case 3:
                    cobranMas = cobranMasQuePromedio(listEmployees, TAM);
                    printf("%d empleados cobran mas que el promedio.", cobranMas);
                break;
                default:
                    printf("opcion invalida!!");
                }


            }
            else
            {

            }

            break;


        case 7:
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }

            break;
        }

        getchar();
        getchar();

    }
    while( seguir == 's');


    return 0;
}


char menu()
{
    int opcion;
    printf("\033[2J");

    printf("*** ABM Personas ***\n\n");
    printf("1 Alta\n");
    printf("2 Baja\n");
    printf("3 Modificion\n");
    printf("4 Listar\n");
    printf("5 Ordenar\n");
    printf("6 Informes\n");
    printf("7 Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    while(validarOpcion(opcion) == 0 )
        {
            printf("Opcion elegida invalida, ingrese operacion a realizar: ");

            scanf("%d", &opcion);
        }

    return opcion;
}

