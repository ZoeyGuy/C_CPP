/*�ǵݹ��㷨*/

#include <stdio.h>
#include <string.h>
#define MAXLEN 60
char result[MAXLEN]={"\0"};

void add(char a1[],char a2[]) 
{
//	strcpy(result,"\0");   //�˴����Բ��ó�ʼ��,��Ϊ�ַ������������һ���ս�'\0' 
	int v1[MAXLEN]={0};   //�۳�ʼ������Ҫ��!!!! 
	int v2[MAXLEN]={0};
	int v3[MAXLEN]={0};
	int i,L,flag;

    L=strlen(a1);
    for (i=0;i<L;i++) v1[i]=a1[L-1-i]-'0';

    L=strlen(a2);
    for (i=0;i<L;i++) v2[i]=a2[L-1-i]-'0';

    for (i=0;i<MAXLEN;i++) v3[i]=v1[i]+v2[i];

    for (i=0;i<MAXLEN;i++)
	{
        if (v3[i]>=10) 
		{
            v3[i+1]+=v3[i]/10;
            v3[i]=v3[i]%10;
        }
    }
    
    int k=0;
    flag=0;
    for(i=MAXLEN-1;i>=0;i--)
    {
    	if (flag==0)
    	{
    		if (v3[i]!=0)
	    	{
	    		result[k]=v3[i]+'0';
	    		k++;
	    		flag=1;
			}
		}
		else
		{
			result[k]=v3[i]+'0';
			k++;
		}
	}
	result[k]='\0';
	if(flag==0) strcpy(result,"\0");
}
/*�˺�����ɧ�������ڱ������Ƕ������ַ���������в���,
��ʵ�����൱�ڸ���һ���ַ�����ֵ -----������Ҫȫ�ֱ���!!!*/ 

int main()
{
	int x,y;
	char fib[500][30]={"\0"};
	scanf("%d%d",&x,&y);
	strcpy(fib[x+1],"1");       //��y��ֵ�������� 
	strcpy(fib[x+2],"2");
	if(y>x+2) 
	{
		for(int i=x+3;i<=y;i++)
		{
			add( fib[i-1], fib[i-2] );
			strcpy(fib[i],result);
		}
	}
	printf("%s\n",fib[y]);
	return 0;
}
