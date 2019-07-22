#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hashtable.h"
#define TAMANHO 12


/* Funcão iniciar
   --------------
   Inicia a tabela, setando os nós do array para NULL
*/
void iniciar(No **tabela){
    int i;
    for (i = 0; i < TAMANHO; i++){
        tabela[i] = NULL;
    }
}


/* Função Hash
   --------------
   Essa função tem por finalidade gerar o índice para
   posicionar o elemento no array
*/

int hash(int chave){
    return chave % TAMANHO; // nesse caso gera um valor de 0 a TAMANHO-1 (resto da divisão por TAMANHO)
}





/* Função novoNo
   ---------------
   Retorna um ponteiro de novo nó.
   Esse novo nó terá armazenado:
   - o valor passado no parâmetro
   - próximo apontando para NULL
*/
No* novoNo(int valor){
    No *novo = (No *) malloc(sizeof(No));
    novo->proximo = NULL;
    novo->valor = valor;
    return novo;
}



/*  Função inserir
    ----------------
    Insere o novo nó na tabela
*/
void inserir(No **tabela, int valor){

    int posicao = hash(valor);

    if (tabela[posicao]==NULL){          // Se não tem nada armazenado
        tabela[posicao] = novoNo(valor); // armazena na mesma posição
    }else {                              // senão
        No *temp = tabela[posicao];      // temporário no nó na posição atual do array

        while (temp->proximo != NULL){   // se enquanto 'próximo do temporário' tiver algo
            temp = temp->proximo;        // seta o temporário para seu próximo
        }
        temp->proximo = novoNo(valor);   // seta um novo nó no próximo do temporário
    }


}
/*  Função buscar
    ----------------
    Insere o novo nó na tabela
*/
bool buscar(No **tabela, int valor){
    int posicao = hash(valor);
    No *temp = tabela[posicao];      // temporário no nó na posição atual do array

    while (temp != NULL){            // repetir enquanto 'temp' tiver algo
        if (temp->valor == valor){   // se o valor do temp é igual ao valor procurado
            return true;             // retorna True (elemento encontrado)
        }
        temp = temp->proximo;        // seta o temporário para seu próximo
    }
    return false;                    // retorna Falso (elemento não encontrado)
}

/*  Função remover
    ----------------
    Exclui um nó na tabela
*/
bool remover(No **tabela, int valor){
    int posicao = hash(valor);
    if (tabela[posicao]==NULL){                             // Se o nó for NULL
        return false;                                       //  - retorna False (elemento não encontrado)
    } else {                                                // Senão
        No *temp = tabela[posicao];
        if (tabela[posicao]->valor == valor){               //  Se valor do nó for o valor a ser removido
            tabela[posicao]= tabela[posicao]->proximo;      //   - setar o próximo na posição raiz
            free(temp);                                     //   - liberar o nó da memória
            return true;                                    //       - retorna True (valor removido)
        } else {                                            //  Senão
            while (temp->proximo!=NULL){                    //   * repetir enquanto o proximo do temporário for diferente de NULL
                if (temp->proximo->valor == valor){         //     - se o valor do proximo for o valor para remover
                    No *tempDel = temp->proximo;            //       - setar o que deverá ser apagado da memória
                    temp->proximo = temp->proximo->proximo; //       - proximo do temporário será o próximo do próximo do temporário
                    free(tempDel);                          //       - liberar o nó da memória
                    return true;                            //       - retorna True (valor removido)
                }                                           //     -
                temp = temp->proximo;                       //     - posicionar temp para o seu próximo
            }
        }
    }
    return false;                       // retorna Falso (elemento não encontrado)
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
