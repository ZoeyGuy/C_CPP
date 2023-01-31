#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>

int main()
{
	int T;
	int m1,d1,m2,d2,x;
	int a[25]={0,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
	int b[25]={0,31,29,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};
	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d%d",&m1,&d1,&m2,&d2,&x);
		if(m1>=m2) m2+=12;
		int sum1=0;
		sum1+=a[m1]-d1;
		sum1+=d2;
		for(int i=m1+1;i<m2;i++)
		{
			sum1+=a[i];
		}
		
		int sum2=0;
		sum2+=b[m1]-d1;
		sum2+=d2;
		for(int i=m1+1;i<m2;i++)
		{
			sum2+=b[i];
		}
		
		if(sum1==x&&sum2!=x) {
			if(m1>m2) printf("R");
			else printf("P");
		}
		else if(sum1==x&&sum2==x) printf("?");
		else if(sum1!=x&&sum2==x) 
		{
			if(m1>m2) printf("P");
			else printf("R");
		}
		
		if(T>0) printf("\n");
	}
	return 0;
}

//考虑跨年份怎么办 
