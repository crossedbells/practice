// Lista Ligada sem cabeça
// Arquivo: "AmoraMarinhoMachado_ListaLigada.c"
// Autora: Amora Marinho Machado
// Data: 28/05/2025
// Descrição: implementação de funções de uma lista ligada sem cabeça

//Inclusões de Biblioteca
#include <stdlib.h>		//Para malloc
#include <stdio.h>		//Para printf

//Estruturas
typedef enum{FALSE, TRUE} bool;

typedef struct Celula{
	char item;
	struct Celula *next;
}Celula;

typedef Celula *Lista;

//Interfaces
Lista newLista();
bool ListaVazia(Lista);
int obterTamanho(Lista);
char obterElemento(Lista, int);
Celula* buscarItem(Lista, char);
void mostrarLista(Lista);
Lista inserirLista(Lista, char);
Lista inserirNoFim(Lista, char);
Lista removerPrimeiro(Lista);
Lista esvaziarLista(Lista);
Lista removerUltimo(Lista);
//Função Main
int main(void){
	Lista A;
	A=newLista();
	printf("A lista eh vazia? %d\n", ListaVazia(A));
	printf("O tamanho da lista eh: %d\n", obterTamanho(A));
	A=inserirLista(A, 'A');
	A=inserirLista(A, 'm');
	A=inserirLista(A, 'o');
	A=inserirLista(A, 'r');
	A=inserirLista(A, 'a');
	printf("A lista eh vazia? %d\n", ListaVazia(A));
	mostrarLista(A);
	printf("O tamanho da lista eh: %d\n", obterTamanho(A));
	A=removerUltimo(A);
	printf("Remove Ultimo\n");
	mostrarLista(A);
	printf("Remove Primeiro\n");
	A=removerPrimeiro(A);
	mostrarLista(A);
	printf("O tamanho da lista eh: %d\n", obterTamanho(A));
	printf("Insere 'a' no fim\n");
	A=inserirNoFim(A, 'a');
	mostrarLista(A);
	printf("O terceiro item eh: %c\n", obterElemento(A,3));
	printf("O endereco que contem o item 'a' eh: %p\n", buscarItem(A, 'a'));
	printf("O endereco que contem o item 'z' eh: %p\n", buscarItem(A, 'z'));
	A=removerPrimeiro(A);
	A=removerPrimeiro(A);
	A=removerPrimeiro(A);
	mostrarLista(A);
	A=removerPrimeiro(A);
	mostrarLista(A);
	A=removerUltimo(A);
	A=inserirNoFim(A, 'A');
	A=inserirNoFim(A, 'm');
	A=inserirNoFim(A, 'o');
	A=inserirNoFim(A, 'r');
	A=inserirNoFim(A, 'a');
	mostrarLista(A);
	printf("A lista eh vazia? %d\n", ListaVazia(A));
	printf("O tamanho da lista eh: %d\n", obterTamanho(A));
	printf(" ESVAZIA LISTA\n");
	A=esvaziarLista(A);
	mostrarLista(A);
	printf("A lista eh vazia? %d\n", ListaVazia(A));
	printf("O tamanho da lista eh: %d\n", obterTamanho(A));
	
	return 0;
}

//Implementações
Lista newLista(){
	Lista L;
	L=NULL;
	return L;
}
bool ListaVazia(Lista L){
	bool vazia=FALSE;
	if(L==NULL)
		vazia=TRUE;
	return vazia;
}
int obterTamanho(Lista L){
	int tam=0;
	Celula *aux;
	if (L!=NULL){
		aux=L; tam=1;
		while(aux->next!=NULL){
			aux=aux->next;
			tam++;
		}
	}
	return tam;
}
char obterElemento(Lista L, int k){
	char a;
	int j; Celula *aux;
	if(L!=NULL){
		aux=L; j=1;
		while(aux->next!=NULL && j!=k){
			aux=aux->next;
			j++;
		}
		if(j==k)
			a=aux->item;
	}
	return a;
}
Celula* buscarItem(Lista L, char a){
	Celula *final=NULL;
	Celula *aux;
	if(L!=NULL){
		aux=L;
		while(aux->next!=NULL && aux->item!=a)
			aux=aux->next;
		if(aux->item==a)
			final=aux;
	}
	return final;	
}
void mostrarLista(Lista L){
	Celula *aux;
	if(L!=NULL){
		aux=L;
		printf("Lista: ");
		do{
			printf("%c ", aux->item);
			aux=aux->next;
		}while(aux!=NULL);
		printf("\n");
	} else{
		printf("Lista Vazia!\n");
	}
}
Lista inserirLista(Lista L,char a){
	Celula *nova;
	nova=malloc(sizeof(Celula));
	nova->item=a;
	nova->next=L;
	L=nova;
	return L;
}
Lista inserirNoFim(Lista L, char a){
	Celula *nova, *aux;
	nova=malloc(sizeof(Celula));
	if(L!=NULL){
		aux=L;
		while(aux->next!=NULL)
			aux=aux->next;
		nova->item=a;
		aux->next=nova;
		nova->next=NULL;
	}else{
		nova->item=a;
		L=nova;
		nova->next=NULL;
	}
	return L;
}
Lista removerPrimeiro(Lista L){
	Celula *sai;
	if(L!=NULL){
		sai=L;
		L=sai->next;
		free(sai);
	}
	return L;
}
Lista esvaziarLista(Lista L){
	Celula *aux, *aux2;
	if(L!=NULL){
		do{
			aux=L;
			while(aux->next!=NULL){
				aux2=aux;
				aux=aux->next;
			}
			aux2->next=NULL;
			free(aux);
		}while(aux2!=aux);
		L=NULL;
	}
	return L;
}
Lista removerUltimo(Lista L){
	Celula *aux, *aux2;
	if(L!=NULL){
		aux=L;
		if(aux->next==NULL){
			L=NULL;
			free(aux);
		}else{
			while(aux->next!=NULL){
				aux2=aux;
				aux=aux->next;
			}
			aux2->next=NULL;
			free(aux);
		}
	}
	return L;
}

//Resultados:
// 1) newLista 			FUNCIONA
// 2) ListaVazia 		FUNCIONA
// 3) obterTamanho 		FUNCIONA
// 4) obterElemento		FUNCIONA
// 5) buscarItem		FUNCIONA	
// 6) mostrarLista  	FUNCIONA
// 7) inserirLista		FUNCIONA
// 8) removerPrimeiro	FUNCIONA
// 9) esvaziarLista		FUNCIONA
// 10) removerUltimo	FUNCIONA