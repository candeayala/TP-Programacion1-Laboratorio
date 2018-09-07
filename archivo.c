//Suma
/** \brief Suma 2 valores reales ingresados por el usuario.
 *
 * \param Primer valor.
 * \param Segundo valor.
 * \return El resultado de la suma.
 *
 */
float addition(float num1, float num2)
{
    float resultado;
    resultado = num1 + num2;
    return resultado;
}


//Resta
/** \brief Resta 2 valores reales ingresados por el usuario.
 *
 * \param Primer valor.
 * \param Segundo valor.
 * \return El resultado de la resta.
 *
 */
float substraction(float num1, float num2)
{
    float resultado;
    resultado = num1 - num2;
    return resultado;
}


//Multiplicacion
/** \brief Multiplica 2 valores ingresados por el usuario.
 *
 * \param Primer valor.
 * \param Segundo valor.
 * \return El resultado de la multiplicacion.
 *
 */
float multiplication(float num1, float num2)
{
    float resultado;
    resultado = num1 * num2;
    return resultado;
}


//Division
/** \brief Divide 2 valores reales ingresados por el usuario.
 *
 * \param Primer valor(Dividendo).
 * \param Segundo valor(Divisor).
 * \return El resultado de la division.
 *
 */
float division(float num1, float num2)
{

    float resultado;
    while (num2 == 0)
    {
        printf("Error. No se puede dividir por 0. Ingrese un divisor mayor a 0: ");
        scanf("%f", &num2);
    }
    resultado = (float) num1 / num2;

    return resultado;
}


//Factorial
/** \brief Calcula los factoriales del primer y segundo valor en los parametros.
 *
 * \param Primer valor entero positivo.
 * \param Si los numeros escogidos son iguales a cero, el factorial retornara un uno.
 * \param En caso de que los numeros escogidos sean negativos, tendra que reingresarlos cambiandolos por positivos.
 * \return El producto de los numeros enteros positivos consecutivos desde el 1 hasta el valor asignado en el parametro.
 *
 */
int factorial(int num1)
{
    if (num1==0)
    {
        return 1;
    }
    else if (num1<0)
    {
        printf("Error. Seleccione un numero positivo: ");
        scanf("%i",&num1);
    }
    else
    {
        int resultadoFactorial=1;
        for(int i=1; i<=num1; i++)
        {
            resultadoFactorial=resultadoFactorial*i;

        }
        return resultadoFactorial;
    }
    }


int factorialDos(int num2)
{
    if (num2==0)
    {
        return 1;
    }
    else if (num2<0)
    {
        printf("Error. Seleccione un numero positivo: ");
        scanf("%i",&num2);
    }
    else
    {
        int resultadoFactorialDos=1;
        for(int i=1; i<=num2; i++)
            {
                resultadoFactorialDos=resultadoFactorialDos*i;
            }
        return resultadoFactorialDos;
    }

}
