/*Ler linhas da entrada padrão e escrevê-las na saída padrão em ordem 
alfabética crescente, de forma similar ao comando sort do shell UNIX.*/

#include <stdio.h>
#include <string.h>

#define TAMPALAVRAS 100
#define NUMPALAVRAS 100

int main() {
    
    /*Cria uma matriz para armazenar as palavras da entrada*/
    char matriz[NUMPALAVRAS][TAMPALAVRAS];
    int numPalavras = 0;
    int linhaEmBrancoEncontrada = 0;

    /*Preenche a matriz de palavras até encontrar uma linha em branco*/
    while (numPalavras < NUMPALAVRAS) {
        if (fgets(matriz[numPalavras], TAMPALAVRAS, stdin) == NULL)
            break;

        /*Se linha em branco é encontrada, interrompe a leitura*/
        if (matriz[numPalavras][0] == "\n") {
            linhaEmBrancoEncontrada = 1;
            break;
        }

        /*Remove o caractere de nova linha do final da string*/
        matriz[numPalavras][strcspn(matriz[numPalavras], "\n")] = "\0";
        numPalavras++;
    }

    /*Realiza a ordenação das palavras na matriz*/
    for (int contPalavras = 0; contPalavras < numPalavras; contPalavras++) {
        int linhaMenorPalavra = contPalavras;

        for (int j = contPalavras + 1; j < numPalavras; j++) {
            if (strcmp(matriz[j], matriz[linhaMenorPalavra]) < 0)
                linhaMenorPalavra = j;
        }

        /*Realiza a troca das palavras*/
        if (linhaMenorPalavra != contPalavras) {
            char aux[TAMPALAVRAS];
            strcpy(aux, matriz[contPalavras]);
            strcpy(matriz[contPalavras], matriz[linhaMenorPalavra]);
            strcpy(matriz[linhaMenorPalavra], aux);
        }
    }

    /*Imprime as palavras ordenadas*/
    for (int i = 0; i < numPalavras; i++)
        printf("%s\n", matriz[i]);

    return 0;
}
