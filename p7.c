#include <stdio.h>
#define N 13

int main ()
{
	int k, p1, p2;	
	
	int S1[N], S2[N];
	
		int A[N]={0,1,2,3,4,5,6,7,8,9,10,11,12};
	
	p1=0; 
	p2=0; 
	S1[0]=0; 
	S2[0]=0;
	
	for(k=1; k<N;k++)
	{
		if((A[k] != 2) && (A[k] != 10)) 
		{
		p1++; S1[p1]=A[k];
		}
	}
	
	for(k=1;k<N;k++)
	{
		if((A[k] != 2) || (A[k] != 10)) 
		{
		p2++; S1[p2]=A[k];
		}
	}
	
	return 0;	
}


// S1 = {0 1 3 4 5 6 7 8 9 11 12}; S2 = {2 10}