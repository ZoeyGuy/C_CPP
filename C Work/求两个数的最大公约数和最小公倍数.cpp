/*��˼·��շת�����*/ 


/*һ���ǵݹ��㷨*/ 

//#include"stdio.h" 
//int GCD( int a ,int b )
//{
//	int n;
//	if( a==0||b==0 ) return 0;  //������һ����Ϊ0����� 
//    else 
//	{
//		n=a%b;
//	    while( n!= 0 )     //���� while(n)
//	    {
//	        a = b;
//	    	b = n;
//	        n = a % b;
//	    }
//	    return b;   //ע�����ﷵ�ص���b ����n
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
//	scanf("%d,%d",&x,&y);  //ע����Ŀ��������ĸ�ʽ������ 
//	printf("���Լ����%d\n��С��������%d\n",GCD(x,y),LCM(x,y));
//	return 0;
//}


/*�����ݹ��㷨*/

#include<stdio.h>
int GCD( int a,int b )
{
	if( a==0||b==0 ) return 0; 
	else 
	{
		if(a<b) 
		{
			if(b%a==0) return a;
			else return GCD( a,b%a );  //ע������Ҫ��return����Ϊ�õ�����һ��ֵ 
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
	printf("���Լ����%d\n��С��������%d\n",GCD(x,y),LCM(x,y));
	return 0;
}
