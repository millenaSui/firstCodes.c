/*Calcular o tamanho de uma string (sem usar strlen).*/

#include <stdio.h>
#include <string.h>

#define size 100

int main() {
    char string[size+1];

    fgets (string, size, stdin);
    string[strcspn (string, "\n")] = '\0';

    int i = 0;
    while (string[i] != '\0') i++;

    printf("O tamanho da string é %d\n", i);

    return 0;
}