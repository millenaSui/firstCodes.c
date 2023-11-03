/*Escrever sua própria versão das funções de manipulação de strings strlen, 
strcpy e strcat. Depois, comparar o desempenho de sua implementação 
em relação às funções originais da LibC (sugestão: meça o tempo 
necessário para ativar cada função um milhão de vezes).*/

#include <stdio.h>
#include <string.h>
#include <time.h>

#define SIZEENTRY 10
#define SIZESTRING 100

int calculaTamanhoString(char *string) {
    int tam = 0;
    while (string[tam] != '\0')
        tam++;

    return tam;
}

void copiaString(char *string, char *copiar) {
    int i = 0;
    while (copiar[i] != '\0') {
        string[i] = copiar[i];
        i++;
    }
    string[i] = '\0';
}

void concatenaStrings(char *string, char *concatenar) {
    int tamString = calculaTamanhoString(string);
    int i = 0;
    while (concatenar[i] != '\0') {
        string[tamString + i] = concatenar[i];
        i++;
    }
    string[tamString + i] = '\0';
}

int main() {
    int entrada;
    char string[SIZESTRING];
    char stringAux[SIZESTRING];
    clock_t start, end;
    double cpu_time_used;

    printf("Insira o número do comando que deseja realizar:\n[1] strlen\n[2] strcpy\n[3] strcat\n[4] sair\n\n");
    while (scanf("%d", &entrada) == 1) {
        
        /*Executa o strlen*/
        if (entrada == 1) {
            printf("Insira a string que deseja calcular:\n");
            getchar();
            fgets(string, SIZESTRING, stdin);
            string[strcspn(string, "\n")] = '\0';

            start = clock();
            printf("O tamanho da string fornecida é %d\n", calculaTamanhoString(string));
            end = clock();
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Tempo para sua implementação de strlen: %f segundos\n\n", cpu_time_used);                

        /*Executa o strcpy*/
        } else if (entrada == 2) {
            printf("Insira a string que deseja copiar:\n");
            getchar(); 
            fgets(string, SIZESTRING, stdin);
            string[strcspn(string, "\n")] = '\0';
            printf("Insira a string para a qual deseja copiar:\n");
            fgets(stringAux, SIZESTRING, stdin);
            stringAux[strcspn(stringAux, "\n")] = '\0';
            
            start = clock();
            copiaString(stringAux, string);
            printf("A nova string é: %s\n", stringAux);
            end = clock();
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Tempo para sua implementação de strcpy: %f segundos\n\n", cpu_time_used);        

        /*Executa o strcat e mede o tempo de execução*/
        } else if (entrada == 3) {
            printf("Insira a string na qual deseja concatenar:\n");
            getchar(); 
            fgets(stringAux, SIZESTRING, stdin);
            stringAux[strcspn(stringAux, "\n")] = '\0';
            printf("Insira a string que deseja concatenar:\n");
            fgets(string, SIZESTRING, stdin);
            string[strcspn(string, "\n")] = '\0';
            
            start = clock();
            concatenaStrings(stringAux, string);
            printf("A nova string é: %s\n", stringAux);
            end = clock();
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Tempo para sua implementação de strcat: %f segundos\n\n", cpu_time_used);

        /*Interrompe o funcionamento do programa*/
        } else if (entrada == 4)
            break;
        
        else
            printf("Comando inexistente, tente novamente.\n");

        printf("Insira o número do comando que deseja realizar:\n[1] strlen\n[2] strcpy\n[3] strcat\n[4] sair\n\n");
    }

    return 0;
}
