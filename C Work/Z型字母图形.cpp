#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>
int main()
{
	int n;
	char cc,ss;
	scanf("%d,%c",&n,&cc);
	int cc1=cc-'a';
	for(int i=0;i<n;i++) printf("%c",(cc1+i)%26+'a');
	printf("\n");
	int j; 
	for(int i=0;i<n-2;i++)
	{
		for(j=0;j<n-i-2;j++) printf(" ");
			if(j==n-i-2) printf("%c",(cc1+n+i)%26+'a');
		printf("\n");
	}
	for(int i=0;i<n;i++) printf("%c",(cc1+2*n-2+i)%26+'a');
	printf("\n");
	return 0;
}
