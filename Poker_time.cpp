#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>
int change(char s[])  //��һ���Ƶ������Ʊ�ţ�1~52 ,����������,����0 
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
	char s[2][10]={"0"};//����������˵��� 
	char all[2][3][4]={"0"};//������������˵��� 
	for(int i=0;i<2;i++) 
	{
		for(int m=0;m<3;m++)   strcpy(all[i][m],"0");  //��ʼ�����Է���һ 
		int k1=0,k2=0;
		gets(s[i]);
		int len=strlen(s[i]);
		for(int j=0;j<len;j++)//�������˵������Ʒŵ�һ����ά������  
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
		k1++;//��Ϊֻ�������ո񣬻�Ҫ�� 1 
		for(int j=0;j<k1-1;j++) //��ѡ������ 
			for(int k=j+1;k<k1;k++)
			{
				if(change(all[i][j])==0||change(all[i][k])==0||( change(all[i][j])==change(all[i][k])&&j!=k ) ) 
				{                                      //�ų��������------�ƷǷ�;����ͬ(һ���˵���) 
					printf("Input Error!\n");
					return 0;
				}
				else if(change(all[i][k])>change(all[i][j]))//ͨ����ӳ��ı�Ŵ�С,�����Ƶ����� 
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
	for(i=0;i<3;i++)//�Ӵ��Ƶ�С�ƱȽ������ƴ�С 
	{
		if(change(all[0][i])>change(all[1][i])) {cc='A';break;}
		else if(change(all[0][i])<change(all[1][i])) {cc='B';break;}
	}
	if(i==3) cc='X';//��������������һ���� 
	printf("Winner is %c!\n",cc);
	printf("A: %s %s %s\nB: %s %s %s\n",all[0][0],all[0][1],all[0][2],all[1][0],all[1][1],all[1][2]);
	system("PAUSE");
	return 0;
}