#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{	int year,month,day,date,x;
	int a,b,c,d,e,f; 
	scanf("%d%d%d",&year,&month,&day);
	a=year-1600,b=a/4,c=a/100,d=a/400;     //求每一年元旦的星期 ，即f
	e=a+b-c+d-372;
	f=(e%7+1)%7;
	if(year%400==0||year%4==0&&year%100!=0)   //判断是否是闰年 
	{ 	
		e=e-1,f=(e%7+1)%7;
		switch(month)
		{
			case 1:date=day;break;
			case 2:date=day+31;break;
			case 3:date=day+60;break;
			case 4:date=day+91;break;
			case 5:date=day+121;break;
			case 6:date=day+152;break;
			case 7:date=day+182;break;
			case 8:date=day+213;break;
			case 9:date=day+244;break;
			case 10:date=day+274;break;
			case 11:date=day+305;break;
			case 12:date=day+335;break;
		}
    }
	else
		switch(month)
		{
			case 1:date=day;break;
			case 2:date=day+31;break;
			case 3:date=day+59;break;
			case 4:date=day+90;break;
			case 5:date=day+120;break;
			case 6:date=day+151;break;
			case 7:date=day+181;break;
			case 8:date=day+212;break;
			case 9:date=day+243;break;
			case 10:date=day+273;break;
			case 11:date=day+304;break;
			case 12:date=day+334;break;
		}
	x=(date-1)%7+f;x=x%7;
	printf("%d\n",x);
	system("pause");
	return 0;
} 
