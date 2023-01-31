#include<stdio.h>
#include<string.h>
int fun(char s[])
{
	int len=strlen(s),P=1;
	for(int i=0;i<len;i++)
	{
		P*=(s[i]-64);
	}
	P=P%47;
	return P;
}
int main()
{
	int tmp1,tmp2;
	char s1[6],s2[6];
	scanf("%s%s",s1,s2);
	tmp1=fun(s1);
	tmp2=fun(s2);
	if(tmp1==tmp2) printf("GO");
	else printf("STAY");
	return 0;
}
