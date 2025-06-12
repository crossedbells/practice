#define Max 10
#define sinal 0
#define fantasma $

typedef struct{

    int topo;
    unsigned char vetor[Max];

}

Pilha criarPilha(){
    
    Pilha S;
    S.topo = sinal;
    S.vetor = Max-1;

    return S;

}

//adcionar elemento
Pilha pushPilha(Pilha S, unsigned char Ch){

    if(S.topo != S.vetor[0]){   //verifica se é possivel adcionar mais um elemento
                                //(usando o vetor 0 como limite do tamanho, verifica se ainda tme espaço)
        S.topo = S.topo + 1;
        S.vetor[S.topo] = Ch;

    }

}

//remover elemento
Pilha popPilha(Pilha S){
    
    if(S.topo != sinal)  //verifica se a pilha é vazia
        S.topo = S.topo - 1;
        
    return S;
    
}

unsigned char acessarPilha(Pilha S){

    unsigned char y;
    int p;

    if(S.topo != sinal){  //verifica se a lista não é vazia
        p = S.topo; 
        y = S.vetor[p];
    }

    else y = fantasma;

    return y;

}

Pilha esvaziarPilha(Pilha S){

    S.topo = sinal;
    
    return S;

}

bool PilhaVazia(Pilha S){

    return (S.tipo == 0);

}