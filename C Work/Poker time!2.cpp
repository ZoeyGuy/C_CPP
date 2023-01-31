#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<float.h>

int num_trans(char s[])  //�Ƚ��ƵĴ�С ----�ȴ�С����ɫ 
{
	int head,body;
	switch(s[0])
	{
		case 'H':head=4;break;
		case 'S':head=3;break;
		case 'D':head=2;break;
		case 'C':head=1;break;
	}
	if(s[1]>='2'&&s[1]<='9') body= s[1]-49;
	else if(s[1]=='J') body= 10;
	else if(s[1]=='Q') body= 11;
	else if(s[1]=='K') body= 12;
	else if(s[1]=='A') body= 13;
	else if(s[1]=='1'&&s[2]=='0') body= 9;
	else body= 0;
	return body*10+head;
}

int num_trans2(char s[])  //ֻ�Ƚ��ƵĴ�С�������ǻ�ɫ�� -----Ӧ�ÿ��Բ���Ҫ����Ϊ�˷������ĺ���������ʹ���� 
{
	int body; 
	if(s[1]>='2'&&s[1]<='9') body= s[1]-49;
	else if(s[1]=='J') body= 10;
	else if(s[1]=='Q') body= 11;
	else if(s[1]=='K') body= 12;
	else if(s[1]=='A') body= 13;
	else if(s[1]=='1'&&s[2]=='0') body= 9;
	else body= 0;
	return body;
}

int decide(char str[][4])  //�ж������������� 
{
	int tmp=num_trans2(str[0]);
	int flag=0,dec=0;
	if(str[0][0]==str[1][0]&&str[0][0]==str[2][0]&&str[1][0]==str[2][0]) return 50;
	else 
	{
		for(int i=1;i<3;i++)
		{
			if(num_trans2(str[i])==tmp) flag++;  //һ��С覴ã������һ�����ǳ����ӵ���һ�ţ���ô�죿 
			else dec+=abs(tmp-num_trans2(str[i]));
		}
		if(dec<=3&&dec>1) return 30;
		else if(flag==2) return 40;
		else if(flag==1) return 20;
		else return 10;
	}
}

int main()
{
	char s[2][10]={"0"};
	char all[2][3][4]={"0"};
	int mmp[2][3]={0};
	for(int i=0;i<2;i++) 
	{
		for(int m=0;m<3;m++)   strcpy(all[i][m],"0");  //��ʼ�� 
		int k1=0,k2=0;
		gets(s[i]);
		int len=strlen(s[i]);
		for(int j=0;j<len;j++)
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
		for(int j=0;j<2;j++) //ѡ������������ 
		{
			for(int k=j+1;k<3;k++)
			{
				if(num_trans(all[i][j])<5||num_trans(all[i][k])<5) 
				{                                      //�ų�������� 
					printf("Input Error!\n");
					return 0;
				}
				else if(num_trans(all[i][k])>num_trans(all[i][j]))
				{
					char tmp[4]={"0"};
						strcpy(tmp,all[i][k]);
						strcpy(all[i][k],all[i][j]);
						strcpy(all[i][j],tmp);
				}
			}
		}
		for(int j=0;j<2;j++)  //ת���ɶ�ά�������飬���ں���ıȽ� 
		{
			mmp[i][2]=num_trans(all[i][2]);
			mmp[i][j]=num_trans(all[i][j]);
			if(num_trans(all[i][j])==num_trans(all[i][j+1])) 
			{
				printf("Input Error!\n");
				return 0;
			}
		}
	}
	for(int i=0;i<3;i++) //�ж�������û������������ͬ���� 
	{
		for(int j=0;j<3;j++)
		{
			if(mmp[0][i]==mmp[1][j]) 
			{
				printf("Input Error!\n");
				return 0;
			}
		}
	}
	char cc;
	int i;
	if(decide(all[0])>decide(all[1])) cc='A';
	else if(decide(all[0])<decide(all[1])) cc='B';
	else
	{
		for(i=0;i<3;i++)
		{
			if(num_trans(all[0][i])>num_trans(all[1][i])) {cc='A';break;}
			else if(num_trans(all[0][i])<num_trans(all[1][i])) {cc='B';break;}
		}
	}
	printf("Winner is %c!\n",cc);
	printf("A: %s %s %s\nB: %s %s %s\n",all[0][0],all[0][1],all[0][2],all[1][0],all[1][1],all[1][2]);
	return 0;
}
