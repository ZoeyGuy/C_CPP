//#include "stdio.h"
//#define MAX 100
//void combine(int a[], int n, int m, int b[], int M);
//
//int main(void)
//{
//	int i;
//	int a[MAX], b[MAX];
//
//	for (i = 1; i < 100; i++)
//		a[i - 1] = i;
//
//	combine(a, 5, 4, b, 4);
//}
// 
//void combine(int a[], int n, int m, int b[], int M)
//{ 
//    int i, j;
//    for (i=n;i>=m;i--)
//    {
//        b[m-1] = i-1;
//        if (m>1)  
//			combine(a, i-1, m-1, b, M);
//        else
//        {
//            for (j=M-1; j>=0; j--)
//                printf("%d ", a[b[j]]);
//            printf("\n"); 
//        }
//    }
//}


#include<stdio.h>
#include<math.h>
int sum[1000000]={0};
int k=0;    //放外面,防止被重复清0 
void combine(int a[], int n, int m, int b[], int M) //求组合情况 
{ 
    int i, j;
    for (i=n;i>=m;i--)
    {
        b[m-1] = i-1;
        if (m>1)  
			combine(a, i-1, m-1, b, M);
        else
        {
            for (j=M-1; j>=0; j--) 
			sum[k]+=a[b[j]];
            k++;
        }
    }
}
int decide(int n)  //判断一个数是否为质数 
{
	int n1=sqrt(n);
	int flag=0;
	for(int i=n1;i>=2;i--) 
	{ 
		if(n%i==0) 
		{ 
			flag=1;
			break;
		} 
	} 
	return flag;
}
int main()
{
	int n,k,x[20],b[20],flag=0;
	scanf("%d%d",&n,&k);
	int K=k;
	for(int i=0;i<n;i++) 
	{ 
		scanf("%d",&x[i]);
	} 
	combine(x,n,k,b,K);
	for(int i=0;sum[i]!=0;i++) 
	{ 
		if(decide(sum[i])==0) 
		flag++;
	} 
	printf("%d",flag);
	return 0;
}
