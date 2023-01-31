#include"stdio.h"
int main()
{
	int x,n,n1,n2,n3,s;
	scanf("%d%d",&x,&n);
	if(x>5) 
	{
		n1=n-(8-x);
		n2=n1/7;
		n3=n1%7;
		if(n3>=5) {n2++;n3=0;}
		s=5*n2+n3;
	}
	else
	{
		if(n<=8-x)  s=6-x;
		else
		{
			n1=n-(8-x);
			n2=n1/7;
			n3=n1%7;
			if(n3>=5) {n2++;n3=0;}
			s=5*n2+n3+6-x;
		}
	}
	printf("%d",s*250);
	return 0;
}
