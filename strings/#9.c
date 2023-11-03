/*Escrever uma função palindromo(s) que testa palíndromos: ela recebe uma string s de caracteres sem acentos e retorna 1 se a string é um palíndromo ou 0 senão.
Acentos, espaços em branco e maiúsculas/minúsculas devem ser ignorados. Exemplos de palíndromos:
    A cara rajada da jararaca
    O poeta ama ate o po
    Socorram-me, subi no onibus em Marrocos!
*/

#include <stdio.h>
#include <string.h>

#define size 100

int palindromo(char string[]) {
	int i = 0;
	int j = strlen(string) - 1;

	while (i <= j) {

		/*se caractere for diferente de letras padrão (maiúsculas e minúsculas), é desconsiderado, e se for letra 
		maiúscula, é transformado em letra minúscula para compará-lo com os demais*/
		while (string[i] > 90 && string[i] < 97 || string[i] > 122 || string[i] < 65)
			i++;

		if (string[i] > 64 && string[i] < 91)
			string[i] += 32;

		while (string[j] > 90 && string[j] < 97 || string[j] > 122 || string[j] < 65)
			j--;

		if (string[j] > 64 && string[j] < 91)
			string[j] += 32;


		/*se caracteres comparados forem iguais, compara os próximos,
		se forem diferentes, encerra o loop e retorna 0 (não palíndromo)*/
		if (string[i] == string[j])	{
			i++;
			j--;
		} else
			return 0;
	}

    return 1;
}

int main() {
    char string[size+1];

	fgets (string, size, stdin);
    string[strcspn (string, "\n")] = '\0';

	printf("%d\n", palindromo(string));

    return 0;
}