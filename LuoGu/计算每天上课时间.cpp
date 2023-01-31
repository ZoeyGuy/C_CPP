#include<stdio.h>
int main()
{	int i,j,v[7],a[7][2];
	for(i=0;i<8;i++) 
	{
		for(j=0;j<3;j++) 
		{
			scanf("%d",&a[i][j]);
			v[i]=a[i][j];
		}
		if(v[i]>=8)
		{
			printf("%d",i+1);
		}
		else printf("0");
	}
	return 0;
} 
