#include"stdio.h"
#include"string.h"
#define N 100 
int main() 
{ 
	int i,j,l,n,a[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2}; //�������飬���ڶ�Ӧ 
	int shu,sum,Y;      
	char s[N][20];
	scanf("%d",&n);
	for(i=0;i<n;i++)  scanf("%s",s[i]);
	for(i=0;i<n;i++)
	{
		l=strlen(s[i]);   
		if(l==18)
		{
			sum=0;
			for(j=0;j<l-1;j++)    
			{
				shu=s[i][j]-48;    //shu��ָ�����ַ���ʮ������ֵ
				sum+=shu*a[j];
			}
			Y=sum%11;  Y=(12-Y)%11;  //һ��Ҫ��������ɣ����߿��Կ�������һ���ַ�����Ӧ���� 
			if(s[i][17]>58)   shu=s[i][17]-78;//����X����� 
			else   shu=s[i][17]-48;
			if(Y==shu)   printf("Valid\n");
			else   printf("Invalid\n");
		}
		else if(l==15)
		{
			sum=0;
			if(s[i][12]=='9'&&s[i][13]=='9'&&s[i][14]>='6'&&s[i][14]<='9')
			{
				for(j=0;j<6;j++)  {printf("%c",s[i][j]);sum+=a[j]*(s[i][j]-48);}
				printf("18");  sum+=10;//������������һ��һ������ַ���������Ѷȣ��������е㸴�� 
				for(j=6;j<l;j++)  {printf("%c",s[i][j]);sum+=a[j+2]*(s[i][j]-48);}
				Y=sum%11;  Y=(12-Y)%11;  
				if(Y==10)  printf("X");
				else  printf("%d",Y);
				printf("\n");
			}
			else
			{
				for(j=0;j<6;j++)  {printf("%c",s[i][j]);sum+=a[j]*(s[i][j]-48);}
				printf("19"); sum+=11;
				for(j=6;j<l;j++)  {printf("%c",s[i][j]);sum+=a[j+2]*(s[i][j]-48);}
				Y=sum%11;  Y=(12-Y)%11; 
				if(Y==10)  printf("X");
				else  printf("%d",Y);
				printf("\n");
			}
		}
		else printf("Invalid\n"); //�Ƿ��������Ҫ�������� 
	}
	return 0;
} 
