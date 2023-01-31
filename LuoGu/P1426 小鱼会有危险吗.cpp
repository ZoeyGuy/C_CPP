#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>
#define Num_max 50
int main()
{
	float Sum[Num_max]={7.0};  //小鱼游的距离的前n项和
	for(int i=1;i<Num_max;i++) Sum[i]=Sum[i-1]+7.0*pow(0.98,i);
	float s,r;
	scanf("%f %f",&s,&r);
	int n0=0;
	while(Sum[n0++]<s-r);
	n0--;
	if(  0.98*(Sum[n0+1]-(s+r)) > Sum[n0]-(s-r)  ) printf("n");
	else printf("y");
	return 0;
} 
