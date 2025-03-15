#include <stdio.h>
#include <string.h>

//se o usuario digitar dog imprime woof 
//se cat, imprime meow

int main()
{
	char canine[10] = "woof";
	char feline[10] =  "meow";
	
	char input[10];
	
	printf("type either >dog< or >cat<: ");
	scanf("%s", input);
	
	if(strcmp(input, "dog") == 0)
	{
		printf("\n%s\n", canine);	
	}
	
	else if (strcmp(input, "cat") == 0)
	{
		printf("\n%s\n", feline);
	}
	
}