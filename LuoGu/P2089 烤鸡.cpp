/*此题没有方法，暴力解决*/ 
#include<stdio.h>
int main()
{
	int n;
	int a[50000][10];
	scanf("%d",&n);
	if(n>30||n<10) 
	{
		printf("0");
		return 0;
	}
	else
	{
		int d=0;
		int k[10]; 
		for(k[0]=1; k[0]<=3; k[0]++)
			for(k[1]=1; k[1]<=3; k[1]++)
				for(k[2]=1; k[2]<=3; k[2]++)
					for(k[3]=1; k[3]<=3; k[3]++)
						for(k[4]=1; k[4]<=3; k[4]++)
							for(k[5]=1; k[5]<=3; k[5]++)
								for(k[6]=1; k[6]<=3; k[6]++)
									for(k[7]=1; k[7]<=3; k[7]++)
										for(k[8]=1; k[8]<=3; k[8]++)
											for(k[9]=1; k[9]<=3; k[9]++)
											{
												if(k[0]+k[1]+k[2]+k[3]+k[4]+k[5]+k[6]+k[7]+k[8]+k[9]==n)
												{
													for(int i=0;i<10;i++) a[d][i]=k[i];
													d++;
												}
											}
	printf("%d\n",d);
	for(int i=0;i<d;i++) 
		printf("%d %d %d %d %d %d %d %d %d %d\n",a[i][0],a[i][1],a[i][2],a[i][3],a[i][4],a[i][5],a[i][6],a[i][7],a[i][8],a[i][9]);
	}
	return 0;
}
