#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>
int main()
{
	int M,N,K;
	int all[100000];
	scanf("%d%d%d",&M,&N,&K);
	int len=0;
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&all[len]);
			len++;
		}
	}
	int x=-1,y=-1;//x���У�y����------������ڵ�λ�� 
	int sum=0;
	while(1)
	{
		int d=0;//ǰ����������ľ��� 
		int max=0;
		for(int l=1;l<len;l++)
		{
			if(all[l]>all[max]) max=l;
		}
		if(y==-1) d=(max/N)-x;
		else d=abs(max/N-x)+abs(max-max/N*N-y);
		if(K>=d+1+max/N+1)
		{
			K-=(d+1);//�˶����ϲ�ժ��ʱ�� 
			sum+=all[max];
			all[max]=0;
			x=max/N;
			y=max-max/N*N;
		}
		else break;
	}
	printf("%d",sum);
	return 0;
}
