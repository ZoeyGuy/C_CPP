#include"stdio.h"
int main()
{	int i,s,a,b,c,d,n,n1,n2;
	while(scanf("%d%d",&n1,&n2)&&n1&&n2)//øÿ÷∆ ‰»Î0‘ÚΩÿ÷π 
	{
		if(n2<1000) printf("Error\n");
		else 
		{
			s=1;
			for(i=0;i<=(n2-n1);i++)
			{
				n=n1+i; 
				a=n%10;
				b=n/10%10;if(b==a) continue;
				c=n/100%10;if(c==a||c==a) continue;
				d=n/1000;if(d==a||d==b||d==c) continue;
				if(n%2==0&&a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d) {printf("%d  ",n);s++;}	
			}
			printf("\ncounter=%d\n",s-1);
		}
	}
	return 0;
}
