/*��Ϻ�����*/
 
#include<stdio.h>
#include<math.h>
#include<limits.h>

int all[INT_MAX][3][2];//���弸��ȫ�ֱ��� 
int k1=0,k2=0;    //������,��ֹ���ظ���0 
void combine(int a[][2], int n, int m, int b[], int M) //�������� 
{        //C (n,m)  n>m  M==m  b[]������Ÿ����������� 
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

float sum(int a[][2]) //����������������깫ʽ 
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
			for(int l=0;l<k1;l++)  //����һ�����飬�ٽ��д�С�Ƚ� 
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

/*�������ַ�������һ�����⣬����ֻ��������ֵ�Ƚ�С�����-------�����
����Ĵ�100���ϵ���������ҪԶ��int��Χ*/ 

/*������ٰ�*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100 
float sum(int a[],int b[],int c[]) //�������ε����-----���깫ʽ 
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
			S=0;   //�˴�һ��Ҫ��ʼ������Ϊ�кü������� 
			for(int k1=0;k1<n;k1++)
			{
				for(int k2=0;k2<n;k2++)
				{
					for(int k3=0;k3<n;k3++)
					{
						if(k1!=k2&&k1!=k3&&k2!=k3) 
						{
							s=sum(a[k1],a[k2],a[k3]);
							if(s>S) S=s;    /*��Ҫ���ŷ���һ�����飬
							                ��Ϊ��ĿֻҪ�����ֵ����*/ 
						}
					}
				}
			}
		}
		printf("%.1f\n",S);
	}
	return 0;
}
