#include <stdio.h>
#include <string.h>
#include <locale.h>
//5


int main()
{
	setlocale(LC_ALL, "Portuguese");
    char str[100];
    int len, i, j, start, end;
    
    printf("Digite uma frase: ");
    fgets(str, 100, stdin);
    
    len = strlen(str);
    start = 0;
    
    for (i = 0; i < len; i++) {
        if (str[i] == ' ') {
            end = i - 1;
            while (start < end) {
                char temp = str[start];
                str[start] = str[end];
                str[end] = temp;
                start++;
                end--;
            }
            start = i + 1;
        }
    }
    
    end = len - 2;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    
    printf("Frase com palavras invertidas: %s\n", str);
    
    return 0;
}

