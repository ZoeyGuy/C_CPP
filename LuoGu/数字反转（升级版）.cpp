#include<stdio.h>
#include<string.h>
void delet(char s[]) //ɾ��һ������ǰ��� 0�ĺ��� 
{
	int len=strlen(s),i=0,j=0;
	for(i=0;i<len;i++)
	{
		if(s[i]!='0') break;
	}
	if(i==len) printf("0");  //���ǵ�ֻ��0����� 
	else for(j=i;j<len;j++) printf("%c",s[j]);
}
void delet2(char s[]) //ɾ��һ�����ֺ���� 0�ĺ��� 
{
	int len=strlen(s),i,j,k;
	char w[20];
	for(i=len-1;i>=0;i--)
	{
		if(s[i]!='0') break;
	}
	if(i==-1) printf("0");
	else
	{
		w[i+1]='\0';
		for(j=i;j>=0;j--) w[j]=s[j];
		printf("%s",w);
	}
}

int main()
{
	char s[20],y[20],z[20];
	int i=0,len,flag,pla; //pla��ָ����(С��������)����λ�� 
	scanf("%s",s);//��ֵ 
	len=strlen(s);//ȡ�� 
	
	for(i=0;i<len;i++)
	{
		if(s[i]=='.') {flag=1;pla=i;break;}//С�� 
		else if(s[i]=='/') {flag=2;pla=i;break;} //���� 
		else flag=0; //���� 
	}
	if(s[len-1]=='%') flag=3;//�ٷ��� 
	if(flag==0)
	{
		for(i=0;i<len;i++)
		{
			y[i]=s[len-i-1];
		}
		y[len]='\0';   //Ҫϰ���Եؼ���һ��'\0'����ΪҪ��strlen���� 
		delet(y);
	}
	else if(flag==1)
	{
		for(i=0;i<pla;i++)
		{
			y[i]=s[pla-1-i];
		}
		y[i]='\0';
		delet(y);
		printf(".");
		for(i=0;i<len-pla-1;i++)
		{
			z[i]=s[len-i-1];
		}
		z[i]='\0';
		delet2(z);
	}
	else if(flag==2)
	{
		for(i=0;i<pla;i++)
		{
			y[i]=s[pla-1-i];
		}
		y[i]='\0';
		delet(y);
		printf("/");
		for(i=0;i<len-pla-1;i++)
		{
			z[i]=s[len-i-1];
		}
		z[i]='\0';
		delet(z);
	}
	else if(flag==3)
	{
		for(i=0;i<len-1;i++)
		{
			y[i]=s[len-i-2];
		}
		y[i]='\0';
		delet(y);
		printf("%%");
	}
	return 0;
}
