#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>

void print_row(int side)
{
	for(int j=0;j<side;j++)
	{
		if(j==0||j==side-1) printf(" ");
		else printf("-");
	}
	printf("\n");
}

void print_left_col(int times,int side)
{
	for(int i=0;i<times;i++)
	{
		for(int j=0;j<side;j++)
		{
			if(j==0) printf("|");
			else printf(" ");
		}
		printf("\n");
	}
}

void print_right_col(int times,int side) 
{
	for(int i=0;i<times;i++)
	{
		for(int j=0;j<side;j++)
		{
			if(j==side-1) printf("|");
			else printf(" ");
		}
		printf("\n");
	}
}

void print_col(int times,int side)
{
	for(int i=0;i<times;i++)
	{
		for(int j=0;j<side;j++)
		{
			if(j==0||j==side-1) printf("|");
			else printf(" ");
		}
		printf("\n");
	}
}

void Num_Print(int num,int times)
{
	int hight=times*2+3;
	int side=times+2;
	switch(num)
	{
		case 1:
			printf("\n");
			print_right_col(times,side);
			printf("\n");
			print_right_col(times,side);
			printf("\n");
			break;
		case 2:
			print_row(side);
			print_right_col(times,side);
			print_row(side);
			print_left_col(times,side);
			print_row(side);
			break;
		case 3:
			print_row(side);
			print_right_col(times,side);
			print_row(side);
			print_right_col(times,side);
			print_row(side);
			break;
		case 4:
			printf("\n");
			print_col(times,side);
			print_row(side);
			print_right_col(times,side);
			printf("\n");
			break;
		case 5:
			print_row(side);
			print_left_col(times,side);
			print_row(side);
			print_right_col(times,side);
			print_row(side);
			break;
		case 6:
			print_row(side);
			print_left_col(times,side);
			print_row(side);
			print_col(times,side);
			print_row(side);
			break;
		case 7:
			print_row(side);
			print_right_col(times,side);
			printf("\n");
			print_right_col(times,side);
			printf("\n");
			break;
		case 8:
			print_row(side);
			print_col(times,side);
			print_row(side);
			print_col(times,side);
			print_row(side);
			break;
		case 9:
			print_row(side);
			print_col(times,side);
			print_row(side);
			print_right_col(times,side);
			print_row(side);
			break;
		case 0:
			print_row(side);
			print_col(times,side);
			printf("\n");
			print_col(times,side);
			print_row(side);
			break;
	}
}

int main()
{
	int times;
	char cc;
	scanf("%d",&times);
	getchar();
	while(1)
	{
		cc=getchar();
		if(cc=='\n') return 0;
		Num_Print(cc-'0',times);
		printf("\n");
	}
	return 0;
}




#include <cstdio>
#include <cstring> 
int k, l;
char c[256]; 
int main()
{
    scanf ("%d\n%s", &k, c);
    l=std::strlen(c); 
    //====== 数字顶部
    for (int i=0; i<l; i++){
        putchar (' ');
        //前面有一个空格
        for (int j=0; j<k; j++)
            putchar ("- -- -----"[c[i]-'0']);
        printf (l-1!=i?"  ":"\n");
        //如果最后一个数，回车，否则两个空格
    }
    //====== 数字上半
    for (int j=0; j<k; j++){
        for (int i=0; i<l; i++){
            putchar ("|   ||| ||"[c[i]-'0']);
            for (int jj=0; jj<k; jj++)
                putchar (' ');
            putchar ("|||||  |||"[c[i]-'0']);
            putchar (l-1!=i?' ':'\n');
        } 
    }
    //====== 数字中间
    //只是修改了顶部的字串
    for (int i=0; i<l; i++){
        putchar (' ');
        for (int j=0; j<k; j++)
            putchar ("  ----- --"[c[i]-'0']);
        printf (l-1!=i?"  ":"\n");
    }
    //====== 数字下半
    //修改了上半的字串
    for (int j=0; j<k; j++){
        for (int i=0; i<l; i++){
            putchar ("| |   | | "[c[i]-'0']);
            for (int jj=0; jj<k; jj++)
                putchar (' ');
            putchar ("|| |||||||"[c[i]-'0']);
            putchar (l-1!=i?' ':'\n');
        } 
    }
    //====== 数字底部，同中间
    for (int i=0; i<l; i++){
        putchar (' ');
        for (int j=0; j<k; j++)
            putchar ("- -- -- --"[c[i]-'0']);
        printf (l-1!=i?"  ":"\n");
    }
    return 0;
}
