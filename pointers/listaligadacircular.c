typedef enum{FALSE, TRUE} bool;

/*Como estamos tratando de uma lista ligada circular, usaremos o
inicio como conticional de para de loop. 

LISTA CIRCULAR NÃO TEM VALOR NULL!!!!!!!

*/

#define terra NULL
#define fantasma -1
#define NULL //so pra tirar os erros
typedef enum{FALSE, TRUE} bool;

typedef struct{

    int elemento;
    struct Celula* next;
} Celula;

typedef Celula* Lista;

Lista criarLista();
void mostrarLista(Lista L);


Lista criarLista()
{
    Lista L;
    L = NULL;

    return L;

}

bool listaVazia(Lista L){

    if(L == NULL){
     return TRUE
    }

    else{
     return FALSE;

    }  

}



void mostrarLista(Lista L)
{
    int k;

    if(L == NULL)
    {
        printf("Lista vazia\n");

    }

    else   
    {
        Lista aux = L;

        do
        {
            k = aux -> elemento;


            printf("%d", aux -> elemento); //imprime valor do item atual
            aux = aux -> next;

         } while(aux != L); //como a lista é circular, devemos usar do/while para garantir que o loop
                            //seja executaod pelo menos uma vez

    }

}










void mostrarLista(Lista L){ // a partir do primeiro
    
    Lista aux;
    int k;
    
    if (L == NULL) 
        printf("lista vazia \n");
   
    else { 
        
        aux = L; 
        
        do 
        {
                k = aux->elemento;  
                
                printf(" %d ", k);
            
                aux = aux->next;     
       
            } while (aux != L);
    
    }
    
    printf("\n");
    
}
    

void resolverJosepehus(Lista *L, int M)
{
    int n = obterTamanho(*L);
    Celula *p, *ant, *morto;
    int c;

    if(n>1)
    {
        p = L; 
        c = 1;

        do
        {
           ant = p;
           p = p-> next;
           c = c+1;
           
           if(c == M)
           {
                morto = p;
                p = p -> next;
                ant -> next = p; //remove o elemento morto
                free(morto); //libera a memória do elemento morto
                
                c=1;
                
                n = n-1;

           }
     
        } while (n > 1);
        
        *L = p; //ultimo sobrevivente

    }


}
    