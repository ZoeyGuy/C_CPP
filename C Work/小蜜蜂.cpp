/*非递归算法*/

#include <stdio.h>
#include <string.h>
#define MAXLEN 60
char result[MAXLEN]={"\0"};

void add(char a1[],char a2[]) 
{
//	strcpy(result,"\0");   //此处可以不用初始化,因为字符串数组后面有一个终结'\0' 
	int v1[MAXLEN]={0};   //论初始化的重要性!!!! 
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
/*此函数的骚操作在于表面上是对两个字符串数组进行操作,
但实际上相当于给另一个字符串赋值 -----所以需要全局变量!!!*/ 

int main()
{
	int x,y;
	char fib[500][30]={"\0"};
	scanf("%d%d",&x,&y);
	strcpy(fib[x+1],"1");       //对y的值进行讨论 
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
