#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>
int cal(char s[],int i)//从i开始计算前面的数字，如-269则i从9开始，最后要得到整形数-269 
{
	int final=0;
	if(s[i]=='-') final=-1;
	else if(s[i]>'9'||s[i]<'0') final=1;//考虑系数为1的情况 
	else
	{
		for(int k=0; s[i]>='0'&&s[i]<='9'; i--,k++)
		{
			final+=(s[i]-'0')*pow(10,k);
		}
		if(s[i]=='-') final*=-1;
	}
	return final;
}

int main()
{
	char s[100];
	gets(s);
	int lenth=strlen(s);
	char value;
	int va_num=0, co_num=0;//分别放置变量前面的数字之和以及常数之和 
	int flag=1;
	for(int i=lenth-1;i>=0;i--)
	{
		if(s[i]=='=') flag=-1;
		else if(s[i]>='a'&&s[i]<='z')
		{
			value=s[i];
			va_num+=cal(s,i-1)*flag;   i--;
			while(s[i]<='9'&&s[i]>='0') i--;//移动i-----不至于重复检测数字 
			i++;//始终保持i在最后一位数字------因为for里面还有一个 i-- 
		}
		else if(s[i]<='9'&&s[i]>='0')
		{
			co_num+=cal(s,i)*flag;
			while(s[i]<='9'&&s[i]>='0') i--;//移动i-----不至于重复检测数字 
			i++;
		}
	}
	float sum;
	sum=-1.0*co_num/va_num;
	printf("%c=%.3f",value,sum);
	return 0;
} 
