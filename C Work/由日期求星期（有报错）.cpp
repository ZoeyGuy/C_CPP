#include"stdio.h"
int main()
{	int year,month,day,date,x;
	int a,b,c,d,e,f; 
	scanf("%d%d%d",&year,&month,&day);
	if(day>31) {printf("day is error.\n");goto end;}
	a=year-1600,b=a/4,c=a/100,d=a/400;     //求每一年元旦的星期 ，即f
	e=a+b-c+d-372;
	f=(e%7+1)%7; 
	if(year%400==0||year%4==0&&year%100!=0)   //判断是否是闰年 
	{ 	
		e=e-1,f=(e%7+1)%7;
		switch(month)
		{
			case 1:date=day;break;
			case 2:date=day+31;
				    if(day>29) {printf("day is error.\n");goto end;} break;
			case 3:date=day+60;break;
			case 4:date=day+91;
					if(day>30) {printf("day is error.\n");goto end;} break;
			case 5:date=day+121;break;
			case 6:date=day+152;
					if(day>30) {printf("day is error.\n");goto end;} break;
			case 7:date=day+182;break;
			case 8:date=day+213;break;
			case 9:date=day+244;
					if(day>30)  {printf("day is error.\n");goto end;} break;
			case 10:date=day+274;break;
			case 11:date=day+305;
					if(day>30) {printf("day is error.\n");goto end;} break;
			case 12:date=day+335;break;
			default:printf("month is error.\n");goto end;
		}
    }
	else
		switch(month)
		{
			case 1:date=day;break;
			case 2:date=day+31;
					if(day>28) {printf("day is error.\n");goto end;} break;
			case 3:date=day+59;break;
			case 4:date=day+90;break;
					if(day>30) {printf("day is error.\n");goto end;} break;
			case 5:date=day+120;break;
			case 6:date=day+151;
					if(day>30) {printf("day is error.\n");goto end;} break;
			case 7:date=day+181;break;
			case 8:date=day+212;break;
			case 9:date=day+243;
					if(day>30) {printf("day is error.\n");goto end;} break;
			case 10:date=day+273;break;
			case 11:date=day+304;
					if(day>30) {printf("day is error.\n");goto end;} break;
			case 12:date=day+334;break;
			default:printf("month is error.\n");goto end;
		}
	x=(date-1)%7+f;x=x%7;
	printf("%d\n",x);
	end:return 0;	
} 
