/*爬楼梯问题,一次可以上1阶或2阶*/ 

#include<stdio.h>

long long x[10010],y[10010];

long long Mesch(int i) //Mesch 为 Memory search 记忆化搜索 
{

	int j;

	if(i==1) return 1;

	if(i==2) return 2;

	if(y[i]>0) return y[i]; //记忆化搜索 --------如果由数据直接返回 

	y[i]=Mesch(i-1)+Mesch(i-2);

	return y[i]; 

}

int main()

{

	int n;

	scanf("%d",&n);

	printf("%I64d",Mesch(n));

}

