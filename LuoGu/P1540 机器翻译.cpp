#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>

int main()
{
	int N,M;
	int a[1001]={0},b[120],i=0;
	scanf("%d %d",&M,&N);
	for(i=0;i<M;i++) b[i]=-1;//·ÀÖ¹Êý×ÖÀïÓÐ0 
	for(i=0;i<N;i++) scanf("%d",&a[i]);
	int num=0;
	int j=0;
	for(i=0;i<N;i++)
	{
		int flag=0;
		for(j=0;j<M;j++)
		{
			if(a[i]==b[j]) flag=1;
		}
		if(flag==0)
		{
			num++;
			for(j=M-1;j>=1;j--)
			{
				b[j]=b[j-1];
			}
			b[j]=a[i];
		}
	}
	printf("%d",num);
	return 0;
} 
