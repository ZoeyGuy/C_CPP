#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>
int decide(long long m)
{
	int k=sqrt( (double)m );
	int flag=0;
	int i=0; 
	for(i=2;i<=k;i++)
	{
		if(m%i==0)
		{
			break;
		}
	}
	if(i>k) flag=1;
	else flag=0;
	return flag;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long a,b;
		scanf("%lld %lld",&a,&b);
		if(a==b&&a==1) 
			printf("NO");
		else if( (a==1&&decide(b)==1) || (b==1&&decide(a)==1) )
			printf("YES");
		else
			printf("NO");
		
		if(T>0) printf("\n");
	}
}
