#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
	char s[20]="0";
	scanf("%s",s);//输入字符串表达式 
	int lenth=strlen(s);
	int a[2]={0};//存放两个参与运算的数字 
	int k=0;
	int n=0;
	char c='\0';//记录运算符 
	for(int i=lenth-1;i>=0;i--)//将两个数字剥出来 ,a[0]是分母(第二个数);a[1]是分子(第一个数). 
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
		case '/':if(fz==0) printf("0");//辗转相除法 
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

/*小伙子，你想复杂了呀！就是两个数字和一个字符*/ 

/*而且，这个不能算负数哇！！！！！！！！*/ 
