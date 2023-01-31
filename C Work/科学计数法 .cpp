/*Remember：高精度问题，不仅仅可以用字符串数组，也可以考虑用整型数组*/
/*数组不一定要从头开始用！！！有时空出前面的数据用来存放0会有很大用处*/ 
#include <stdio.h>
#define X 20     //X为1.0^-X中X最大值
void prt (int a[],int s,int t)    //定义一个从a[s]输出到a[t]的函数 
{
	while (s<=t) printf ("%d",a[X+s++]);
}
int main () 
{
	int a[100]={0},i=0,ip,i0,n;
	char c;
	while (scanf("%1d",&a[X+i++]) != 0);//巧妙利用scanf的返回值输入---处理多位浮点数的另一种思路 
	ip=--i;         //小数点所在位置 
	scanf ("%c",&c);
	if (c=='E'||c=='e')   goto C;     //没有小数点的情况
	while (scanf ("%1d",&a[X+i++]) != 0);   //输入小数点后面的数字，注意此时i的值不是0 
	getchar (); 
	//getchar的作用：输入一串字符并显示，以回车结束，若没有则只显示 
	C:  scanf ("%d",&n);       //指数n 
	for (i=0;a[X+i]==0;i++);
	i0=i;                    //该数前面0的个数
	
	prt (a, i0<ip+n-1?i0:ip+n-1, ip+n-1);
	printf (".");
	prt (a, ip+n, ip+n+7);//控制位数，保留八位 
	printf ("\n");
}
