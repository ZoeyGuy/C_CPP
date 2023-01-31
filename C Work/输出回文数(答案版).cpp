#include <stdio.h> 
long reverse(long number)   //记住这种将输入数字颠倒的函数定义 
{
	long tmp=0;
	while(number!=0)
	{
		tmp=(tmp*10 + number%10);
		number=number/10;
	}
	if(number<0) return (-tmp);
	else return tmp;
}

int main()
{
	int n,i,s,S;
	scanf("%d",&n);
	for(i=1;i<n;i++) 
	{
		s=i*i;
		S=reverse(s);
		if(S==s) printf("%d\n",i);
	}
	return 0;
}
