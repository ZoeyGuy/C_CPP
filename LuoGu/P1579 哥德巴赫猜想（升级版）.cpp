#include<stdio.h>
#include<math.h>

int decide(int n)  //判断一个数是否为质数,是则返回0；否则返回1。 
{
	int n1=sqrt(n);
	int flag=0;
	for(int i=n1;i>=2;i--) 
	{ 
		if(n%i==0) 
		{ 
			flag=1;
			break;
		} 
	} 
	return flag;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=2;i<n;i++)
	{
		for(int j=2;j<n;j++) //少一重循环，提速不少 
		{                                        //n-i-j>1是排除出现0和1的情况 
			if(decide(i)==0&&decide(j)==0&&decide(n-i-j)==0&&n-i-j>1) 
			{
				printf("%d %d %d",i,j,n-i-j);
				return 0;
			}
		}
	}
	return 0;
}
