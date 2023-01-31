#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>
//求对称点的坐标 
void change(int flag,int z,float *x,float *y) //flag为标志变量，1代表纵向，0代表横向 
{
	if(flag==1)
	{
		*x=2*z-*x;
		*y=*y;
	}
	else if(flag==0)
	{
		*y=2*z-*y;
		*x=*x;
	}
}

int main()
{
	float w,l,x0,y0,x1,y1;
	scanf("%f%f%f%f%f%f",&w,&l,&x0,&y0,&x1,&y1);
	char s[1010];
	scanf("%s",s);
	for(int i=0;s[i]!='\0';i++)
	{
		switch(s[i])
		{
			case ('F'):change(0,0,&x0,&y0);break;
			case ('L'):change(1,0,&x0,&y0);break;
			case ('R'):change(1,w,&x0,&y0);break;
			case ('B'):change(0,l,&x0,&y0);break;
		}
	}
	double lenth;
	lenth=sqrt(pow(x0-x1,2)+pow(y0-y1,2));
	printf("%.4lf\n",lenth);
	return 0;
}
