#include <stdio.h>
#define N 13

main ()
{
	int k;
	int A[N]={0,1,2,3,4,5,6,7,8,9,10,11,12};

	printf("\n");

	for(k=1; k<N; k++)
	{  
	  if((A[k]!= 2) && (A[k] != 10))
	  
	  printf("%d", A[k]);
	  
	  else (printf("*"));
	  
	  	
		
		
	}	
	
	
	return 0;

	
	
}