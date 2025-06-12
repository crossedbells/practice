#include <stdio.h>
#include <stdlib.h>

typedef enum{FALSE, TRUE} bool;

typedef struct Celula
{
    char item;
    struct Celula *next;
}Celula;

typedef Celula *Lista;

//criar lista sem cabeça
Lista criarLista(){

    Lista L;
    L=NULL;
    return L;

}

bool verificarVazia(Lista L){

    bool vazia = FALSE;

    if(L == NULL)
    {
        vazia = TRUE;
    }

    return vazia;

}

int obterTamanho(Lista L){

    int tam = 1;
    Celula *aux;

    if(L != NULL){

        aux = L;


        while(aux->next != NULL)
        {
            aux = aux -> next;
            tam++;

        }

        return tam;

    }



}

obterElemento(Lista L, int k) //k = elemento que queremos obter
{
    Celula* aux;
    char elemento;
    int j=1; //variavel auxiliar de controle de loop

    if(L != NULL)
    {
        aux = L; 
        
        while(aux->next != NULL && j != k)
        {
            aux = aux->next;
            j++;

        }

        if(j==k)
        {
            elemento = aux->item;
        }

        return elemento;

    }

}


Celula* buscarItem(Lista L, char item){

    Celula *aux;
    Celula *retorno = NULL;

    if(L != NULL){

        aux = L;

        while(aux != NULL && aux ->item !=item){
            aux = aux->next;
            }

        if(aux->item == item)
        {
            retorno = aux;
        }

    }

    return retorno;

}      

void mostrarLista(Lista L){

    Celula *aux;

    if(L!= NULL){
        aux = L;

        while(aux != NULL){
            printf("%c", aux->item);
            aux=aux->next;
        }
    }

    else{
        printf("Lista vazia\n");
    }

}

Lista inserirLista(Lista L, char a){

    Celula* nova = malloc(sizeof(Celula));
    Celula* aux;

    nova->item = a;
    nova->next = L; //faz a nova celula apontar para o inicio da lista atual
    L = nova; //atualizando L para apontar para o novo inicio da lista

    return L;

}