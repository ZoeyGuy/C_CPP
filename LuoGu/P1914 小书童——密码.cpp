#include<stdio.h>
#include<string.h>
int main()
{
	int n,i=0,j=0,len,former_10[50],latter_10[50];
	char former[50],latter[50];
	scanf("%d%s",&n,former);
	len=strlen(former);
	for(i=0;i<len;i++)
	{
		former_10[i]=former[i]-'a';
		latter_10[i]=(former_10[i]+n)%26;
		latter[i]=latter_10[i]+'a';
		printf("%c",latter[i]);
	}
	return 0;
} 
