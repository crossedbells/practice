/*
Arquivo: problema2.c
Autor: Gabriel Mechi Lima 
Date: 18/02/2025 
Descricao: Programa para verificar se a saida esperada eh igual
a verificada
*/

#include <stdio.h>

int main()
{
	int a = 1547;
	int b = 3276;
	int c = 4823;
	int d;
	int igual = 0;
	d = a + b;
	
	if(c == d)
	 igual = 1;
	
	else
	 igual = 0;
	 
	if (igual == 1)
	{
		printf("igual!!");	
	}
	
	else
	{
		printf("diferente!!");	
		
	} 
	
	return 0;
	
	
	
	
	
}