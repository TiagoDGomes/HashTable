#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int hash(char *chave){
	int k1, k2;
	chave = toupper(chave);
	return (chave[0] - 65) * 26
         + (chave[1] - 65) ;
}

int main(){

	char *estado[676];

	estado[hash("AC")] = "Acre";
	estado[hash("RJ")] = "Rio de Janeiro";
	estado[hash("GO")] = "Goias";
	estado[hash("SP")] = "São Paulo";

	printf("%s", estado[hash("RJ")]);

}

