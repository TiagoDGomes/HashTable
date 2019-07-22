#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

No* novoNo(int valor);

void iniciar(No **tabela);
int hash(int chave);
void inserir(No **tabela, int valor);
bool buscar (No **tabela, int valor);
bool remover (No **tabela, int valor);
void limpar (No **tabela);
void imprimir (No **tabela);


#endif // HASHTABLE_H_INCLUDED
