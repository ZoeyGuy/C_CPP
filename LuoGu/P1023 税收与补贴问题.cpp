#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>

#define MAX 100000

int main()
{
	int n;
	int price[MAX],amount[MAX];
	scanf("%d",&n);
	int num;
	for(num=0;;num++)
	{
		scanf("%d%d",&price[num],&amount[num]);
		if(price[num]==-1&&amount[num]==-1) break;
	}
	int dd;//提高1块钱减少的销量 
	scanf("%d",&dd);
	for(int j=0;j<num;j++)
	{
		for(int k=j+1;k<num-1;k++)
		{
			if(price[k]<price[j])
			{
				
			}
		}
	}
} 
