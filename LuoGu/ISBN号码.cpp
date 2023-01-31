#include<stdio.h>
int main()
{
	char s[13],w[9];
	int a[9],sum=0,i=0,j=0,tmp;
	scanf("%s",s);
	for(i=0;i<9;i++) a[i]=i+1;
	for(i=0,j=0;i<12;i++)
	{
		if(i+1!=2&&i+1!=6&&i+1!=12)
		{
			w[j]=s[i];
			j++;
		}
	}
	for(i=0;i<9;i++)
	{
		sum+=a[i]*(w[i]-48);
	}
	tmp=sum%11;
	if(tmp==10)
	{
		if(s[12]=='X') printf("Right");
		else
		{
			s[12]='X';
			for(i=0;i<13;i++) printf("%c",s[i]);//还是用字符输出靠谱点 
		}
	}
	else
	{ 
		if(tmp==s[12]-48) printf("Right");
		else 
		{
			s[12]=sum%11+48;
			for(i=0;i<13;i++) printf("%c",s[i]);
		}
	}
	return 0; 
}
