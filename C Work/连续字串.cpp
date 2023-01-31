#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>
int main()
{
	char s[100];
	scanf("%s",s);
	int len=strlen(s);
	int flag=0;
	for(int i=0;i<len-1;)
	{
		if(s[i+1]==s[i]+1) 
		{
			printf("%c",s[i]);
			while(s[i+1]-s[i]==1) 
			{
				printf("%c",s[i+1]);
				flag++;
				i++;
			}
			if(flag>0) 
			{
				printf("\n");
				flag=0;
			}
		}
		else i++;
	}
	return 0;
}
