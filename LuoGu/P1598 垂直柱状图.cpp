#include<stdio.h>
#include<string.h>
#define N 100
int main()
{
	char s[4][N];
	int i=0,j=0,len,a[26]={0},ASCII;
	for(i=0;i<4;i++) gets(s[i]);
	for(i=0;i<4;i++)
	{
		len=strlen(s[i]);
		for(j=0;j<len;j++)
		{
			ASCII=s[i][j]-65;
			a[ASCII]++;
		}
	}
	int max=a[0];
	for(i=0;i<26;i++)
	{
		if(a[i]>max) max=a[i];
	}
	//int row=max+1;
	for(i=max;i>0;i--)
	{
		for(j=0;j<26;j++)
		{
			if(a[j]>=i) printf("*");
			else printf(" ");
			printf(" ");
		}
		printf("\n");
	} 
	for(i=0;i<26;i++) printf("%c ",i+65);
	printf("\n");
	return 0;
} 
