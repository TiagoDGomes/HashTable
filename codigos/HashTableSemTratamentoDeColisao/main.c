
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hashtable.h"
#define TAMANHO 12

int main()
{
    int minhaTabela[TAMANHO];
    iniciar(&minhaTabela);
    inserir(&minhaTabela, 4);
    inserir(&minhaTabela, 22);
    inserir(&minhaTabela, 8);
    inserir(&minhaTabela, 5);
    inserir(&minhaTabela, 1);
   // inserir(&minhaTabela, 17);
    inserir(&minhaTabela, 9);

    inserir(&minhaTabela, 12);
    inserir(&minhaTabela, 18);
/*  inserir(&minhaTabela, 7);
    inserir(&minhaTabela, 3);
    inserir(&minhaTabela, 5);
   inserir(&minhaTabela, 24);

*/
    imprimir(&minhaTabela);
    printf("Busca:\n");
    printf(" Tem %d? %s\n", 5, buscar(&minhaTabela, 5)!=NULL ? "Sim": "Nao" );
    printf(" Tem %d? %s\n", 14, buscar(&minhaTabela, 14)!=NULL ? "Sim": "Nao" );

    printf("Remover 4...\n");
    remover(&minhaTabela, 4);

    imprimir(&minhaTabela);
    return 0;
}
