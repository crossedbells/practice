//PRECISAR TER CABEÇA!!!!!!!!

#define terra
#define fantasma -1
#define NULL //so pra tirar os erros


typedef enum{FALSE, TRUE} bool;

typedef struct Celula{

    int item;
    struct Celula* suc;
    struct Celula* ant;


} Celula;

typedef struct Lista{

    int tamanho;
    Celula* inicio;
    Celula* fim;


} Lista;

Lista criarLista();  
bool ListaVazia(Lista L);  
void mostrarLista(Lista L);  
void mostrarListaDE(Lista L); 
void inserir(Lista *, int);   
void RemovePos(Lista *, int); 
int obterMaximo(Lista);
int obterSoma(Lista);

Lista criarLista(){
    
    Lista L;
    L.tamanho = 0;
    L.inicio = NULL;
    L.fim = NULL;
    return L;

}

bool ListaVazia(Lista L)
{
    if(L.tamanho == 0){
        return TRUE;
    }

    else{
        return FALSE;
    }

    //return(L.tamanho == 0);

}

void mostrarLista(Lista L)
{
    Celula* aux = L.inicio;

    if(ListaVazia(L)){
        printf("Lista vazia");
        return;
    }

    while (aux != NULL){
        printf("%d ", aux -> item);
        aux = aux -> suc;

    }
}

void mostrarListaDE(Lista L) //de tras para frente
{
    Celula* aux = L.fim;

    if(ListaVazia(L)){
        printf("Lista vazia");
        return;
    }

    while(aux != NULL)
    {
        printf("%d", aux -> item);
        aux = aux -> ant;

    }



}

void inserir(Lista *L, int item){

    Celula* nova = malloc(sizeof(Celula));
    nova -> item = item;
    nova -> suc = NULL;
    nova -> ant = NULL;

    if(L -> tamanho == 0){
        L -> inicio = nova;
        L -> fim = nova;
    }
    
    else {
        nova -> ant = L -> fim;
        L -> fim -> suc = nova;
        L -> fim = nova;

    }


    L -> tamanho = L -> tamanho + 1;


}

void removerPos(Lista *L, int pos)
{
    Celula *aux = L-> inicio;
    Celula *anterior;
    Celula *posterior;

    int cont=1;

    while(aux != NULL && cont < pos)
    {
        aux=aux->suc;
        cont++;


    }

    anterior = aux -> ant;
    posterior = aux -> suc;

    if(cont == pos)
    {
        anterior = aux -> posterior;
        posterior = aux -> anterior;
        free(aux);

        L -> tamanho--;

    }


}

/*
inserir no meio da lista 

void inserirPosicao(Lista *L, int item, int pos) {
    // Verificar se a posição é válida
    if (pos < 0 || pos > L->tamanho) {
        printf("Posição inválida\n");
        return;
    }
    
    // Caso especial: inserir no final (usa sua função inserir original)
    if (pos == L->tamanho) {
        inserir(L, item);
        return;
    }
    
    // Caso especial: inserir no início
    if (pos == 0) {
        Celula* nova = malloc(sizeof(Celula));
        nova->item = item;
        nova->ant = NULL;
        nova->suc = L->inicio;
        
        if (L->inicio != NULL) {
            L->inicio->ant = nova;
        }
        L->inicio = nova;
        
        // Se a lista estava vazia
        if (L->tamanho == 0) {
            L->fim = nova;
        }
        
        L->tamanho++;
        return;
    }
    
    // INSERIR NO MEIO: Navegar até a posição desejada
    Celula* aux = L->inicio;
    for (int i = 0; i < pos; i++) {
        aux = aux->suc;
    }
    
    // Criar nova célula
    Celula* nova = malloc(sizeof(Celula));
    nova->item = item;
    
    // Fazer as ligações para inserir ANTES de aux
    nova->ant = aux->ant;  // Nova célula aponta para o anterior de aux
    nova->suc = aux;       // Nova célula aponta para aux
    
    // Atualizar os ponteiros das células vizinhas
    aux->ant->suc = nova;  // Célula anterior agora aponta para nova
    aux->ant = nova;       // aux agora tem nova como anterior
    
    L->tamanho++;
}
*/