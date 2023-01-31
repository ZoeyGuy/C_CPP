#include"stdio.h"
int main()
{	
	int i,j,a,b,c,n;
	scanf("%d",&n);
	for(i=0;i<2*n-1;i++)	//先输出第一行星号 
	{
		printf("*");
	}
	printf("\n");
	for(i=2;i<n+1;i++) 
	{
		for(j=1;j<2*n-i+1;j++) 
		{ 
			if(j==i||j==2*n-i)  printf("*");//空格是常态，*是个别，则可以考虑用if判断 
			else  printf(" ");
		}
		printf("\n");
	}
	return 0;
}
