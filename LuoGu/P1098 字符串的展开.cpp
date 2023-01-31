#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>

void Print_Char(char first,char last,int p1,int p2,int p3)
{
	int dec=last-first;
	if(dec<=0) printf("-");
	else if(dec==1) return;
	else
	{
		if(p1==3) 
		{
			for(int i=0;i<dec-1;i++) //×¢ÒâÊýÁ¿£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡ 
			{
				for(int num=0;num<p2;num++)
				{
					printf("*");
				}
			}
		}
		else if(p1==2&&first>='a')
		{
			if(p3==2)
				for(int i=last-1;i>first;i--)
				{
					for(int num=0;num<p2;num++)
					{
						printf("%c",i+'A'-'a');
					}
				}
			else
				for(int i=first+1;i<last;i++)
				{
					for(int num=0;num<p2;num++)
					{
						printf("%c",i+'A'-'a');
					}
				}
		}
		else
		{
			if(p3==2)
				for(int i=last-1;i>first;i--) 
				{
					for(int num=0;num<p2;num++)
					{
						printf("%c",i);
					}
				}
			else
				for(int i=first+1;i<last;i++) 
				{
					for(int num=0;num<p2;num++)
					{
						printf("%c",i);
					}
				}
		}
		
	}
}

int main()
{
	int p1,p2,p3;
	scanf("%d%d%d",&p1,&p2,&p3);
	char str[101];
	scanf("%s",str);
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]=='-')
		{
			if(i==0||str[i+1]=='\0') printf("-");
			else if((str[i-1]<='z'&&str[i-1]>='a' && str[i+1]<='z'&&str[i+1]>='a')||(str[i-1]<='9'&&str[i-1]>='0'&&str[i+1]<='9'&&str[i+1]>='0'))
				Print_Char(str[i-1],str[i+1],p1,p2,p3);
			else printf("-");
		}
		else printf("%c",str[i]);
	}
	return 0;
}
