/*非递归算法*/ 
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int tmp,lenth,i;
//	char s[100],t[100]={'\0'};
//	gets(s);
//	lenth=strlen(s);
//	for(i=0;i<lenth;i++)
//	{
//		t[i]=s[lenth-1-i];
//	}
//	tmp=strcmp(s,t);
//	if(tmp==0) printf("Yes\n");
//	else printf("No\n");
//	return 0;
//}


/*递归算法*/
#include<stdio.h>
#include<string.h>
int fun(char s[],int lenth)
{
	int len=strlen(s);
	if(lenth==0||lenth==1) return 1;
	else
	{
		if(s[len-lenth]==s[lenth-1]) return fun(s,lenth-1);//注意这里最好加return 
		else return 0;
	}
} 
int main()
{
	char str[20];
	int tmp,len2;
	gets(str);
	len2=strlen(str);
	tmp=fun(str,len2);
	if(tmp==1) printf("Yes\n");
	else if(tmp==0) printf("No\n");
	return 0;
}
