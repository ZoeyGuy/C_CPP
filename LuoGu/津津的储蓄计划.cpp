#include"stdio.h"
int main()
{
	int a[12];
	int i,j,s=0,r=0,d=0,c=0,p=0,q=0;
	for(i=0;i<12;i++) scanf("%d",&a[i]);
	for(j=0;j<12;j++)
	{
		s+=(300-a[j]);  //sΪԤ��������Ǯ 
		r=s%100;   //rΪ������֮��ʣ���Ǯ 
		d=r+300;    //dΪ�ڶ��������Ǯ 
		if(d<a[j+1]) {printf("-%d",j+2);goto end;}
		p=s-r;  //pΪÿ����Ǯ 
		c+=p;  //cΪ�ܹ������Ǯ 
		s-=p;
	}
	q=(int)(r+1.2*c);
	printf("%d",q);
	end:return 0;
}
