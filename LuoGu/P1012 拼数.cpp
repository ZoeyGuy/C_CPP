#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>

void STRREV(char ss[],int len)
{
	char tt[15];
	strcpy(tt,ss);
	for(int i=0;i<len;i++)
	{
		ss[i]=tt[len-i-1];
	}
	ss[len]='\0';
}

int Str_Cmp(char s1[],char s2[])
{
	int i=0;
	int len1=strlen(s1),len2=strlen(s2);
	while(1)
	{
		if(s1[i%len1]==s2[i%len2]) i++;//类似这种循环型的数就可以采取这种措施 
		else if(s1[i%len1]>s2[i%len2]) return 1;
		else if(s1[i%len1]<s2[i%len2]) return -1;
	}
}

int compare(int n1,int n2)
{
	char s1[15],s2[15];
	int i=0;
	while(n1>0)
	{
		s1[i]=n1%10+'0';
		n1/=10;
		i++;
	}
	s1[i]='\0';
	STRREV(s1,i);
	i=0;
	while(n2>0)
	{
		s2[i]=n2%10+'0';
		n2/=10;
		i++;
	}
	s2[i]='\0';
	STRREV(s2,i);
	/*或者直接写 
	strrev(s2); 
	上面类似*/
	return Str_Cmp(s1,s2);
} 


int main()
{
	int n;
	scanf("%d",&n);
	int num[21];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(compare(num[j],num[j+1])<0)
			{
				int tmp=num[j];
				num[j]=num[j+1];
				num[j+1]=tmp;
			}
		}
	}
	for(int i=0;i<n;i++) printf("%d",num[i]);
	return 0;
}
