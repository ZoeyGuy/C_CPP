#include"stdio.h"
int main()
{
	int n,i,j,k,flag=0;
	scanf("%d",&n);
	if(n%2==0||n%5==0) printf("NO");
	else
	{
		for(i=0;n>=10;i++)
		{
			n=n%100;
			if(n%2==0||n%3==0||n%5==0||n%7==0) {printf("NO");flag++;break;}
			n=n/10;
		}
		if(flag==0) printf("YES");
	}
	return 0;
}
