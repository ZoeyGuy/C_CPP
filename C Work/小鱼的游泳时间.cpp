#include<stdio.h>

int main()
{	int a,b,c,d,e,f,s;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	s=60*(c-a)+d-b,e=s/60,f=s-60*e;
	printf("%d %d",e,f);
 } 
