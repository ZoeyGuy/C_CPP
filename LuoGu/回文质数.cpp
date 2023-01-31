#include<stdio.h>
#include<math.h>
#include<string.h>
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
	int a,b;
	scanf("%d%d",&a,&b);
	int a1=num(a);
	int b1=num(b);
	int  palindrome[8][10000]={{5,6,7,8,9},{11,22,33,44,55,66,77,88,99}};
	/*找出所有的回文数*/ 
	int i=0;
	for(int d1=1;d1<=9;d1+=2)
	{
		for(int d2=0;d2<=9;d2++)
		{
			palindrome[2][i]=100*d1+10*d2+d1;
			i++;
		}
	}
	for(int d1=1,i=0;d1<=9;d1+=2)
	{
		for(int d2=0;d2<=9;d2++)
		{
			palindrome[3][i]=1000*d1+100*d2+10*d2+d1;
			i++;
		}
	}
	for(int d1=1,i=0;d1<=9;d1+=2)
	{
		for(int d2=0;d2<=9;d2++)
		{
			for(int d3=0;d3<=9;d3++)
			{
				palindrome[4][i]=10000*d1+1000*d2+100*d3+10*d2+d1;
				i++;
			}
		}
	}
	for(int d1=1,i=0;d1<=9;d1+=2)
	{
		for(int d2=0;d2<=9;d2++)
		{
			for(int d3=0;d3<=9;d3++)
			{
				palindrome[5][i]=100000*d1+10000*d2+1000*d3+100*d3+10*d2+d1;
				i++;
			}
		}
	}
	for(int d1=1,i=0;d1<=9;d1+=2)
	{
		for(int d2=0;d2<=9;d2++)
		{
			for(int d3=0;d3<=9;d3++)
			{
				for(int d4=0;d4<=9;d4++)
				{
					palindrome[6][i]=1000000*d1+100000*d2+10000*d3+1000*d4+100*d3+10*d2+d1;
					i++;
				}
			}
		}
	}
	for(int d1=1,i=0;d1<=9;d1+=2)
	{
		for(int d2=0;d2<=9;d2++)
		{
			for(int d3=0;d3<=9;d3++)
			{
				for(int d4=0;d4<=9;d4++)
				{
					palindrome[7][i]=10000000*d1+1000000*d2+100000*d3+10000*d4+1000*d4+100*d3+10*d2+d1;
					i++;
				}
			}
		}
	}
	int sum[100000]={0};  //放入符合位数范围的回文数 
	int k=0;
	for(i=a1;i<=b1;i++)
	{
		for(int l=0;palindrome[i-1][l]!=0;l++)
		{
			sum[k]=palindrome[i-1][l];
			k++;
		}
	} 
	for(i=0;i<k;i++)
	{
		if(sum[i]>=a&&sum[i]<=b&&decide(sum[i])==0) printf("%d\n",sum[i]);
	}
	return 0;
}
