/*remover de uma string os caracteres que não sejam letras, números ou espaço, sem usar string auxiliar*/

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
        if (string[i] < 32 || string[i] > 32 && string[i] < 48 || string[i] > 57 && string[i] < 65 || string[i] > 90 && string[i] < 97 || string[i] > 122) {
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