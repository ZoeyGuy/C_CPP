#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>

#define MAX 1000000

void fun(char s[],int num)
{
	int win=0,los=0,i=-1;
	while(s[++i]!='E')
	{
		if(s[i]=='W') win++;
		else if(s[i]=='L') los++;
		if( (win>=num||los>=num) && abs(win-los)>=2 ) 
		{
			printf("%d:%d\n",win,los);
			win=0;los=0;
		}
	}
	printf("%d:%d",win,los);
}

int main()
{
	char str[MAX],tmp[30];
	scanf("%s",str);
	while(scanf("%s",tmp)!=EOF) strcat(str,tmp);
	fun(str,11);
	printf("\n\n");
	fun(str,21);
	return 0;
}
