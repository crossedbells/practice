/* atividade L1 */
/* Arquivo: Amora_Marinho_MachadoATL1.c
   Autores: Alexandre Maciano de Oliveira
            Amora Marinho Machado	
            Gabriel Mechi Lima
            Luiz Fernando de Marchi Andrade
   Data: 11/03/2025
   Descrição: verificar existência de duplicatas em uma lista
*/


//preenche o vetor com números aleatorios entre 1 e 9
void construirNumeros(unsigned char V[]){
	
	int i;
	
	srand(time(NULL));
	
	for(i=1;i<Max;i++)
		V[i]=(rand()%9)+1;  //inicializa uma semente que gera numeros aleatorios
}

//exibe os numeros armazenados no vetor
void mostrarNumeros(unsigned char V[]){
	
	int i;
	
	printf("Numeros armazenados: ");
	
	for(int i=1;i<Max;i++)
		printf("%d ", V[i]);
	printf("\n");
}

bool verificarRepetido(unsigned char V[]){
	
	bool repete=FALSE;
	int i=1;
	int j=2;
	
	while(i<(Max-1) && repete==FALSE){
		while(j<Max && repete==FALSE){
			if(V[i]==V[j])
				repete=TRUE;
			else
				j++;
		}
		i++;
		j=i+1;  //incrementa j para que a comparacao funcione corretamento com os numeros seguintes
					
	}	
	return repete;
}