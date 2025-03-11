#include <stdio.h>

int main()
{
	int num;
	int fatorial = 1;
	
  	printf("Digite um int: ");
  	scanf("%d", &num);
  	
  	while(num > 0)
  	{
  		fatorial *= num;
  		num--;
  		
  	}

	printf("\nFatorial: %d", fatorial);

}
		