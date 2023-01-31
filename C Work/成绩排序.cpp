#include <stdio.h>
int main ()
{
	int grade[3][4],sum[3]={0},rank[3];//各科成绩，总成绩，排名
	int i,j,m;
	for(i=0;i<3;i++)
		for(j=0;j<4;j++)
		{
			scanf("%d",&grade[i][j]);
			sum[i]+=grade[i][j];  //一旦出现这种未赋值就拿去用的一定要初始化!!! 
		}
	for(i=0;i<3;i++)
	{
		for(m=j=0;j<3;j++)
		{
			if (sum[m]<sum[j]) m=j;
		}
		sum[m]=0;  //巧妙之处在于,取得最大值时,即将其赋为最小值 
		rank[i]=m;
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d",grade[rank[i]][j]);
			if(j<3)printf(",");
		}
		printf("\n");
	}
}
