#include<stdio.h>
#include<math.h>
int transform(int a)
{
	switch(a)
	{
		case 0:printf("7D");break;
		case 1:printf("50");break;
		case 2:printf("37");break;
		case 3:printf("57");break;
		case 4:printf("5A");break;
		case 5:printf("4F");break;
		case 6:printf("6F");break;
		case 7:printf("54");break;
		case 8:printf("7F");break;
		case 9:printf("5F");break;
	}
}

int main()
{
	int n,j=0;
	while(scanf("%d",&n)&&n)
	{
		for(j=0;j<5;j++)
		{
			int tmp=n/pow(10,4-j);
			n=n%(int)pow(10,4-j);
			transform(tmp); 
			if(j<4) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
