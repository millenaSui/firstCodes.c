/*converter as letras de uma string em minúsculas 
(dica: estude a estrutura da tabela ASCII antes de implementar)*/

#include <stdio.h>
#include <string.h>

#define size 100

int main() {
    char string[size+1];

    fgets (string, size, stdin);
    string[strcspn (string, "\n")] = '\0';

    int i = 0;
    while (string[i] != '\0') {
        if (string[i] >= 65 && string[i] <= 90)
            string[i] += 32;
        i++;
    }

    printf("\nA string modificada é:\n%s\n\n", string);


    return 0;
}