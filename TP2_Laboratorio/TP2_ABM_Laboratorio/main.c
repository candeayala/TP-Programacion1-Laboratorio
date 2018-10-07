#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "utn.h"
#define MAX 1000

int main()
{
   char seguir = 's';
    eEmployee lista[MAX];

    initEmployees(lista,MAX);

    char name[20];
    char lastName[20];
    float salary;
    int sector;
    int freeSlot;
    int flag=0;

    do
    {
        switch(menu())
        {
            case 1:
                freeSlot = toFindFreeSlot(lista,MAX);

                if(freeSlot != -1)
                {
                    flag++;
                    printf("Espacio libre = %d\n",freeSlot);
                    getValidString("Ingrese nombre:", "Error, reingrese nombre:", name);
                    getValidString("Ingrese apellido:", "Error, reingrese apellido:", lastName);
                    salary=getValidFloat("Ingrese salario:\n","Error, reintente:\n", 0, 999999);
                    sector=getValidInt("Ingrese sector:\n","Error, son solo hasta cinco sectores\n", 0, 5);
                    addEmployee(lista, MAX, freeSlot, name, lastName, salary, sector);
                }
                else
                {
                    printf("No hay espacio libre.\n");
                    system("pause");
                    system("cls");
                }

                break;

            case 2:
                if(flag==0)
                {
                    printf("Error. No hay suficientes datos.\n");

                }
                else
                {
                   modifyEmployee(lista, MAX, freeSlot);
                }

                system("pause");
                system("cls");
                break;

            case 3:
                if(flag == 0)
                {
                    printf("Error. No hay suficientes datos.\n");
                }
                else
                {
                   eraseEmployee(lista, MAX, lista[MAX].id);
                }
                system("pause");
                system("cls");
                break;

            case 4:
                if(flag == 0)
                {
                    printf("Error. No hay suficientes datos.\n");
                }
                else
                {
                    int order= getOrder();
                    sortEmployees(lista, MAX, order);
                    getAverageSalary(lista, MAX);
                }

                system("pause");
                system("cls");
                break;

            case 5:
               seguir='n';
                break;

            default:
                printf("Error\n");
                system("pause");
                system("cls");
                break;


        }
    }while(seguir == 's');

    return 0;
}
