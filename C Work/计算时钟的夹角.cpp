//��Ҫ˼·��ץס�����ʱ���׷������ ��������ѧ˼�� 
#include<stdio.h>
int main () 
{	int a,b,r;
 	float d,e,c;
	scanf("%d%d",&a,&b);
	c=(60*a+b)*5.5 ,r=(int)c,d=(r%360)+c-r,e=360-d;
	if(d<=180)
		printf("At %d:%02d the angle is %.1f degrees.\n",a,b,d);
	else
		printf("At %d:%02d the angle is %.1f degrees.\n",a,b,e);
}
