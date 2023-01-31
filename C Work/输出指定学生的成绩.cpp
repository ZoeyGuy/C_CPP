#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>
int main()
{
	int grade[3][4];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
			scanf("%d",&grade[i][j]);
	}
	int n=0;
	scanf("%d",&n);
	double sum=0.0;
	for(int j=0;j<4;j++)
	{
		printf("%d",grade[n-1][j]);
		if(j<3) printf(" ");
		sum+=grade[n-1][j]*1.0;
	}
	sum=sum/4;
	int tmp=(int)sum;
	if(sum==tmp) printf("\n%d\n",tmp);
	else printf("\n%.2lf\n",sum); 
	return 0;
}
