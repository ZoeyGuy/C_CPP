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
	if(s[0]!='n') printf("%c",s[0]);//首位是n不换行 
	for(int i=1;i<len-1;i++)
	{
		if(s[i]!='n') printf("%c",s[i]);
		else
		{
			printf("\n");
			while(s[i+1]=='n') i++;//考虑连续 n 的情况 
		}
	}
	if(s[len-1]=='n') printf("\n");//最后是不是n都换一次行 
	else printf("%c\n",s[len-1]);
	return 0;
} 
