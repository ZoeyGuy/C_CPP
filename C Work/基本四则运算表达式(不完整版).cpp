#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
	char s[20]="0";
	scanf("%s",s);//�����ַ������ʽ 
	int lenth=strlen(s);
	int a[2]={0};//�������������������� 
	int k=0;
	int n=0;
	char c='\0';//��¼����� 
	for(int i=lenth-1;i>=0;i--)//���������ְ����� ,a[0]�Ƿ�ĸ(�ڶ�����);a[1]�Ƿ���(��һ����). 
	{ 
		if(s[i]>='0')
		{
			a[k]+=(s[i]-'0')*pow(10,n);
			n++;
		}
		else
		{
			c=s[i];
			k++;n=0;
		}
	}
	int fz=a[1],fm=a[0],n1=fz%fm;
	switch(c)
	{
		case '+':printf("%d",a[0]+a[1]);break;
		case '-':printf("%d",a[1]-a[0]);break;
		case '*':printf("%d",a[0]*a[1]);break;
		case '/':if(fz==0) printf("0");//շת����� 
			     else
				 {
				 	while(n1!=0)
					{
						fz=fm;
						fm=n1;
						n1=fz%fm;
					}
					a[1]=a[1]/fm;   a[0]=a[0]/fm;
					if(a[0]==1) printf("%d",a[1]);
					else if(a[0]<0) printf("%d/%d",-a[1],-a[0]);
					else printf("%d/%d",a[1],a[0]);
				 }
				 break;
	}
	return 0;
} 

/*С���ӣ����븴����ѽ�������������ֺ�һ���ַ�*/ 

/*���ң���������㸺���ۣ���������������*/ 
