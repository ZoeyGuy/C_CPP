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
	int X[MAX],Y[MAX],P[MAX],Q[MAX];//输入两个坐标 
	
	scanf("%d%d%d%d%d",&M,&N,&K,&L,&D);//M,N分别是长和宽，K,L表示通道数，D是说话的同学数 
	
	for(int i=0;i<D;i++) scanf("%d%d%d%d",&X[i],&Y[i],&P[i],&Q[i]);
	
	int row[MAX]={0},col[MAX]={0};//row[i]用来存放第i行（小的那个数）出现的次数 ；col[i]类似 
	int num_row=0,num_col=0;//表示说话的同学占了多少条通道 
	
	for(int i=0;i<D;i++)
	{
		if(X[i]==P[i])
		{
			row[min(Y[i],Q[i])]++;          //row表示垂直行的分界线 
		}
		else if(Y[i]==Q[i])
		{
			col[min(X[i],P[i])]++;
		}
	}
	
	
	for(int i=1;i<M;i++)
	{
		if(col[i]==0)  col[i]=1000000;//找到没有说话同学的道 ，赋最值 
		else num_col++;//统计道数 
	}
	for(int i=1;i<N;i++)
	{
		if(row[i]==0) row[i]=1000000;
		else num_row++;
	}
	
	int row_kick=num_row-L;//表示要被踢出去的个数-----即频次最低的几个数 
	int col_kick=num_col-K;
		
	//分别对行和列进行讨论 -----------此处可以考虑写成一个函数 

	if(col_kick==0)//考虑刚好够的情况 
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
		while(col_kick--)//开始踢数 
		{
			int min_col=1;
			for(int i=1;i<M;i++)
			{
				if(col[i]<col[min_col]) min_col=i;
			}
			col[min_col]=1000000;//找到最小值所在坐标，赋最值 
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
	
	if(row_kick==0) //考虑刚好够的情况 
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
