#include <stdio.h>
#include <string.h>
int main () 
{
	char psw[100]=""; 
	int typ[5],n,i;
	for (scanf ("%d",&n)&&n++; n;n--) 
	{ 
		gets(psw);
		typ[0]=typ[1]=typ[2]=typ[3]=typ[4]=0;i=-1;
		while (psw[++i]!='\0') 
		{ 
			if ('0'<=psw[i]&&psw[i]<='9') {typ[1]++;continue;} 
			if ('a'<=psw[i]&&psw[i]<='z') {typ[2]++;continue;} 
			if ('A'<=psw[i]&&psw[i]<='Z') {typ[3]++;continue;} 
			typ[4]++;
		}
		typ[0]=typ[1]+typ[2]+typ[3]+typ[4];
		if (0<typ[0]&&typ[0]<6) printf ("Not Safe\n");
		else
		{
			typ[0]=(0||typ[1])+(0||typ[2])+(0||typ[3])+(0||typ[4]);
			switch (typ[0])
			{
				case 1:printf("Not Safe\n");break;
				case 2:printf("Medium Safe\n");break;
				case 3:
				case 4:printf("Safe\n");
			}
		}
	}
}
