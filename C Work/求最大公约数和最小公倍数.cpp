#include<stdio.h>
int fun1(int a,int b)  //求最大公约数的函数 
{
	int n;
	if(b==0||a==0) return 0;
    else
    {
    	n=a%b;
	    while(n!= 0)     //即： while(n)
	    {
	        a=b;
	    	b=n;
	        n=a%b;
	    }
	    return b;       //注意这里返回的是b 不是n
	}
}

int fun2(int a,int b)  //求最小公倍数的函数 
{
	int m,n,a1=a,b1=b;
	if(b==0||a==0) return 0;
	else
	{
		n=a%b;
	    while(n!= 0)     //即： while(n)
	    {
	        a=b;
	    	b=n;
	        n=a%b;
	    }
	    m=a1*b1/b;
	    return m;       //注意这里返回的是b 不是n
	}
} 
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	printf("最大公约数：%d\n",fun1(x,y));
	printf("最小公倍数：%d\n",fun2(x,y));
	return 0;
}
