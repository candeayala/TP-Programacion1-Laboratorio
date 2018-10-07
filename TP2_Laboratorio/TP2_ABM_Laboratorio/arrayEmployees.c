#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "utn.h"

static int newId()
{
   static int id = 0;

    id ++;

    return id;

}
int initEmployees(eEmployee* lista, int len)
{
    int retorno=-1;

    if(lista != NULL && len>0)
    {
       for(int i=0; i < len; i++)
        {
            lista[i].isEmpty = 1;
        }

        retorno=0;
    }
    return retorno;
}

int toFindFreeSlot(eEmployee* lista, int len)
{
    int retorno = -1;

    if(lista != NULL)
    {
       for(int i=0; i< len; i++)
        {
            if( lista[i].isEmpty == 1)
            {
                retorno = i;
                break;
            }
        }

    }

    return retorno;
}

int menu()
{
    int option;
    system("cls");
    printf("***Menu de Opciones***\n\n");
    printf("1- Alta\n");
    printf("2- Modificar\n");
    printf("3- Baja\n");
    printf("4- Informes\n");
    printf("5- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &option);

    return option;
}

int addEmployee(eEmployee* lista, int len, int id, char* name, char* lastName, float salary, int sector)
{
    int retorno =-1;
    int i = toFindFreeSlot(lista, len);
    int index = findEmployeeById(lista, len, id);

    if (i!=-1)
    {
        if (lista[index].isEmpty==0)
        {
            id=newId();
        }
        lista[i].id=id;
        strcpy(lista[i].name, name);
        strcpy(lista[i].lastName, lastName);
        lista[i].salary= salary;
        lista[i].sector= sector;
        lista[i].isEmpty= 0;
        retorno= 0;
    }

    return retorno;

}

int findEmployeeById(eEmployee* lista, int len, int id)
{
    int retorno = -1;
    if(lista != NULL)
    {
        for(int i=0; i < len; i++)
        {
            if( lista[i].id == id && lista[i].isEmpty == 0)
            {
                retorno = i;
                break;
            }
        }
        return retorno;

    }

    return retorno;
}

int eraseEmployee(eEmployee* lista, int len, int id)
{
    int i;
    int index;
    int retorno= -1;
    char respuesta;

    printf("\nIngrese el id que quiere borrar: ");
    scanf("%d",&id);

    index = findEmployeeById(lista, len, id);

    for(i=0; i<len ;i++)
    {
      if(lista[index].isEmpty >= 0)
        {
            printf("\nID\t NOMBRE\t APELLIDO\t SALARIO\t SECTOR\n\n");
            printEmployee(lista, len);
            printf("\n¿Desea borrar al empleado? S/N: ");
            fflush(stdin);
            scanf("%c",&respuesta);

            if (respuesta == 's')
            {
                    lista[index].isEmpty=1;
                    printf("\nEmpleado borrado.\n\n");
            }

            else
            {
                printf("\nOpcion cancelada.\n\n");
                break;
            }
         }

        else
            {
                printf("\nError. No existe el ID ingresado.\n");
                break;
            }

          retorno=0;
    }
    return retorno;
}

int modifyEmployee(eEmployee* lista, int len,int id)
{
    int i;
    int retorno=-1;
    int modify;
    float newSalary;
    char newName[20];
    char newLastName[20];
    int newSector;
    char respuesta;

    printf("Ingrese el Id. que desea modificar:\n");
    scanf("%d", &id);
    i=findEmployeeById(lista, len, id);

        if(i== -1)
        {
            printf("\nNo existe el ID.\n");
        }
        else
        {
           do
            {
                printf("ID\t    NOMBRE\t    APELLIDO\t    SALARIO\t    SECTOR\n");
                printEmployee(lista, len);
                printf("\n\nSeleccione lo que quiere modificar:");
                printf("\n1. Nombre\n");
                printf("2. Apellido\n");
                printf("3. Salario\n");
                printf("4. Sector\n");
                scanf("%d", &modify);

                switch(modify)
                {
                    case 1:
                        getValidString("Ingrese nombre:", "Error, ingrese nuevamente:", newName);
                        strcpy(lista[i].name, newName);
                        break;

                    case 2:
                        getValidString("Ingrese apellido:", "Error, ingrese nuevamente:", newLastName);
                        strcpy(lista[i].lastName, newLastName);
                        break;

                    case 3:
                        newSalary = getValidFloat("Ingrese salario:\n","Error\n", 0, 1000000);
                        lista[i].salary = newSalary;
                        break;

                    case 4:
                        newSector = getValidInt("Ingrese sector:\n","Error, son solo 5 sectores\n", 0, 5);
                        lista[i].sector = newSector;
                        break;

                    default :
                        printf("El dato es incorrecto\n");
                    }

                printf("¿Desea continuar? s/n \n :");
                fflush(stdin);
                scanf("%c",&respuesta);
                system("pause");
                system("cls");

            }while(respuesta=='s');

            retorno=0;
        }

    return retorno;
}

int printEmployee(eEmployee* lista, int index)
{
    int retorno=-1;

    if(lista != NULL && lista[index].isEmpty == 0)
    {
        printf("%d %s %s %.2f %d\n", lista[index].id, lista[index].name, lista[index].lastName, lista[index].salary, lista[index].sector);
        retorno=0;
    }

    return retorno;

}

int printEmployees(eEmployee* lista, int len)
{
    int retorno=-1;
    if (lista!=NULL)
    {
        printf("\nID\tNombre\t\tApellido\tSalario\t\t\tSector\n\n");
        for (int i=0; i<len; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                printEmployee(lista, i);
                retorno=0;
            }
        }
    }
    return retorno;
}

int getAverageSalary(eEmployee* lista, int len)
{
    float averageSalary =0;
    float total =0;
    int contadorEmployee =0;
    int contadorSalary =0;

    for(int i=0; i<len; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            total= total+lista[i].salary;
            contadorEmployee++;

        }
    }
    averageSalary= total/contadorEmployee;

    for (int i=0; i<len; i++)
    {
        if ((lista[i].isEmpty == 0) && (lista[i].salary > averageSalary))
        {
          contadorSalary++;
        }

    }

    system("cls");
    printf("El total de los salarios es: %.2f\n", total);
    printf("El promedio de los salarios es: %.2f\n", averageSalary);
    printf("La cantidad de empleados que superan el salario promedio son: %d\n", contadorSalary);
    return 0;
}

int getOrder()
{
    int order;
    printf("Ingrese el orden de la lista de empleados\n0 = Descendente\n1= Ascendente\n");
    scanf("%d", &order);
    return order;
}

int sortEmployees(eEmployee* lista, int len, int order)
{
    eEmployee aux;
    printEmployees(lista,len);
    int retorno=-1;

    if (order == 1)
    {
        for (int i=0; i<len-1; i++)
        {
            for (int j= i+1; j<len; j++)
            {
                if (strcmp(lista[i].lastName,lista[j].lastName) > 0)
                {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
                else if (strcmp(lista[i].lastName, lista[j].lastName) == 0 && lista[i].sector > lista[j].sector)
                {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }

            }
        }
        retorno=0;
    }
    else if (order == 0)
    {
        for (int i=0; i<len-1; i++)
        {
            for (int j =i+1; j<len; j++)
            {
                if (strcmp(lista[i].lastName, lista[j].lastName) < 0)
                {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }

                else if (strcmp(lista[i].lastName, lista[j].lastName) == 0 && lista[i].sector < lista[j].sector)
                {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
            }

        }
        retorno=0;
    }
    else
    {
       printf("Error, ingrese la opcion 0 (Descendente) o 1 (Ascendente)\n");
    }
    return retorno;
}

