#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX 30000
#define min(a,b)  a>b?b:a 
//#define max(a,b)  a>b?a:b

int main()
{
	int M,N,K,L,D;
	int X[MAX],Y[MAX],P[MAX],Q[MAX];//������������ 
	
	scanf("%d%d%d%d%d",&M,&N,&K,&L,&D);//M,N�ֱ��ǳ��Ϳ�K,L��ʾͨ������D��˵����ͬѧ�� 
	
	for(int i=0;i<D;i++) scanf("%d%d%d%d",&X[i],&Y[i],&P[i],&Q[i]);
	
	int row[MAX]={0},col[MAX]={0};//row[i]������ŵ�i�У�С���Ǹ��������ֵĴ��� ��col[i]���� 
	int num_row=0,num_col=0;//��ʾ˵����ͬѧռ�˶�����ͨ�� 
	
	for(int i=0;i<D;i++)
	{
		if(X[i]==P[i])
		{
			row[min(Y[i],Q[i])]++;          //row��ʾ��ֱ�еķֽ��� 
		}
		else if(Y[i]==Q[i])
		{
			col[min(X[i],P[i])]++;
		}
	}
	
	
	for(int i=1;i<M;i++)
	{
		if(col[i]==0)  col[i]=1000000;//�ҵ�û��˵��ͬѧ�ĵ� ������ֵ 
		else num_col++;//ͳ�Ƶ��� 
	}
	for(int i=1;i<N;i++)
	{
		if(row[i]==0) row[i]=1000000;
		else num_row++;
	}
	
	int row_kick=num_row-L;//��ʾҪ���߳�ȥ�ĸ���-----��Ƶ����͵ļ����� 
	int col_kick=num_col-K;
		
	//�ֱ���к��н������� -----------�˴����Կ���д��һ������ 

	if(col_kick==0)//���Ǹպù������ 
	{
		for(int i=1;i<M;i++)
		{
			if(col[i]<1000000) 
			{
				printf("%d",i);
				num_col--;
				if(num_col>0) printf(" ");
			}
		}
		printf("\n");
	}
	else
	{
		while(col_kick--)//��ʼ���� 
		{
			int min_col=1;
			for(int i=1;i<M;i++)
			{
				if(col[i]<col[min_col]) min_col=i;
			}
			col[min_col]=1000000;//�ҵ���Сֵ�������꣬����ֵ 
		}
		for(int i=1;i<M;i++)
		{
			if(col[i]<1000000) 
			{
				printf("%d",i);
				num_col--;
				if(num_col>0) printf(" ");
			}
		}
		printf("\n");
	} 
	
	if(row_kick==0) //���Ǹպù������ 
	{
		for(int i=1;i<N;i++) 
		{
			if(row[i]<1000000) 
			{
				printf("%d",i);
				num_row--;
				if(num_row>0) printf(" ");
			}
		}
	}
	else
	{
		while(row_kick--)
		{
			int min_row=1;
			for(int i=1;i<N;i++)
			{
				if(row[i]<row[min_row]) min_row=i;
			}
			row[min_row]=1000000;
		}
		for(int i=1;i<N;i++)
		{
			if(row[i]<1000000)
			{
				printf("%d",i);
				num_row--;
				if(num_row>0) printf(" ");
			}
		}
	}
	return 0;
}
