#include <stdio.h>
int main ()
{
	int grade[3][4],sum[3]={0},rank[3];//���Ƴɼ����ܳɼ�������
	int i,j,m;
	for(i=0;i<3;i++)
		for(j=0;j<4;j++)
		{
			scanf("%d",&grade[i][j]);
			sum[i]+=grade[i][j];  //һ����������δ��ֵ����ȥ�õ�һ��Ҫ��ʼ��!!! 
		}
	for(i=0;i<3;i++)
	{
		for(m=j=0;j<3;j++)
		{
			if (sum[m]<sum[j]) m=j;
		}
		sum[m]=0;  //����֮������,ȡ�����ֵʱ,�����丳Ϊ��Сֵ 
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
