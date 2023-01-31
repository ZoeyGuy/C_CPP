#include <stdio.h>
#include <easyx.h> //绘图所用的库
//Easyx Ref: https://docs.easyx.cn/zh-cn/intro
#include <conio.h> //键盘输入getch()
#include "2048/2048base.h" //2048基本操作函数实现
#define MAP_ROW 4	//地图行
#define MAP_COL 4	//地图列
#define PIXEL 75	//一个格子所占像素

int MaxScore = 0;	//最高分

void init(int *p, int len, int *score);		//初始化游戏
void UpdateMap(int *p, int len, int score); //更新地图渲染
int Judg(int map[][MAP_COL]);			    //判断输赢
void WriteData(int *p, int len, int score);	//写入数据
int ReadData(int *p, int len, int *score);	//读取数据

/* map：
 * a[0][0], a[0][1], a[0][2], a[0][3];
 * a[1][0], a[1][1], a[1][2], a[1][3];
 * a[2][0], a[2][1], a[2][2], a[2][3];
 * a[3][0], a[3][1], a[3][2], a[3][3];
 * 窗口的起点是左上角，向右x增大，向下y增大
 */

int main()
{
    int map[MAP_ROW][MAP_COL] = {0};	//地图大小
    int *p = (int *)map;                //转换为指针
	int score = 0;					    //总成绩
	
	init(p, MAP_COL, &score);			//初始化地图数据
    MaxScore = ReadData(p, MAP_COL, &score);//读取数据
    UpdateMap(p, MAP_COL, score);       //同时更新一下地图
	while (1)
	{
        run(p, MAP_COL, &score);		//运行一次
        UpdateMap(p, MAP_COL, score);   //同时更新地图
		switch (Judg(map))		        //判断游戏状态
		{
		case 2://达到某个目标
			MessageBox(GetHWnd(), L"你实现了自我！", L"恭喜", MB_OK);
			if (score > MaxScore) MaxScore = score;
			WriteData(p, MAP_COL, score);
			return 0;
			break;
		case 1://游戏结束
			MessageBox(GetHWnd(), L"你输了", L"很遗憾", MB_OK);
			if (score > MaxScore) MaxScore = score;
			if (MessageBox(GetHWnd(), L"是否重新开始", L"提示", MB_YESNO | MB_ICONWARNING) == IDNO)
			{
                WriteData(p, MAP_COL, score);//保存游戏
				return 0;
			}
            //MessageBox Ref: https://learn.microsoft.com/zh-cn/windows/win32/api/winuser/nf-winuser-messagebox
            init(p, MAP_COL, &score);		 //输了重来
            UpdateMap(p, MAP_COL, score);
			break;
		default:
			break;
		}
		WriteData(p, MAP_COL, score);	     //保存游戏
	}
	getchar();
	closegraph();
	return 0;
}

/*初始化地图并随机生成两个位置上的数*/
void init(int *p , int len, int *score)
{
    /*1.初始化地图*/
    initgraph(MAP_ROW * PIXEL + 100 + 20, MAP_COL * PIXEL + 100);	//加载窗口
    setorigin(20, 0);                 //设置原点位置
    setbkcolor(RGB(205, 193, 180));	  //背景颜色
    setlinecolor(RGB(187, 173, 160)); //线条颜色
    setlinestyle(PS_SOLID, 5);		  //线条风格
    settextstyle(20, 0, L"Times New Roman");//字体风格 和 字体大小
    cleardevice();					  //清屏
    BeginBatchDraw();                 //缓存绘制
    for (int i = 0; i <= 4; ++i)
    {
        line(PIXEL * i, 0 + 50, PIXEL * i, PIXEL * 4 + 50);//竖线
        line(0, PIXEL * i + 50, PIXEL * 4, PIXEL * i + 50);//横线
    }
    settextcolor(RGB(255, 0, 0));	//字体颜色 红色
    outtextxy(0, 15, L"score: 0");			//分数
    outtextxy(MAP_ROW * PIXEL + 10, 5, L"最高分:");			
    wchar_t arr[20];
    wsprintf(arr, L"%d", MaxScore);
    outtextxy(MAP_ROW * PIXEL + 15, 25, arr);		
    outtextxy(MAP_ROW * PIXEL + 10, 80, L"↑↓←→");		
    outtextxy(MAP_ROW * PIXEL + 10, 120, L"WSAD");		
    outtextxy(MAP_ROW * PIXEL + 10, 160, L"控制游戏");	
    EndBatchDraw();		//结束绘制地图

    /*2.全部赋值为零*/
    memset(p, 0, sizeof(int)*MAP_COL*MAP_ROW);

    /*3.生成随机位置*/
	int x, y;	//随机位置参数
	*score = 0;	//对成绩进行初始化
	for (int i = 0; i < 2;)
	{
		x = rand() % 4; //生成一个0-3之间的随机数
		y = rand() % 4;
		if (*(p+x*len+y) == 0)
		{
			if (rand() % 9 >= 5)
                *(p + x*len + y) = 4;
			else
                *(p + x*len + y) = 2;
			i++;
		}
	}
}

/*根据map图数据渲染图片*/
void UpdateMap(int *p, int len, int score)
{
    wchar_t arr[20];
    BeginBatchDraw(); //缓存写入，防止闪烁
    setbkmode(TRANSPARENT); //设置方块数字背景透明
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            switch (*(p+len*i+j))
            {
            case  0:  setfillcolor(RGB(205, 193, 180)); break;
            case  2:  setfillcolor(RGB(238, 228, 218)); settextcolor(RGB(119, 110, 101)); break;
            case  4:  setfillcolor(RGB(237, 224, 200)); settextcolor(RGB(119, 110, 101)); break;
            case  8:  setfillcolor(RGB(242, 177, 121)); settextcolor(RGB(249, 246, 242)); break;
            case  16: setfillcolor(RGB(245, 149, 99));  settextcolor(RGB(249, 246, 242)); break;
            case  32: setfillcolor(RGB(246, 124, 95));  settextcolor(RGB(249, 246, 242)); break;
            case  64: setfillcolor(RGB(246, 94, 59));   settextcolor(RGB(249, 246, 242)); break;
            case 128: setfillcolor(RGB(237, 207, 114)); settextcolor(RGB(249, 246, 242)); break;
            case 256: setfillcolor(RGB(237, 204, 97));  settextcolor(RGB(249, 246, 242)); break;
            case 512: setfillcolor(RGB(237, 200, 80));  settextcolor(RGB(249, 246, 242)); break;
            case 1024:setfillcolor(RGB(237, 197, 63));  settextcolor(RGB(249, 246, 242)); break;
            case 2048:setfillcolor(RGB(255, 215, 0));   settextcolor(RGB(249, 246, 242)); break;
            }
            fillrectangle(PIXEL*j, PIXEL*i + 50, PIXEL*(j + 1), PIXEL*(i + 1) + 50);
            //绘制地图时，i表示列，j表示行
            if (*(p + len*i + j) != 0)
            {
                wsprintf(arr, L"%d", *(p + len*i + j));
                int lenths = wcslen(arr); //根据长度来确定所在位置
                outtextxy(j * PIXEL + 38 - lenths*4, i * PIXEL + 50 + 30, arr);//指定位置输出字符串
            }
        }
    }
    setbkmode(OPAQUE); //设置显示分数背景默认
    settextcolor(RGB(255,0,0));//更新分数
    wsprintf(arr, L"score: %d", score);
    outtextxy(0, 15, arr);
    wsprintf(arr, L"%d", MaxScore);//更新最高分
    outtextxy(MAP_ROW * PIXEL + 15, 25, arr);
    EndBatchDraw();//缓存写入结束
}

/*判断游戏状态
 * 0：继续游戏
 * 1：游戏结束（无零，且相邻元素不相等）
 * 2：达到某个目标
 */
int Judg(int map[][MAP_COL])
{
	int num = 0;	//记录0的个数
	int flag = 0;	//如果存在一组可以合并的元素 那么flag置为1
	for (int i = 0; i < MAP_COL; ++i)
	{
		for (int j = 0; j < MAP_COL; ++j)
		{
			if (map[i][j] >= 2048) return 2; //达到某个目标
			if (map[i][j] == 0) num++;		 //记录0的个数
			if (j + 1 < 4 && map[i][j] == map[i][j + 1]) flag = 1;//判断右边
			if (i + 1 < 4 && map[i][j] == map[i + 1][j]) flag = 1;//判断下方
		}
	}
	if (num == 0 && flag == 0)  return 1;	//游戏结束
	if (num == 0) return 0;					//游戏继续
	return 0;
}

/*写入数据*/
void WriteData(int *p, int len, int score)
{
    FILE *fp = fopen("../2048/2048.data", "w"); //fopen函数的当前路径是exe文件的路径
    if (fp == NULL)
        return;
    for (int i = 0; i < MAP_COL; i++)
    {
        for (int j = 0; j < MAP_ROW; j++)
            fprintf(fp, "%d ", *(p+i*len+j));
        fprintf(fp, "\n");
    }
    fprintf(fp, "%d\n", score);
    fprintf(fp, "%d\n", MaxScore);
    fclose(fp);
}

/*读取数据*/
int ReadData(int *p, int len, int *score)
{
    FILE *fp = fopen("../2048/2048.data", "r");
    if (fp == NULL)
        return 0;
    for (int i = 0; i < MAP_COL; i++)
    {
        for (int j = 0; j < MAP_ROW; j++)
        {
            fscanf(fp, "%d", p + i*len + j);
        }
    }
    fscanf(fp, "%d", score);
    int max = 0;
    fscanf(fp, "%d", &max);
    fclose(fp);
    return max;
}

