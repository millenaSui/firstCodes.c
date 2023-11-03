/*Escrever uma função int busca(agulha, palheiro), que busca a string agulha dentro da string palheiro, sem usar 
funções prontas da biblioteca C. A função deve retornar o índice onde agulha começa em palheiro, -1 se não for 
encontrada ou -2 em caso de erro (uma ou ambas as strings são nulas).*/

#include <stdio.h>
#include <string.h>

#define size 100

int busca(char *agulha, char *palheiro) {
    
    /*Retorna erro se strings são nulas*/
    if (agulha == NULL || palheiro == NULL)
        return -2;

    int tamAgulha = strlen(agulha);
    int tamPalheiro = strlen(palheiro);

    /*Retorna erro se palavra é maior que 
    texto em que deve ser buscada*/
    if (tamAgulha > tamPalheiro)
        return -2;

    for (int i = 0; i <= tamPalheiro - tamAgulha; i++) {
        int j;
        for (j = 0; j < tamAgulha; j++) {
            if (palheiro[i + j] != agulha[j])
                break;
        }

        /*Se encontrou a palavra, retorna seu índice*/
        if (j == tamAgulha)
            return i;
    }

    /*Palavra não encontrada*/
    return -1;
}

int main() {
    char agulha[size + 1];
    char palheiro[size + 1];

    printf("Insira a palavra que deseja buscar:\n");
    fgets(agulha, size, stdin);
    agulha[strcspn(agulha, "\n")] = "\0";

    printf("\nInsira o texto no qual deseja buscar a palavra:\n");
    fgets(palheiro, size, stdin);
    palheiro[strcspn(palheiro, "\n")] = "\0";

    /*Busca palavra e retorna seu índice (se encontrada), e mensagens
    alternativas caso não seja encontrada ou haja erro em sua busca*/
    int indice = busca(agulha, palheiro);
    if (indice >= 0)
        printf("O índice da palavra buscada é %d.\n", busca(agulha, palheiro));
    
    else if (indice == -1)
        printf("Palavra não encontrada.\n");
    
    else if (indice == -2)
        printf("Erro ao buscar palavra.\n");
    
    return 0;
}
