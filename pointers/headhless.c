#define fantasma -1

#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\User\Documents\PUC\3 SEM\EDL\practice\Booleano.h"
#define terra


typedef struct Celula {
    int item;
    struct Celula* next;
} Celula;

typedef Celula* Lista;

Lista newLista();
bool listaVazia(Lista L);
int obterTamanho(Lista L);
char obterElemento(Lista L, int k);
Celula* buscarItem(Lista L, int y);
void mostrarLista(Lista L);
Lista inserirLista(Lista L, int y);
Lista inserirNoFim(Lista, char);
Lista removerPrimeiro(Lista L);
Lista esvaziarLista(Lista L);
Lista removerUltimo(Lista L);

Lista newLista(){
    
    Lista L;
    L = NULL; 
    return L;


}

bool listaVazia(Lista L){
    bool vazia = FALSE;

    if(L == NULL)
    {
        vazia = TRUE;
    }

    return vazia; //retorna true ou false 
}

int obterTamanho(Lista L){
    int tam = 0;

    Lista aux = L;

    while (aux != NULL){
        tam++;
        aux = aux -> next;



    }

    return tam;


}

char obterElemento(Lista L, int k){
    int i;
    char a; //para retornar o valor que for encotrado

    /*if (k < 0){
        return fantasma;
    }*/

    Lista aux = L;

    while (i < k && aux != NULL){
        aux = aux -> next;
        i++;
    }

    if(aux != NULL)
    {
        a = aux -> item;
        return a;


    }



    /*if (aux == NULL) {
        return fantasma;
    }*/

    return aux -> item;

}

Celula *buscarItem(Lista L, int y)
{
    Lista aux = L;

    while (aux != NULL){
        if (aux -> item == y){
            return aux;
        }

        aux = aux -> next;
    }


        return NULL;
}


void mostrarLista(Lista L)
{
    if(L == NULL)
    {
        printf("Lista vazia\n");

    }

    Lista aux = L;

    while(aux != NULL)
    {
        printf("%d", aux -> item); //imprime valor do item atual
        aux = aux -> next;

    }
}

Lista inserirLista(Lista L, int y)
{
    Celula *nova = malloc(sizeof(Celula));

    nova -> item = y;
    nova -> next = L;

    L = nova;

    return L;

}

Lista inseirNoFim(Lista L, int y){

    Celula *nova = malloc(sizeof(Celula));

    nova -> item = y;
    nova -> next = NULL; //pois é acrescentada no final da lista

    if(L == NULL)
    {
       return nova; 
    }

    Celula *aux = L;

    while(aux -> next != NULL){

        aux = aux -> next;

    }

    aux -> next = nova;

    return L;

}


Lista removerPrimeiro(Lista L)
{
    Celula *aux;

    if(L != NULL){
        aux = L;
        L = aux -> next;
        free(aux);
    }

    return L;

}

Lista esvaziarLista(Lista L)
{
    while(L != NULL)
    {
        Lista aux = L;
        L = L -> next;
        free(aux);                          

        
    }

    return L;
}


Lista removerUltimo(Lista L)
{

    if(L -> next == NULL){  //se a lista tiver so um elemento

        free(L);
        return NULL;

    }

    Lista aux = L;

    while(aux -> next -> next != NULL)
    {
        aux = aux -> next;

    }

    free(aux -> next);
    aux -> next = terra;
    return L;

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
    printf("Lista Los remover o primeiro elemento: ");
    mostrarLista(minhaLista);
    printf("\n");

    // Removendo o ultimo elemento
    minhaLista = removerUltimo(minhaLista);
    printf("Lista Los remover o ultimo elemento: ");
    mostrarLista(minhaLista);
    printf("\n");

    // Esvaziando a lista
    minhaLista = esvaziarLista(minhaLista);
    printf("Lista Los esvaziar: ");
    mostrarLista(minhaLista);
    printf("\n");

    // Finalizando o programa
    printf("Teste concluido.\n");
    return 0;
}








void remover(Fila *F) {
    if (F->inicio == NULL) {
        printf("Fila vazia\n");
        return;
    }

    Celula* aux = F->inicio;

    F->inicio = F->inicio->next;

    // Se a fila ficou vazia depois da remoção, atualiza F->fim
    if (F->inicio == NULL) {
        F->fim = NULL;
    }

    free(aux);
}