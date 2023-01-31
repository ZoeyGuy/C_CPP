#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>

int main()
{
	char code_0[101],code_1[101],primer[101];
	int reflect[93]={0};//自变量为原信息 ，函数值为加密信息
	gets(code_0);
	gets(primer);
	gets(code_1);
	int flag=0; 
	for(int i=0;code_0[i]>='A'&&code_0[i]<='Z';i++)
	{
		if(reflect[primer[i]]>0&&reflect[primer[i]]!=code_0[i]) 
		{
			printf("Failed");
			return 0;
		}
		else if(reflect[primer[i]]==0)
		{
			reflect[primer[i]]=code_0[i];
			flag++;
		}
	}
	if(flag<26) 
	{
		printf("Failed");
		return 0;
	}
	for(int i=0;code_1[i]!='\0';i++)
	{
		for(int j='A';j<='Z';j++)
		{
			if(code_1[i]==reflect[j]) printf("%c",j);
		}
	}
	return 0;
}
