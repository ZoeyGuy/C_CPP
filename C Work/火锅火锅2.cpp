#include<stdio.h> 
main() 
{ 
	int a,i,j,k=0,l,m,max; 
	int s[9999],t[9999];
	scanf("%d",&l);
	for(m=0;m<l;m++)
	{
		max=-1000; //Ҫ������⣬ȷ����ʼ���������� 
		scanf("%d",&a); 
		for(i=0;i<a;i++) 
		{
			scanf("%d",&s[i]);
		}
		for(i=0;i<a;i++)
		{
			for(j=i;j<a;j++)
			{
				k+=s[j];
				if(max<k)
				max=k;
			}
			k=0;
		}
		k=0;t[m]=max;
	}
	for(m=0;m<l;m++)  printf("%d\n",t[m]);
	return 0;
} 
