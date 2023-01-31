/*总思路:f(10)=1+f(5)+f(4)+f(3)+f(2)+f(1)*/
/*f(n)=1+f(n/2)+f(n/2-1)+....+f(2)+f(1)*/ 
/*递归算法*/
//#include<stdio.h>
//int fun(int n)
//{
//	int flag=0;
//	if(n==1) flag++;
//	else
//	{
//		flag++; 
//		for(int i=1;i<=n/2;i++)
//		{
//			flag+=fun(i);
//		}
//	}
//	return flag;//没有加上原来的n/2个,但发现恰好是原来的两倍 
//}
//
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	int final=fun(n);
//	printf("%d",final);
//	return 0;
//}

/*非递归算法*/
#include<stdio.h>
int main()
{
	int n,tmp,sum=0;
	scanf("%d",&n);
	if(n==1)                   //考虑两种特殊情况 
	{
		printf("1");return 0;
	}
	else if(n==2||n==3)
	{
		printf("2");return 0;
	}
	int num[100000]={0};
	num[1]=1;
	for(int i=2;i<=n/2;i++)
	{
		tmp=i/2;
		for(int j=tmp;j>=1;j--)
		{
			num[i]+=num[j]; 
		}
		num[i]++;
		sum+=num[i];
	}
	sum+=(num[1]+1);
	printf("%d",sum);
	return 0;
} 
