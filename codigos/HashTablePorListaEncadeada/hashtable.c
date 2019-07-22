#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hashtable.h"
#define TAMANHO 12


/* Func�o iniciar
   --------------
   Inicia a tabela, setando os n�s do array para NULL
*/
void iniciar(No **tabela){
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





/* Fun��o novoNo
   ---------------
   Retorna um ponteiro de novo n�.
   Esse novo n� ter� armazenado:
   - o valor passado no par�metro
   - pr�ximo apontando para NULL
*/
No* novoNo(int valor){
    No *novo = (No *) malloc(sizeof(No));
    novo->proximo = NULL;
    novo->valor = valor;
    return novo;
}



/*  Fun��o inserir
    ----------------
    Insere o novo n� na tabela
*/
void inserir(No **tabela, int valor){

    int posicao = hash(valor);

    if (tabela[posicao]==NULL){          // Se n�o tem nada armazenado
        tabela[posicao] = novoNo(valor); // armazena na mesma posi��o
    }else {                              // sen�o
        No *temp = tabela[posicao];      // tempor�rio no n� na posi��o atual do array

        while (temp->proximo != NULL){   // se enquanto 'pr�ximo do tempor�rio' tiver algo
            temp = temp->proximo;        // seta o tempor�rio para seu pr�ximo
        }
        temp->proximo = novoNo(valor);   // seta um novo n� no pr�ximo do tempor�rio
    }


}
/*  Fun��o buscar
    ----------------
    Insere o novo n� na tabela
*/
bool buscar(No **tabela, int valor){
    int posicao = hash(valor);
    No *temp = tabela[posicao];      // tempor�rio no n� na posi��o atual do array

    while (temp != NULL){            // repetir enquanto 'temp' tiver algo
        if (temp->valor == valor){   // se o valor do temp � igual ao valor procurado
            return true;             // retorna True (elemento encontrado)
        }
        temp = temp->proximo;        // seta o tempor�rio para seu pr�ximo
    }
    return false;                    // retorna Falso (elemento n�o encontrado)
}

/*  Fun��o remover
    ----------------
    Exclui um n� na tabela
*/
bool remover(No **tabela, int valor){
    int posicao = hash(valor);
    if (tabela[posicao]==NULL){                             // Se o n� for NULL
        return false;                                       //  - retorna False (elemento n�o encontrado)
    } else {                                                // Sen�o
        No *temp = tabela[posicao];
        if (tabela[posicao]->valor == valor){               //  Se valor do n� for o valor a ser removido
            tabela[posicao]= tabela[posicao]->proximo;      //   - setar o pr�ximo na posi��o raiz
            free(temp);                                     //   - liberar o n� da mem�ria
            return true;                                    //       - retorna True (valor removido)
        } else {                                            //  Sen�o
            while (temp->proximo!=NULL){                    //   * repetir enquanto o proximo do tempor�rio for diferente de NULL
                if (temp->proximo->valor == valor){         //     - se o valor do proximo for o valor para remover
                    No *tempDel = temp->proximo;            //       - setar o que dever� ser apagado da mem�ria
                    temp->proximo = temp->proximo->proximo; //       - proximo do tempor�rio ser� o pr�ximo do pr�ximo do tempor�rio
                    free(tempDel);                          //       - liberar o n� da mem�ria
                    return true;                            //       - retorna True (valor removido)
                }                                           //     -
                temp = temp->proximo;                       //     - posicionar temp para o seu pr�ximo
            }
        }
    }
    return false;                       // retorna Falso (elemento n�o encontrado)
}
void imprimir (No **tabela){
    int i;
    for (i = 0; i < TAMANHO; i++){
        printf("%2d : ",i);

        No *temp = tabela[i];

        while (temp != NULL){
            printf(" %3d ->", temp->valor);
            temp = temp->proximo;
            printf("%s", (temp== NULL)? "   |" : "");
        }

        printf("\n");
    }
}
