#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hashtable.h"
#define TAMANHO 12


/* Func�o iniciar
   --------------
   Inicia a tabela, setando os n�s do array para NULL
*/
void iniciar(int tabela[]){
    int i;
    for (i = 0; i < TAMANHO; i++){
        tabela[i] = NULL;
    }
}


/* Fun��o Hash
   --------------
   Essa fun��o tem por finalidade gerar o �ndice para
   posicionar o elemento no array
*/

int hash(int chave){
    return chave % TAMANHO; // nesse caso gera um valor de 0 a TAMANHO-1 (resto da divis�o por TAMANHO)
}



void inserir(int tabela[], int valor){
    int posicao = hash(valor);
    if (tabela[posicao]==NULL){
        tabela[posicao] = valor;
    } else{
        printf("Estouro ao inserir %d. Colisao em posicao %d (existe %d).", valor,posicao, tabela[posicao]);
        exit(1);
    }
}

int buscar (int tabela[], int valor){
    int posicao = hash(valor);
    if (tabela[posicao]==valor){
        return posicao;
    } else{
        return NULL;
    }

}
int remover (int tabela[], int valor){
    int posicao = hash(valor);
    if (tabela[posicao]==valor){
        tabela[posicao]=NULL;
    } else {
        posicao = NULL;
    }
    return posicao;
}

void limpar (int tabela[]){
    iniciar(tabela);
}

void imprimir (int tabela[]){
    int i;
    for (i = 0; i < TAMANHO; i++){
        printf("[%2d]: ",i);
        if (tabela[i]!=NULL)
            printf("%2d", tabela[i]);
        printf("\n");
    }

}
