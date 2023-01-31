#include<stdio.h>
int main()
{
	int a[10]={0},i=0,j=0,temp;
	for(i=0;i<9;i++)
	{
		if(i==8) scanf("%d",&a[i]);//scanf不能识别回车，但回车能终结scanf 
		else scanf("%d,",&a[i]);
		//或者： scanf("%d,",&a[i]);
	}
	scanf("%d",&a[9]);
	for(i=0;i<9;i++)
	{
		for(j=i+1;j<10;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
		}
	}
	for(i=0;i<10;i++)
	{
		printf("%d",a[i]);
		if(i<9) printf(",");
	}
	return 0;
}
