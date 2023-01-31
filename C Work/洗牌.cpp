#include"stdio.h"
#define N 100000
int main()
{
	int n=0,a[N]={0},b[N]={0},i=0,flag=0;
	scanf("%d",&n);
	for(i=0;i<=2*n-1;i++) a[i]=i+1;
	do 	{	
			for(i=0;i<=2*n-1;i++) b[i]=a[i];
			for(i=0;i<=n-1;i++)
			{
				a[2*i+1]=b[i];
				a[2*i]=b[n+i];
			}
			flag++;
		}
	while(a[0]!=1);
	printf("%d\n",flag); 
	return 0;
}
