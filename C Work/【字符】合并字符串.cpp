#include<stdio.h>
#include<string.h>
#define N 100
int main()
{
	int i=0,j=0,k=0,len_s,len_t;
	char s[N]={'\0'},t[N]={'\0'},p[N]={'\0'};
	scanf("%s%s",s,t);
	len_s=strlen(s);
	len_t=strlen(t);
	while(i<len_s&&j<len_t) 
	{
		if(s[i]<t[j]) 
		{
			p[k]=s[i];
			k++;
			i++;
		}
		else 
		{
			p[k]=t[j];
			k++;
			j++;
		}
	}
	while(i<len_s)//继续输出没有输出的数 
	{
		p[k]=s[i];
		i++;k++;
	}
	while(j<len_t)//继续输出没有输出的数
	{
		p[k]=t[j];
		j++;k++;
	}
	for(j=0;j<k;j++) printf("%c",p[j]);
	printf("\n");
	return 0;
}
