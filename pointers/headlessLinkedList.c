#define fantasma -1

#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\User\Documents\PUC\3 SEM\EDL\practice\Booleano.h"

typedef struct Celula {
    int item;
    struct Celula* next;
} Celula;

typedef Celula* Lista;

Lista newLista();
bool listaVazia(Lista ap);
int obterTamanho(Lista ap);
char obterElemento(Lista ap, int k);
Celula* buscarItem(Lista ap, int y);
void mostrarLista(Lista ap);
Lista inserirLista(Lista ap, int y);
Lista removerPrimeiro(Lista ap);
Lista esvaziarLista(Lista ap);
Lista removerUltimo(Lista ap);

Lista newLista(){
    return NULL;
}

bool listaVazia(Lista ap){
    return ap == NULL;
}

int obterTamanho(Lista ap){
    int tamanho = 0;

    Lista atual = ap;

    while (atual != NULL){
        tamanho++;
        atual = atual -> next;



    }

    return tamanho;


}

char obterElemento(Lista ap, int k){
    int i = 0;

    if (k ==  NULL || k < 0){
        return fantasma;
    }

    Lista atual = ap;

    while (i < k && atual != NULL){
        atual = atual -> next;
        i++;
    }

    if (atual == NULL) {
        return fantasma;
    }

    return atual -> item;

}

Celula *buscarItem(Lista ap, int y)
{
    Lista atual = ap;

    while (atual != NULL){
        if (atual -> item == y){
            return atual;
        }

        atual = atual -> next;
    }


        return NULL;
}


void mostrarLista(Lista ap)
{
    if(ap == NULL)
    {
        printf("Lista vazia\n");
        return;

    }
    Lista atual = ap;

    while(atual != NULL)
    {
        printf("%d", atual -> item);
        atual = atual -> next;

    }


}

Lista inserirLista(Lista ap, int y)
{
    Celula *nova = (Celula*)malloc(sizeof(Celula));

    if(nova == NULL){return ap;}

    novo -> item = y;
    novo -> next = ap;

    return novo;

}


Lista removerPrimeiro(Lista ap)
{
    if (ap == NULL) {
        return NULL;
    }

   Lista seg = ap -> next;
   free(ap);

   return seg;

}

Lista esvaziarLista(Lista ap)
{
    while(ap != NULL)
    {
        Lista aux = ap;
        ap = ap -> next;
        free(aux);                          

        return ap;



    }


}


Lista removerUltimo(Lista ap)
{
    if(ap == NULL)
    {
        return NULL;

    }

    if(ap -> next == NULL){

        free(ap);
        return NULL;

    }

    Lista atual = ap;
    while(atual -> next -> next != NULL)
    {
        atual = atual -> next;

    }

    free(atual -> next);
    atual -> next = NULL;
    return ap;

}

int main() {
    // Criando uma nova lista
    Lista minhaLista = newLista();

    // Verificando se a lista esta vazia
    if (listaVazia(minhaLista)) {
        printf("A lista esta vazia.\n");
    }

    // Inserindo elementos na lista
    minhaLista = inserirLista(minhaLista, 10);
    minhaLista = inserirLista(minhaLista, 20);
    minhaLista = inserirLista(minhaLista, 30);

    // Mostrando os elementos da lista
    printf("Elementos da lista: ");
    mostrarLista(minhaLista);
    printf("\n");

    // Obtendo o tamanho da lista
    printf("Tamanho da lista: %d\n", obterTamanho(minhaLista));

    // Buscando um elemento na lista
    int elemento = 20;
    Celula* encontrado = buscarItem(minhaLista, elemento);
    if (encontrado != NULL) {
        printf("Elemento %d encontrado na lista.\n", elemento);
    } else {
        printf("Elemento %d nao encontrado na lista.\n", elemento);
    }

    // Obtendo um elemento pelo indice
    int indice = 1;
    char valor = obterElemento(minhaLista, indice);
    if (valor != fantasma) {
        printf("Elemento no indice %d: %d\n", indice, valor);
    } else {
        printf("Indice %d invalido.\n", indice);
    }

    // Removendo o primeiro elemento
    minhaLista = removerPrimeiro(minhaLista);
    printf("Lista apos remover o primeiro elemento: ");
    mostrarLista(minhaLista);
    printf("\n");

    // Removendo o ultimo elemento
    minhaLista = removerUltimo(minhaLista);
    printf("Lista apos remover o ultimo elemento: ");
    mostrarLista(minhaLista);
    printf("\n");

    // Esvaziando a lista
    minhaLista = esvaziarLista(minhaLista);
    printf("Lista apos esvaziar: ");
    mostrarLista(minhaLista);
    printf("\n");

    // Finalizando o programa
    printf("Teste concluido.\n");
    return 0;
}