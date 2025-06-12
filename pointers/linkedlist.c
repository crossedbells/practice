#define fantasma -1

#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\User\Documents\PUC\3 SEM\EDL\practice\Booleano.h"

typedef struct Celula {
    int item;
    struct Celula* next;
} Celula;

typedef struct {
    int tamanho;
    Celula* inicio;
} Lista;


Lista criarLista();
bool verListaVazia(Lista L);
void inserirLista(Lista* L, int y);
void removerPrimeiro(Lista* ap);
int obterTamanho(Lista ap);
void removerUltimo(Lista* ap);
int obterElemento(Lista* ap, int k);
Celula* buscarItem(Lista* ap, int y);

Lista criarLista(){
    Lista L;
    L.tamanho = 0;
    L.inicio = NULL;
    return L;
}

bool verListaVazia(Lista ap) {
    bool vazio;
    if (ap.inicio == NULL) { 
        vazio = TRUE;
    } else {
        vazio = FALSE;
    }
    return vazio;
}

void inserirLista(Lista* ap, int y) {
    Celula *novo;
    novo = malloc(sizeof(Celula));
    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }

    novo->item = y;
    novo->next = ap->inicio; 
    ap->inicio = novo;       

    ap->tamanho = ap->tamanho + 1; 
}

void removerPrimeiro(Lista* ap) {
    Celula *prim, *seg;

    if (ap->inicio != NULL) { 
        prim = ap->inicio;   
        seg = prim->next;
        ap->inicio = seg;     
        ap->tamanho = ap->tamanho - 1; 
        free(prim);
    }
}

int obterTamanho(Lista ap) {
    return ap.tamanho; 
}

void removerUltimo(Lista* ap) {
    if (verListaVazia(*ap)) {
        return;
    }

    if (ap->tamanho == 1) { 
        free(ap->inicio);   
        ap->inicio = NULL;
        ap->tamanho = 0;
        return;
    }

    Celula *atual = ap->inicio;
    while (atual->next->next) {
        atual = atual->next;
    }

    Celula *ultimo = atual->next;
    atual->next = NULL;
    free(ultimo);

    ap->tamanho--;
}

int obterElemento(Lista* ap, int k) {
    int i = 0;

    if (k < 0 || k >= ap->tamanho) {
        return fantasma;
    }

    Celula *atual = ap->inicio;

    while (i < k && atual != NULL) {
        atual = atual->next;
        i++;
    }

    if (atual != NULL) {
        return atual->item;
    } else {
        return fantasma;
    }
}

Celula* buscarItem(Lista* ap, int y) {
    Celula *atual = ap->inicio; // Usando ap->inicio
    while (atual != NULL) { // Corrigido para comparar com NULL
        if (atual->item == y) {
            return atual;
        }
        atual = atual->next;
    }
    return NULL; // Retorna NULL se o item nao for encontrado
}

int main() {
    // Criacao da lista
    Lista minhaLista = criarLista();

    // Testando se a lista esta vazia
    if (verListaVazia(minhaLista)) {
        printf("A lista esta vazia.\n");
    }

    // Inserindo elementos na lista
    inserirLista(&minhaLista, 10);
    inserirLista(&minhaLista, 20);
    inserirLista(&minhaLista, 30);

    // Mostrando o tamanho da lista
    printf("Tamanho da lista: %d\n", obterTamanho(minhaLista));

    // Testando se a lista esta vazia novamente
    if (!verListaVazia(minhaLista)) {
        printf("A lista nao esta mais vazia.\n");
    }

    // Removendo o primeiro elemento
    removerPrimeiro(&minhaLista);
    printf("Tamanho da lista apos remover o primeiro elemento: %d\n", obterTamanho(minhaLista));

    // Buscando um elemento na lista
    int elemento = 20;
    Celula* encontrado = buscarItem(&minhaLista, elemento);
    if (encontrado != NULL) {
        printf("Elemento %d encontrado na lista.\n", elemento);
    } else {
        printf("Elemento %d nao encontrado na lista.\n", elemento);
    }

    // Obtendo um elemento pelo indice
    int indice = 1;
    int valor = obterElemento(&minhaLista, indice);
    if (valor != fantasma) { // Corrigido para comparar com fantasma
        printf("Elemento no indice %d: %d\n", indice, valor);
    } else {
        printf("Indice %d invalido.\n", indice);
    }

    // Removendo o ultimo elemento
    removerUltimo(&minhaLista);
    printf("Tamanho da lista apos remover o ultimo elemento: %d\n", obterTamanho(minhaLista));

    // Finalizando o programa
    printf("Teste concluido.\n");
    return 0;
}