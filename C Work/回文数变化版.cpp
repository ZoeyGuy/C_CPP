#include<stdio.h>
int num(int n) //计算一个数的位数 
{
	int i=0;
	while(n>0)
	{
		i++;
		n=n/10;
	}
	return i;
}

int decide(int n)
{
	int sum1=0,sum2=0;
	int number=num(n);
	int half;
	if(number%2==0)
	{
		half=number/2;
		for(int i=0;i<number;i++)
		{
			if(i<half)
			{
				sum1+=n%10;
				sum2+=n%10;
			}
			else sum2+=n%10;
			n=n/10;
		}
	}
	else
	{
		int tmp;
		half=number/2;
		for(int i=0;i<number;i++)
		{
			if(i<half)
			{
				sum1+=n%10;
				sum2+=n%10;
			}
			else if(i==half) tmp=n%10;
			else sum2+=n%10;
			n=n/10;
		}
	}
	int flag=0;
	if(sum1*2==sum2) flag=1;
	return flag;
}

int main()
{
	int m1,m2;
	scanf("%d%d",&m1,&m2);
	for(int i=m1;i<=m2;i++)
	{
		if(decide(i)==1) printf("%d\n",i);
	}
	return 0;
}
