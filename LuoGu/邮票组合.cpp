#include"stdio.h"
#define N 1000
int main()
{
	int i,j=0,t,k,k1=0,k2=0,k3=0,k4=0,a[4],s[N];
	for(i=0;i<4;i++) scanf("%d",&a[i]);
	for(k1=0;k1<=5;k1++)        //对四种面值邮票张数进行讨论 
		for(k2=0;k2<=5;k2++)
			for(k3=0;k3<=5;k3++)
				for(k4=0;k4<=5;k4++) 
					if(k1+k2+k3+k4<=5)  
					{
						s[j]=a[0]*k4+a[1]*k3+a[2]*k2+a[3]*k1;
						j++;
					}
	for(i=0;i<=j;i++) 
		for(k=0;k<=j;k++)
			if(s[k]>s[i]) 
			{
				t=s[i];
				s[i]=s[k];
				s[k]=t;
			} 
	for(i=0;i<=j-1;i++)
	{
		if(s[i+1]-s[i]>1) break;
	}
	printf("The max is %d.",s[i]);
	return 0;
}
