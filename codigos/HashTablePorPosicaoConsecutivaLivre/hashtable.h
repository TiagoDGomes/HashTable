#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void iniciar(int tabela[]);
int hash(int chave);
void inserir(int tabela[], int valor);
int buscar (int tabela[], int valor);
int remover (int tabela[], int valor);
void limpar (int tabela[]);
void imprimir (int tabela[]);


#endif // HASHTABLE_H_INCLUDED
