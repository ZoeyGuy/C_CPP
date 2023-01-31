#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>
int change(char s[])  //给一副牌的所有牌编号，1~52 ,若不在其中,返回0 
{
	if(s[0]=='H')
	{
		if(s[1]>='2'&&s[1]<='9') return s[1]-10;
		else if(s[1]=='J') return 49;
		else if(s[1]=='Q') return 50;
		else if(s[1]=='K') return 51;
		else if(s[1]=='A') return 52;
		else if(s[1]=='1'&&s[2]=='0') return 48;
		else return 0;
	}
	else if(s[0]=='S')
	{
		if(s[1]>='2'&&s[1]<='9') return s[1]-23;
		else if(s[1]=='J') return 36;
		else if(s[1]=='Q') return 37;
		else if(s[1]=='K') return 38;
		else if(s[1]=='A') return 39;
		else if(s[1]=='1'&&s[2]=='0') return 35;
		else return 0;
	}
	else if(s[0]=='D')
	{
		if(s[1]>='2'&&s[1]<='9') return s[1]-36;
		else if(s[1]=='J') return 23;
		else if(s[1]=='Q') return 24;
		else if(s[1]=='K') return 25;
		else if(s[1]=='A') return 26;
		else if(s[1]=='1'&&s[2]=='0') return 22;
		else return 0;
	}
	else if(s[0]=='C')
	{
		if(s[1]>='2'&&s[1]<='9') return s[1]-49;
		else if(s[1]=='J') return 10;
		else if(s[1]=='Q') return 11;
		else if(s[1]=='K') return 12;
		else if(s[1]=='A') return 13;
		else if(s[1]=='1'&&s[2]=='0') return 9;
		else return 0;
	}
	else return 0;
}

int main()
{
	char s[2][10]={"0"};//输入的两个人的牌 
	char all[2][3][4]={"0"};//用来存放两个人的牌 
	for(int i=0;i<2;i++) 
	{
		for(int m=0;m<3;m++)   strcpy(all[i][m],"0");  //初始化，以防万一 
		int k1=0,k2=0;
		gets(s[i]);
		int len=strlen(s[i]);
		for(int j=0;j<len;j++)//将两个人的三张牌放到一个三维数组中  
		{
			if(s[i][j]!=' ') 
			{
				all[i][k1][k2]=s[i][j];
				k2++;
			}
			else
			{
				all[i][k1][k2]='\0';
				k1++;k2=0;
			}
		}
		k1++;//因为只有两个空格，还要加 1 
		for(int j=0;j<k1-1;j++) //半选择排序 
			for(int k=j+1;k<k1;k++)
			{
				if(change(all[i][j])==0||change(all[i][k])==0||( change(all[i][j])==change(all[i][k])&&j!=k ) ) 
				{                                      //排除特殊情况------牌非法;牌相同(一个人的牌) 
					printf("Input Error!\n");
					return 0;
				}
				else if(change(all[i][k])>change(all[i][j]))//通过牌映射的编号大小,进行牌的排序 
				{
					char tmp[4]={"0"};
						strcpy(tmp,all[i][k]);
						strcpy(all[i][k],all[i][j]);
						strcpy(all[i][j],tmp);
				}
			}
	}
	char cc;
	int i;
	for(i=0;i<3;i++)//从大牌到小牌比较两人牌大小 
	{
		if(change(all[0][i])>change(all[1][i])) {cc='A';break;}
		else if(change(all[0][i])<change(all[1][i])) {cc='B';break;}
	}
	if(i==3) cc='X';//二者摸到的牌是一样的 
	printf("Winner is %c!\n",cc);
	printf("A: %s %s %s\nB: %s %s %s\n",all[0][0],all[0][1],all[0][2],all[1][0],all[1][1],all[1][2]);
	system("PAUSE");
	return 0;
}