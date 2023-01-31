#include"stdio.h"
#include"math.h"
int main()
{	int n,s;
	scanf("%d",&n);
	for(int i=0;i<pow(n,2);i++)
	{	s=i+1;
		printf("%3d",s);
		if(s%n==0)	printf("\n");
	}
	return 0;
}
