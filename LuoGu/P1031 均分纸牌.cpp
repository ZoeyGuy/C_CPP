#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>

#define MAX 10000 

int main() 
{
	int n;
	scanf("%d",&n);
	int a[MAX];
	int sum=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	int ave=sum/n;
	int flag=0;
	
	if(a[0]!=ave) {a[1]+=(a[0]-ave);flag++;}
	if(a[n-1]!=ave) {a[n-2]+=(a[n-1]-ave);flag++;}
	
	for(int i=1;i<n-2;i++)
	{
		if(a[i]!=ave)
		{
			a[i+1]+=(a[i]-ave);
			flag++;
		}
	}
	
	printf("%d",flag);
	return 0;
}
