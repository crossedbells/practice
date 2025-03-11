#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	srand(time(NULL));
	
	int nums = rand()%19+1;
	
	int guess;
	int attempts = 0;
	
	printf("Chute um numero entre 1 a 20: ");
	
	while(1)
	{
		scanf("%d", &guess);
		attempts++;
		
		
		if(guess == nums)
		{
			printf("Acertou em %d tentativas!\n", attempts);
			break;
		}
		
		else 
		{
			printf("Tente novamente!\n");
		}
		
		
		
	}
	
	
	


	
}
		