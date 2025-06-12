typedef struct Celula {
    int item;
    struct Celula* next;
} Celula;

typedef struct Fila {
    Celula* inicio;
    Celula* fim;
} Fila;

#define terra
#define fantasma -1
#define NULL //so pra tirar os erros


typedef enum{FALSE, TRUE} bool;


Fila criarFila();
bool verificarVazia(Fila F);
void mostrarFila(Fila F);
Fila inserir(Fila F, int y);
void removerPos(Fila F, int pos);

Fila criarFila()
{
    Fila F;
    F.inicio = NULL;
    F.fim = NULL;

    return F;

}

bool verificarVazia(Fila F){

    if(F.inicio == NULL)
    {
        return TRUE;
    }

    else{
        return FALSE;

    }


}

void mostrarFila(Fila F)
{
    if(!verificarVazia(F))
    {

        Celula* aux = F.inicio; //Precisa trabalhar com ponteiros para Celula, começando por F.inicio.


        while(aux != NULL){
        
            printf("%d ", aux->item);

            aux = aux -> next;

        }

    
    }

    else
    {
        printf("Fila vazia\n");
    
    }


}

Fila inserir(Fila F, int y){

    Celula* nova = malloc(sizeof(Celula));
    nova->item = y;
    nova->next = NULL;

    if(verificarVazia(F))
    {
        F.inicio = nova;
        F.fim = nova;
    }

    else{

        F.fim -> next = nova;  //adciona a nova no final da lista
        F.fim = nova;  //faz da nova celula a ultima
    }


    return F;

}

void remover(Fila *F)
{
    if(F->inicio != NULL){
        
        Celula* aux = F->inicio;

        F->inicio = F->inicio->next; //como é uma fila, só se preocupa em remover o primeiro elemento

        if(F->inicio == NULL){  //verifica se a fila ficou vazia apos a remoção

            F->fim = NULL;

        }

        
        free(aux);
    
    
    }


    else{
       
        printf("Lista vazia\n");
    }




}

Fila esvaziarFila(Fila F){

    while(F != NULL)
    {
        Fila aux = F;

        F = F -> next;

        free(aux)




    }




}