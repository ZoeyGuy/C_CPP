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
	if(s[0]!='n') printf("%c",s[0]);//��λ��n������ 
	for(int i=1;i<len-1;i++)
	{
		if(s[i]!='n') printf("%c",s[i]);
		else
		{
			printf("\n");
			while(s[i+1]=='n') i++;//�������� n ����� 
		}
	}
	if(s[len-1]=='n') printf("\n");//����ǲ���n����һ���� 
	else printf("%c\n",s[len-1]);
	return 0;
} 
