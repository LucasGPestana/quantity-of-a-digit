#include <stdio.h>
#include <stdlib.h>

int _countDigits(int number) {

    /* Conta a quantidade de d�gitos do n�mero passado como argumento, de modo a incrementar 1 ao valor retornado dessa mesma
    fun��o chamada recursivamente, at� que o n�mero do argumento tenha apenas um d�gito */

    if (number < 10) return 1;
    return 1 + _countDigits(number / 10);
}

int* _getDigits(int number) {

    /* Armazena todos os d�gitos do n�mero passado como argumento em um espa�o alocado dinamicamente e retorna o seu ponteiro */

    int* digits = (int*)malloc(_countDigits(number) * sizeof(int));
    int aux; // Vari�vel auxiliar para armazenar o valor resultante da opera��o aritm�tica da linha 21
    int last_aux; // Vari�vel auxiliar para armazenar o valor de aux, de modo que ela n�o seja perdida ap�s a linha 21

    aux = number;
    for (int k = 0; k < _countDigits(number); k++) {

        last_aux = aux;

        aux = (int) (aux / 10);

        digits[k] = last_aux - (aux * 10);

    }

    return digits;

}

int getDigitQuantity(int digit, int* numbers, int length) {

    /* Pega os digitos de cada n�mero da estrutura de dados apontada por numbers e incrementa 1 ao contador (count) quando o
    digito comparado for correspondente ao digito passado como argumento (digit) */

    if (digit < 0 || digit >= 10) {
        printf("\nThe digit must be higher or equal than zero and lower than 10!\n\n");
        return 0;
    }

    int count = 0;

    for (int i = 0; i < length; i++) {

        int* digits = _getDigits(numbers[i]);

        for (int j = 0; j < _countDigits(numbers[i]); j++) {
            if (digits[j] == digit) count++;
        }

    }

    return count;

}

int main()
{
    int numbers[100];
    int length = sizeof(numbers) / sizeof(int); /* Quantidade de elementos da estrutura de dados apontada por numbers */
    int digit = 4;

    for (int i = 0; i < length; i++) numbers[i] = 400 + i;

    printf("\nQuantity of %d between %d and %d: %d\n", digit, numbers[0], numbers[length-1], getDigitQuantity(digit, numbers, length));
    return 0;
}
