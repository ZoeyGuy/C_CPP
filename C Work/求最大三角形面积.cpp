/*组合函数版*/
 
#include<stdio.h>
#include<math.h>
#include<limits.h>

int all[INT_MAX][3][2];//定义几个全局变量 
int k1=0,k2=0;    //放外面,防止被重复清0 
void combine(int a[][2], int n, int m, int b[], int M) //求组合情况 
{        //C (n,m)  n>m  M==m  b[]用来存放各种情况的序号 
    int i, j;
    for (i=n;i>=m;i--)
    {
        b[m-1] = i-1;
        if (m>1)  
			combine(a, i-1, m-1, b, M);
        else
        {
        	k2=0;
            for (j=M-1; j>=0; j--)
			{
				all[k1][k2][0]=a[b[j]][0];
				all[k1][k2][1]=a[b[j]][1];
				k2++;
			}
            k1++;
        }
    }
}

float sum(int a[][2]) //求三角形面积的坐标公式 
{
	int x,y;
	int m,n;
	x=a[1][0]-a[0][0];
	y=a[1][1]-a[0][1];
	m=a[2][0]-a[0][0];
	n=a[2][1]-a[0][1];
	float s=0.5*fabs(x*n-y*m);
	return s;
}

int main()
{
	int n,N,a[max][2],b[max];
	float S,s;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&N);
		for(int j=0;j<N;j++) 
			scanf("%d%d",&a[j][0],&a[j][1]);
		if(N==3)
		{
			S=sum(a);
		}
		else
		{
			S=0;
			combine(a,N,3,b,3);
			for(int l=0;l<k1;l++)  //放入一个数组，再进行大小比较 
			{
				s=sum(all[l]);
			}
			S=s[0];
			for(int l=1;l<k1;l++)
			{
				if(s[l]>S) S=s[l];
			}
		}
		printf("%.1f\n",S);
	}
	return 0;
}

/*以上这种方法存在一个问题，就是只适用于数值比较小的情况-------组合数
是真的大，100以上的最大组合数要远超int范围*/ 

/*暴力穷举版*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100 
float sum(int a[],int b[],int c[]) //求三角形的面积-----坐标公式 
{
	int x,y,m,n;
	x=b[0]-a[0];
	y=b[1]-a[1];
	m=c[0]-a[0];
	n=c[1]-a[1];
	float s=0.5*abs(x*n-y*m);
	return s;
}
int main()
{
	int a[MAX][2]={0};
	int T=0,n=0;
	float s=0,S=0;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%d",&n);
		for(int j=0;j<n;j++) scanf("%d%d",&a[j][0],&a[j][1]);
		if(n==3)
		{
			S=sum(a[0],a[1],a[2]);
		}
		else
		{
			S=0;   //此处一定要初始化，因为有好几组数据 
			for(int k1=0;k1<n;k1++)
			{
				for(int k2=0;k2<n;k2++)
				{
					for(int k3=0;k3<n;k3++)
					{
						if(k1!=k2&&k1!=k3&&k2!=k3) 
						{
							s=sum(a[k1],a[k2],a[k3]);
							if(s>S) S=s;    /*不要想着放入一个数组，
							                因为题目只要求最大值即可*/ 
						}
					}
				}
			}
		}
		printf("%.1f\n",S);
	}
	return 0;
}
