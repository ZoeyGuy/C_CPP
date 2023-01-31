/*总思路：辗转相除法*/ 


/*一、非递归算法*/ 

//#include"stdio.h" 
//int GCD( int a ,int b )
//{
//	int n;
//	if( a==0||b==0 ) return 0;  //考虑有一个数为0的情况 
//    else 
//	{
//		n=a%b;
//	    while( n!= 0 )     //即： while(n)
//	    {
//	        a = b;
//	    	b = n;
//	        n = a % b;
//	    }
//	    return b;   //注意这里返回的是b 不是n
//	}    
//}
//int LCM( int a,int b )
//{
//	int tmp,tmp2;
//	if(a==0||b==0) return 0;
//	else 
//	{
//		tmp=GCD(a,b);
//		tmp2=a*b/tmp;
//		return tmp2;
//	}
//}
//int main()
//{
//	int x,y;
//	scanf("%d,%d",&x,&y);  //注意题目输入输出的格式！！！ 
//	printf("最大公约数：%d\n最小公倍数：%d\n",GCD(x,y),LCM(x,y));
//	return 0;
//}


/*二、递归算法*/

#include<stdio.h>
int GCD( int a,int b )
{
	if( a==0||b==0 ) return 0; 
	else 
	{
		if(a<b) 
		{
			if(b%a==0) return a;
			else return GCD( a,b%a );  //注意这里要用return，因为得到的是一个值 
		}
		else if(a==b) return a;
		else
		{
			if(a%b==0) return b;
			else return GCD( b,a%b );
		}
	}
} 
int LCM(int a, int b)
{
	int tmp,tmp2;
	if(a==0||b==0) return 0;
	else
	{
		tmp=GCD(a,b);
		tmp2=a*b/tmp;
		return tmp2;
	}
}
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	printf("最大公约数：%d\n最小公倍数：%d\n",GCD(x,y),LCM(x,y));
	return 0;
}
