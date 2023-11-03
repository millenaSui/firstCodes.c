/*Ler uma string da entrada padrão e escrevê-la na saída padrão ao contrário 
(do final para o início), de forma similar ao comando rev do shell UNIX.*/

#include <stdio.h>
#include <string.h>

#define size 100

int main() {
    char string[size+1];

    fgets (string, size, stdin);
    string[strcspn (string, "\n")] = '\0';
    int i = strlen(string);

    while (i >= 0) {
        putchar (string[i]);
        i--;
    }
    printf("\n");

    return 0;
}