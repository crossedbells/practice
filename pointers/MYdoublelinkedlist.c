//Esta eh uma lista de inteiros de 1 a 60

#include<stdio.h>
#include<stdlib.h>
#include "Booleano.h"
#define ghost 0

typedef struct Celula{
	char item;
	struct Celula *next;
	struct Celula *ant;
} Celula;

typedef struct{
	int tamanho;
	Celula *inicio;
	Celula *fim;
} Lista;

//interface
Lista criarLista();				//o construtor cria a lista vazia
bool listaVazia(Lista);			//devolve TRUE se a lista estiver vazia
void mostrarLista(Lista);		//mostra o conteudo da lista a partir do inicio
void mostrarListaDE(Lista);		//mostra o conteudo da lista a partir do fim
void inserir(Lista *, char);		//acrescenta o item no inicio da Lista
void inserirFim(Lista *, char);	//acrescenta o item no final da lista
void removePos(Lista *, int);	//remove o item de ordem k
int obterMaximo(Lista);			//devolve o maior valor existente na lista ou ghost
int localizarMaior(Lista);		//devolve a ordem do maior valor existente na lista ou zero
int obterSoma(Lista);
void inserirOrdenado(Lista*, char);

Lista criarLista(){

    Lista L;
    L.inicio = NULL;
    L.fim = NULL; 
    L.tamanho = 0;

    return L;


}

bool listaVazia(Lista L){
        bool vazia;

        if(L.tamanho != 0)
        {
            vazia = FALSE;
        }

        else{
            vazia = TRUE;
        }

        return L;

}

void mostrarLista(Lista L){

    Celula *aux;

    if(L.tamanho != 0)
    {
        aux = L.inicio;


        while(aux!=NULL){
            printf("%d ", aux->item);
            aux= aux-> next;

        }
    }

}

void mostrarListaDE(Lista L){

    Celula* aux;

    if(L.tamanho != 0){

        aux = L.fim;

        while(aux != NULL)
        {
            printf("%d ", aux->item);
            aux=aux->next;


        }

    }
}

void inserir(Lista* L, char y){

        Celula* nova;
        nova = malloc(sizeof(Celula));
        nova->item=y;
        nova->next=NULL;
        nova->ant=NULL;

        if(L->tamanho!=0)
        {
            Celula *aux;
            aux = L->inicio;

            nova->next=aux; 
            aux->ant=nova;
            L->inicio=nova;
            L->tamanho=L->tamanho+1;

        }

        else{

            nova->next=NULL;
            nova->ant=NULL;
            L->inicio=nova;
            L->fim=nova;
            L->tamanho=L->tamanho+1;



        }

}

void inserirFim(Lista* L, char y)
{
    Celula *nova;
    nova=malloc(sizeof(Celula));
    nova->next=NULL;
    nova->ant=NULL;
    nova->item=y;


    if(L->tamanho != 0){

        Celula *aux;
        aux=L->fim;
        aux->next=nova;
        nova->ant=aux;
        L->fim=nova;
        L->tamanho=L->tamanho+1;
    }

    else{
        nova->next=NULL;
        nova->ant=NULL;
        L->inicio=nova;
        L->fim=nova;
        L->tamanho=L->tamanho+1;
    }

}

int obterSoma(Lista L){

    int soma;
    soma=0;

    if(L.tamanho!=0){

        Celula *aux;
        aux=L.inicio;

        while(aux!=NULL){

            soma = soma + aux->item;
            aux=aux->next;

        }

    }

    return soma;

}

bool verificarSequencia(Lista*L){

//10 9 8 7 6 5 4 3 2 1 0

    bool booleano;
    booleano=TRUE;

    if(L->tamanho!=0){

        Celula* aux;
        aux=L->inicio;

        /*Celula* aux2;
        aux2 = aux->next->item;*/ //NAO PODE FAZER ISSO PORQUE O ITEM É CHAR!!!!!!!

        //char aux2 = aux->next->item;


        while(aux->next != NULL && booleano=TRUE){

            if(aux->item < aux->next->item){
                booleano = FALSE;
            }

            aux=aux->next;



        }

    }

    return booleano;

}
