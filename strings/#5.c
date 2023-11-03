/*Remover de uma string caracteres repetidos em sequência (rr, ss, ee, etc), sem usar string auxiliar.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define size 100

int main() {
    char string[size+1];

    fgets (string, size, stdin);
    string[strcspn (string, "\n")] = '\0';
    int tam = strlen(string);

    int i = 0;
    while (string[i] != '\0') {
        if (string[i+1] == string[i]) {
            int j = i;
            for (int j = i; j < tam; j++)
                string[j] = string[j+1];

            tam--;
        } else
            i++;
    }

    printf("A string modificada é: %s\n", string);

    return 0;
}