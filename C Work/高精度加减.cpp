#include"stdio.h"
#include"string.h"
#define N 501 //乐学上还是定义600 
void  add(char str1[],char str2[])
{
	int  l1,l2,len,i=0,j=0;
	int  a[N]={0},b[N]={0};
	l1=strlen(str1);
	l2=strlen(str2);
	if(l1>l2)  len=l1;
	else  len=l2;
	for(i=0;i<l1;i++)  a[i]=str1[l1-i-1]-'0';
	for(i=0;i<l2;i++)  b[i]=str2[l2-i-1]-'0';
	for(i=0;i<len;i++)
	{ 
		a[i] = a[i] + b[i];    //运算 
		a[i+1]+= a[i] / 10;    //如有进位，在后一位上加上 
		a[i] = a[i] % 10;      //原来那一位减掉进位了的 
	}
	if(a[len]!=0) len++;
	for(j=len-1;j>=0;j--) 	printf("%d",a[j]);
	printf("\n");
}
void   dec(char str1[],char str2[])
{
	int l1,l2,i,j,len;
	int a[N]={0},b[N]={0};
	l1=strlen(str1);l2=strlen(str2);
	if(l1>l2)  
	{ 
		len=l1;
		for(i=0;i<l1;i++)  a[i]=str1[l1-i-1]-'0';
		for(i=0;i<l2;i++)  b[i]=str2[l2-i-1]-'0';
		for(i=0;i<len;i++)
		{
			a[i]=a[i]-b[i];
			if(a[i]<0) 
			{
				a[i]=a[i]+10;
				a[i+1]--;
			}
		}
		if(a[len-1]==0)  len--;
		for(j=len-1;j>=0;j--) 	printf("%d",a[j]);
		printf("\n");
	}
	else if(l1<l2)
	{
		len=l2;
		for(i=0;i<l1;i++)  b[i]=str1[l1-i-1]-'0';
		for(i=0;i<l2;i++)  a[i]=str2[l2-i-1]-'0';
		for(i=0;i<len;i++)
		{
			a[i]=a[i]-b[i];
			if(a[i]<0) 
			{
				a[i]=a[i]+10;
				a[i+1]--;
			}
		}
		if(a[len-1]==0)  len--;
		printf("-");
		for(j=len-1;j>=0;j--) 	printf("%d",a[j]);
		printf("\n");
	}
	else
	{
		len=l1; int s=strcmp(str1,str2);
		if(s>0)
		{
			for(i=0;i<l1;i++)  a[i]=str1[l1-i-1]-'0';
			for(i=0;i<l2;i++)  b[i]=str2[l2-i-1]-'0';
			for(i=0;i<len;i++)
			{
				a[i]=a[i]-b[i];
				if(a[i]<0) 
				{
					a[i]=a[i]+10;
					a[i+1]--;
				}
			}
			if(a[len-1]==0)  len--;
			for(j=len-1;j>=0;j--) if(a[j]!=0) break;
			for(;j>=0;j--) 	printf("%d",a[j]);
			printf("\n");
		}
		else if(s<0)
		{
			for(i=0;i<l1;i++)  b[i]=str1[l1-i-1]-'0';
			for(i=0;i<l2;i++)  a[i]=str2[l2-i-1]-'0';
			for(i=0;i<len;i++)
			{
				a[i]=a[i]-b[i];
				if(a[i]<0) 
				{
					a[i]=a[i]+10;
					a[i+1]--;
				}
			}
			if(a[len-1]==0)  len--;
			for(j=len-1;j>=0;j--) if(a[j]!=0) break;
			printf("-");
			for(;j>=0;j--) 	printf("%d",a[j]);
			printf("\n");
		}
		else printf("0\n");
	}
}

int main()
{
	int n,i,j,k;
	char s[N][N],y1[N][N],y2[N][N];
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%s",s[i]);
	for(i=0;i<n;i++)
	{	
		int lenth=strlen(s[i]);
		for(j=0;1;j++)
		{
			if(s[i][j]>='0') y1[i][j]=s[i][j];
			else break;
		}  
		for(k=j+1;k<lenth;k++) 
		{
			y2[i][k-j-1]=s[i][k];
		}
		if(s[i][j]=='+')  add(y1[i],y2[i]);
		else if(s[i][j]=='-')   dec(y1[i],y2[i]);
	}
	return 0;
}
