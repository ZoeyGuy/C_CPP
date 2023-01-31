#include<stdio.h>
#include<string.h>
#define N 80
int main()
{
	int i=0,j=0,k=0,len_s=0,len_t=0,flag=0;
	char s[N],t[N],p[N]={'\0'};
	gets(s);
	gets(t);
	len_s=strlen(s);
	len_t=strlen(t);
	if(len_t==0) printf("%s",s);//考虑到第二个字符串为空串，scanf识别不了 
	else
	{
		for(i=0;i<len_s;i++) 
		{
			flag=0;
			for(j=0;j<len_t;j++) 
			{
				if(s[i]==t[j]) 
				{
					flag++;
				}
			}
			if(flag==0) 
			{
				p[k]=s[i];
				k++;
			}
		} 
		for(i=0;i<k;i++)  printf("%c",p[i]);
	}
	printf("\n");
	return 0;
}
