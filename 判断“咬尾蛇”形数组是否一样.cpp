#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>
int main()
{
	char s1[1000],s2[1000];
	gets(s1);
	gets(s2);
	int lenth=strlen(s1);
	
	if(strcmp(s1,s2)==0)
	{
		printf("YES");
		return 0;
	}
	else
	{
		int start=0;
		for(int i=0;i<lenth;i++)//找比较起点 
		{
			if(s1[i]==s2[0]&&s1[(i+1)%lenth]==s2[1]&&s1[(i-1)%lenth]==s2[lenth-1]) //确保左右 
			{
				start=i;
				break;
			}
		}
		int flag=0;
		for(int i=0;i<lenth;i++)
		{
			if( s2[i]!=s1[(start+i)%lenth] )
			{
				flag=1;
				break;
			}
		}
		if(flag==0) printf("YES");
		else printf("NO");
		return 0;
	}
}
