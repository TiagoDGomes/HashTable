
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hashtable.h"
#define TAMANHO 12

int main()
{
    No * minhaTabela[TAMANHO];

    iniciar(&minhaTabela);
    inserir(&minhaTabela, 4);
    inserir(&minhaTabela, 22);
    inserir(&minhaTabela, 8);
    inserir(&minhaTabela, 5);
    inserir(&minhaTabela, 1);
    inserir(&minhaTabela, 17);
    inserir(&minhaTabela, 9);

    int i;
    for (i = 25; i < 40; i++){
        inserir(&minhaTabela, i);
    }
    for (i = 72; i < 118; i=i+2){
        inserir(&minhaTabela, i);
    }
    inserir(&minhaTabela, 12);
    inserir(&minhaTabela, 18);
    inserir(&minhaTabela, 7);
    inserir(&minhaTabela, 3);

    imprimir(&minhaTabela);
    printf("Busca:\n");
    printf(" Tem %d? %s\n", 5, buscar(&minhaTabela, 5) ? "Sim": "Nao" );
    printf(" Tem %d? %s\n", 14, buscar(&minhaTabela, 14) ? "Sim": "Nao" );
    printf(" Tem %d? %s\n", 112, buscar(&minhaTabela, 112) ? "Sim": "Nao" );
    printf(" Tem %d? %s\n", 113, buscar(&minhaTabela, 113) ? "Sim": "Nao" );

    printf("Remover 4...\n");
    remover(&minhaTabela, 4);
    printf("Remover 29...\n");
    remover(&minhaTabela, 29);
    printf("Remover 80...\n");
    remover(&minhaTabela, 80);

    imprimir(&minhaTabela);

    iniciar(&minhaTabela);
    printf("\n\n\n\n");
    for (i = 0 ; i < 50; i++){
        inserir(&minhaTabela, i);
    }
    imprimir(&minhaTabela);
    return 0;
}
