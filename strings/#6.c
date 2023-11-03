/*Colocar entre colchetes ([ ]) os caracteres de uma string que não sejam letras, números ou espaço; 
As alterações devem ser feitas na própria string, sem usar string auxiliar.*/

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

        /*verifica se caractere está fora dos critérios (ser letra, número ou espaço)*/
        if (string[i] < 32 || string[i] > 32 && string[i] < 48 || string[i] > 57 && string[i] < 65 || string[i] > 90 && string[i] < 97 || string[i] > 122) {
           
           /*pega a última letra da string e passa dois caracteres à frente*/
           for (int j = tam; j > i; j--)
                string[j+2] = string[j];   

            /*adiciona caracteres que nao se encaixem nos critérios entre colchetes*/         
            string[i+1] = string[i];
            string[i] = 91;
            string[i+2] = 93;

            tam += 2;
            i += 3;
        } else
            i++;
    }

    printf("A string modificada é: %s\n", string);

    return 0;
}