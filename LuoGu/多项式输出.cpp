#include<stdio.h>
#include<math.h>
#define N 10000

int main()
{
	int n,i=0,j=0,a[N];
	printf("中文测试");
	scanf("%d",&n);          //输入 
	for(i=0;i<n+1;i++) scanf("%d",&a[i]);
	for(i=0;i<n+1;i++)
	{
		if(a[i]==0) continue;    //对a[i]的值作为第一标准进行讨论 
		if(i==n)    //例外情况 
		{
			if(a[i]>0) printf("+%d",a[i]);
			else printf("%d",a[i]);
		}
		else if(abs(a[i])==1)
		{
			if(i>0)   //以i的值作为第二标准讨论----第一个和之后不太一样 
			{
				if(i==n-1)  //倒数第二个指数为1，需要进行讨论 
				{
					if(a[i]>0) printf("+x");
					else printf("-x");
				}
				else
				{
					if(a[i]>0) printf("+x^%d",n-i);
					else printf("-x^%d",n-i);
				}
			}
			else
			{
				if(a[i]>0) printf("x^%d",n-i);
				else printf("-x^%d",n-i);
			}
		}
		else 
		{
			if(i>0) 
			{
				if(i==n-1)
				{
					if(a[i]>0) printf("+%dx",a[i]);
					else printf("%dx",a[i]);
				}
				else
				{
					if(a[i]>0) printf("+%dx^%d",a[i],n-i);
					else printf("%dx^%d",a[i],n-i);
				}
			}
			else
			{
				printf("%dx^%d",a[i],n-i);
			}
		}
	}
	return 0;
}

/*Summary：多项式只有两个数字：系数和指数。这两个数字对0和1都要进行讨论！！！*/ 
