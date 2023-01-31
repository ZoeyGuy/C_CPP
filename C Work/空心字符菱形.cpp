#include"stdio.h"
#include"math.h"
int main()
{
	char ch1,ch2;
	int i=0,j=0,n,D;
	scanf("%c%d",&ch1,&n);
	for(i=n-1;i>=1-n;i--)
	{
		D=n-1-abs(i);
		ch2=ch1+D;
		for(j=1;j<=n+D;j++)
		{
			if(j==n+D||j==abs(i)+1) printf("%c",ch2);
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
