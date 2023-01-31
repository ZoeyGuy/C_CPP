#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>

#define MAX 100000
#define min(a,b) a>b?b:a

int main()
{
	int N,M,A[MAX];
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
	}
	int flag1=0;
	int temp_sum=0;
	for(int i=0;i<N;i++)
	{
		temp_sum+=A[i];
		if(temp_sum<M) continue;
		else if(temp_sum==M) 
		{
			flag1++;
			temp_sum=0;
		}
		else
		{
			flag1++;
			temp_sum=A[i];
		}
	}
	if(temp_sum<M) flag1++;//这才是关键-----讨论最后没有满的情况 
	printf("%d",flag1);
/*	int flag2=0;
	temp_sum=0;
	for(int i=N-1;i>=0;i--)
	{
		temp_sum+=A[i];
		if(temp_sum<M) continue;
		else if(temp_sum==M) 
		{
			flag2++;
			temp_sum=0;
		}
		else
		{
			flag2++;
			temp_sum=A[i];
		}
	}
	if(temp_sum<M) flag2++;
	int final=min(flag1,flag2);
	printf("%d",final);*/
	return 0;
}
