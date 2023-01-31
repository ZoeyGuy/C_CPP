#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int fun(int a[],int m,int x)
{
	int i=0,k=0,len=0;
	while(a[i++]!='\0') len++;
	if(len==1) return a[0];
	else
	{
		int j=(m+x-1)%len;
		for(i=0;i<len;i++)
			if(i!=j)
			{
				a[k]=a[i];k++;
			}
		a[k]='\0';
		return fun(a,m,j);
	}
}
int main()
{
	int n,m,a[60],i;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++) a[i]=i+1;
	a[i]='\0';
	int final=fun(a,m,0);
	printf("The left child is NO %d.\n",final);
	return 0;
}
