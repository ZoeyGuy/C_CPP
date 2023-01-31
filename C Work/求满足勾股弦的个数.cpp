#include"stdio.h"
#include"math.h"
int main()
{
	int a,b,c,N,flag=0;
	scanf("%d",&N);
	for(a=1;a<=N;a++)//三个循环，讨论三个数！ 
		for(b=1;b<=N;b++)
			for(c=1;c<=N;c++)
				if(a*a+b*b==c*c&&a<=b) flag++;
	printf("%d",flag);
	return 0;
}
