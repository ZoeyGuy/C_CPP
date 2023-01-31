#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>
int main()
{
	char s[15]={"0"};
	gets(s);
	int lenth=strlen(s);
	int i=0;
	int j=0;
	if(lenth==1)
	{
		printf("%s",s);
		return 0;
	}
	int flag=0;
	if(s[0]=='-')
	{
		lenth--;
		for(i=0;i<lenth;i++) 
		s[i]=s[i+1];
		s[i]='\0';
		flag=1;
	}
	char t[15]={"0"};
	for(i=0;i<lenth;i++)
	{
		t[i]=s[lenth-i-1];
	}
	t[i]='\0';
	i=0;
	while(t[i]=='0') i++;
	while(t[i]!='\0')
	{
		s[j]=t[i];
		j++;i++;
	}
	s[j]='\0';
	if(flag==1) printf("-");
	printf("%s",s);
	return 0;
}
