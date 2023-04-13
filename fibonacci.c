#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// 2
int fibonacci(int num)
{
    setlocale(LC_ALL, "Portuguese");
    // Retorna o número Fibonacci correspondente a um determinado índice
    if (num == 0)
    {
        return 0;
    }
    else if (num == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(num - 1) + fibonacci(num - 2);
    }
}

int main()
{
    int n, i;
    int pertence_fibonacci = 0;

    // Recebe um número do usuúrio
    printf("Digite um número: ");
    scanf("%d", &n);

    // Verifica se o número pertence a sequência de Fibonacci
    for (i = 0; fibonacci(i) <= n; i++)
    {
        if (fibonacci(i) == n)
        {
            pertence_fibonacci = 1;
            break;
        }
    }

    // Imprime a mensagem correspondente
    if (pertence_fibonacci)
    {
        printf("%d pertence a sequência de Fibonacci!\n", n);
    }
    else
    {
        printf("%d não pertence a sequência de Fibonacci.\n", n);
    }

    return 0;
}
