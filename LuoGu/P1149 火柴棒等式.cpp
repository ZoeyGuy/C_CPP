#include<stdio.h>
int transport(int n)  //此处可以改为定义一个已知数组 
{
	int flag;
	switch(n)
	{
		case 0:case 6:case 9:flag=6;break;
		case 1:              flag=2;break;
		case 2:case 3:case 5:flag=5;break;
		case 4:              flag=4;break;
		case 7:              flag=3;break;
		case 8:              flag=7;break;
	}
	return flag;
}
int num(int n)  //判断大于10的数用多少根火柴棒 
{
	int flag=0;
	if(n<10)
	{
		flag=transport(n);
	}
	else
	{
		while(n>0)
		{
			int tmp=n%10;
			flag+=transport(tmp);
			n=n/10;
		}
	}
	return flag;
}
int main()
{
	int n;
	scanf("%d",&n);
	n=n-4;
	int flag1=0,flag2=0;
	for(int i=0;i<1111;i++)
	{
		for(int j=0;j<1111;j++)
		{
			if(num(i)+num(j)+num(i+j)==n)
			{
				flag1++;
				if(i==j) flag2++;
			}
		}
	}
	printf("%d",flag1-flag2/2);
	return 0;
} 
