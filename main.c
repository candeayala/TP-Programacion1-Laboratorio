/*******************************************************************
*Programa: Calculadora en lenguaje C
*
*Objetivo:
      Ingresar dos numeros y realizar 5 operaciones matematicas:
      suma, resta, multiplicacion, division y factorial.
*
*Version: 01. del 07 Septiembre de 2018.
*Autor: Candela Ayala
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "archivo.h"

int main()
{
    int option,resultadoFactorial,resultadoFactorialDos;
    float num1=0, num2=0, resultado;

    do{
        system("cls");
        printf("Menu");
        printf("\n\n1.- Ingresar primer numero(A= %.2f)", num1);
        printf("\n\n2.- Ingresar segundo numero(B= %.2f)", num2);
        printf("\n\n3.- Sumar(A+B).");
        printf("\n\n4.- Restar(A-B).");
        printf("\n\n5.- Multiplicar(A*B).");
        printf("\n\n6.- Dividir(A/B).");
        printf("\n\n7.- Factorial(A!) y (B!).");
        printf("\n\n8.- Salir.");
        printf("\n\nSeleccione opcion: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("Ingrese el primer numero\n");
                scanf("%f", &num1);
                break;

            case 2:
                printf("Ingrese el segundo numero\n");
                scanf("%f", &num2);
                break;

            case 3:
                resultado= addition(num1, num2);
                printf("\nEl resultado de la suma es %.2f\n\n", resultado);
                break;

            case 4:
                resultado= substraction(num1, num2);
                printf("\nEl resultado de la resta es %.2f\n\n", resultado);
                break;

            case 5:
                resultado= multiplication(num1, num2);
                printf("\nEl resultado de la multiplicacion es %.2f\n\n", resultado);
                break;

            case 6:
                resultado= division(num1, num2);
                printf("\nEl resultado de la division es %.2f\n\n", resultado);
                break;

            case 7:
                resultadoFactorial= factorial(num1);
                printf("\nEl factorial de A es: %.2i\n\n", resultadoFactorial);
                resultadoFactorialDos= factorialDos(num2);
                printf("\nEl factorial de B es: %.2i\n\n", resultadoFactorialDos);
                break;

            case 8:
                printf("\n Adios!\n\n");
                break;

            default:
                printf("\nLas opciones disponibles son del 1 al 8.\n\n");
                break;
        }
        system("pause");
    }while(option != 8);

    return 0;
}


