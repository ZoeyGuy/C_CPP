// #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

class Cube
{
public:
	Cube();
	void swap(int i, int j, vector<int> &S);
	int Code(vector<int> &S, unsigned long long k, int l);
	void Search();
	void print(int a);
	void AntiSearch();
	int Operation(int a);
	void Recall(unsigned long long a, unsigned long long b);
	bool F_90(vector<int> &S);
	bool _F90(vector<int> &S);
	bool F_180(vector<int> &S);
	bool R_90(vector<int> &S);
	bool _R90(vector<int> &S);
	bool R_180(vector<int> &S);
	bool U_90(vector<int> &S);
	bool _U90(vector<int> &S);
	bool U_180(vector<int> &S);
	bool Change(int i, vector<int> &S);
	vector<int> State;	//状态数组，为一组int类型的数据
	vector<int> Target; //目标状态顺序
	vector<unsigned long long> B;
	vector<unsigned long long> D;
	unsigned long long Conflict1, Conflict2;
	map<unsigned long long, unsigned long long> Hash;
};

Cube::Cube() //初始化和输入函数
{
	State.reserve(24); //反转数组
	Target.reserve(24);
	for (int i = 0; i < 24; i++)
	{
		int a;
		scanf("%d", &a);
		State.push_back(a);
		Target.push_back(i);
	}
	B.reserve(1);
	D.reserve(1);
	Conflict1 = Conflict2 = -1;
}

void Cube::swap(int i, int j, vector<int> &S) //交换数组中的两位
{
	int temp;
	temp = S[i];
	S[i] = S[j];
	S[j] = temp;
}

bool Cube::F_90(vector<int> &S) //前面顺时针转动90度
{
	swap(0, 6, S);
	swap(1, 7, S);
	swap(2, 8, S);
	swap(3, 6, S);
	swap(4, 7, S);
	swap(5, 8, S);
	swap(6, 9, S);
	swap(7, 10, S);
	swap(8, 11, S);
	return 1;
}
bool Cube::_F90(vector<int> &S) //前面逆时针转动90度
{
	swap(0, 6, S);
	swap(1, 7, S);
	swap(2, 8, S);
	swap(0, 9, S);
	swap(1, 10, S);
	swap(2, 11, S);
	swap(0, 3, S);
	swap(1, 4, S);
	swap(2, 5, S);
	return 1;
}
bool Cube::F_180(vector<int> &S) //前面转动180度
{
	swap(3, 6, S);
	swap(4, 7, S);
	swap(5, 8, S);
	swap(0, 9, S);
	swap(1, 10, S);
	swap(2, 11, S);
	return 1;
}
bool Cube::R_90(vector<int> &S) //右边顺时针转动90度
{
	swap(3, 17, S);
	swap(4, 15, S);
	swap(5, 16, S);
	swap(3, 21, S);
	swap(4, 22, S);
	swap(5, 23, S);
	swap(3, 11, S);
	swap(4, 9, S);
	swap(5, 10, S);
	return 1;
}
bool Cube::_R90(vector<int> &S) //右边逆时针转动90度
{
	swap(3, 11, S);
	swap(4, 9, S);
	swap(5, 10, S);
	swap(3, 21, S);
	swap(4, 22, S);
	swap(5, 23, S);
	swap(3, 17, S);
	swap(4, 15, S);
	swap(5, 16, S);
	return 1;
}
bool Cube::R_180(vector<int> &S) //右边转动180度
{
	swap(3, 21, S);
	swap(4, 22, S);
	swap(5, 23, S);
	swap(9, 15, S);
	swap(10, 16, S);
	swap(11, 17, S);
	return 1;
}
bool Cube::U_90(vector<int> &S) //上面顺时针转动90度
{
	swap(0, 14, S);
	swap(1, 12, S);
	swap(2, 13, S);
	swap(0, 15, S);
	swap(1, 16, S);
	swap(2, 17, S);
	swap(0, 5, S);
	swap(1, 3, S);
	swap(2, 4, S);
	return 1;
}
bool Cube::_U90(vector<int> &S) //上面逆时针转动90度
{
	swap(0, 5, S);
	swap(1, 3, S);
	swap(2, 4, S);
	swap(0, 15, S);
	swap(1, 16, S);
	swap(2, 17, S);
	swap(0, 14, S);
	swap(1, 12, S);
	swap(2, 13, S);
	return 1;
}
bool Cube::U_180(vector<int> &S) //上面转动180度
{
	swap(0, 15, S);
	swap(1, 16, S);
	swap(2, 17, S);
	swap(3, 12, S);
	swap(4, 13, S);
	swap(5, 14, S);
	return 1;
}

bool Cube::Change(int i, vector<int> &S) //在某一状态下进行某一操作，共有9种选择
{
	switch (i)
	{
	case 1:
	{
		F_90(S);
		break;
	}
	case 2:
	{
		F_180(S);
		break;
	}
	case 3:
	{
		_F90(S);
		break;
	}
	case 4:
	{
		R_90(S);
		break;
	}
	case 5:
	{
		R_180(S);
		break;
	}
	case 6:
	{
		_R90(S);
		break;
	}
	case 7:
	{
		U_90(S);
		break;
	}
	case 8:
	{
		U_180(S);
		break;
	}
	case 9:
	{
		_U90(S);
		break;
	}
	}
	return 1;
}

int Cube::Operation(int a)
{
	switch (a % 3)
	{
	case 1:
	{
		return a + 2;
	}
	case 2:
	{
		return a;
	}
	case 0:
	{
		return a - 2;
	}
	default:
		return 0;
	}
}

int Cube::Code(vector<int> &S, unsigned long long k, int l)
{
	unsigned long long temp = 0;
	unsigned long long q1 = 10000000000000;
	unsigned long long q2 = 1000000;
	for (int i = 0; i < 24; i = i + 3)
	{
		if (i != 18)
		{
			temp += q1 * (S[i] / 3);
			temp += q2 * (S[i] % 3);
			q1 /= 10;
			q2 /= 10;
		}
	}
	if (temp == 1234570000000)
	{
		return 2;
	}
	if (Hash.count(temp))
	{
		map<unsigned long long, unsigned long long>::iterator iter;
		unsigned long long tmp;
		iter = Hash.find(temp);
		tmp = iter->second;
		if (tmp % 10 == l)
		{
			return 3;
		}
		else
		{
			Conflict1 = tmp;
			return 0;
		}
	}
	Hash.insert(pair<unsigned long long, unsigned long long>(temp, k * 10 + l));
	return 1;
}

void Cube::print(int a) //打印操作及各操作之后的状态
{
	switch (a)
	{
	case 1:
	{
		printf("F+\n");
		break;
	}
	case 2:
	{
		printf("F2\n");
		break;
	}
	case 3:
	{
		printf("F-\n");
		break;
	}
	case 4:
	{
		printf("R+\n");
		break;
	}
	case 5:
	{
		printf("R2\n");
		break;
	}
	case 6:
	{
		printf("R-\n");
		break;
	}
	case 7:
	{
		printf("U+\n");
		break;
	}
	case 8:
	{
		printf("U2\n");
		break;
	}
	case 9:
	{
		printf("U-\n");
		break;
	}
	default:
		break;
	}
	for (int i = 0; i < 24; i++)
	{
		printf("%d ", State[i]);
	}
	printf("\n");
}

void Cube::Search() //前向搜索
{
	queue<vector<int>> P;
	queue<vector<int>> Q;
	queue<int> p;
	queue<int> q;
	B.push_back(0);
	D.push_back(0);
	unsigned long long count1 = 0, count2 = 1;
	unsigned long long c1 = 0, c2 = 1;
	if (Code(State, 0, 1) == 2)
		return;
	Q.push(Target);
	q.push(0);
	B.resize(10);
	for (int i = 1; i < 9; i = i + 3)
	{
		Change(i, State);
		P.push(State);
		B[i] = 0;
		if (Code(State, i, 1) == 2)
		{
			Conflict2 = i;
			Change(i + 2, State);
			return;
		}
		Change(i + 2, State);
		p.push(i);
		Change(i + 1, State);
		P.push(State);
		B[i + 1] = 0;
		if (Code(State, i + 1, 1) == 2)
		{
			Conflict2 = i + 1;
			Change(i + 1, State);
			return;
		}
		Change(i + 1, State);
		p.push(i);
		Change(i + 2, State);
		P.push(State);
		B[i + 2] = 0;
		if (Code(State, i + 2, 1) == 2)
		{
			Conflict2 = i + 2;
			Change(i, State);
			return;
		}
		Change(i, State);
		p.push(i);
	}
	int C1 = 1, C2 = 6;
	unsigned long long p1 = 9;
	unsigned long long q1 = 0;
	while (!P.empty() || !Q.empty())
	{
		while (q1 < C1 * 9)
		{
			D.resize(10 + 9 * count1);
			for (int i = 1; i < 9; i = i + 3)
			{
				if (i != q.front())
				{
					Change(i, Q.front());
					Q.push(Q.front());
					D[i + 9 * count1] = c1;
					if (!Code(Q.front(), i + 9 * count1, 0))
					{
						Conflict2 = i + 9 * count1;
						return;
					}
					Change(i + 2, Q.front());
					q.push(i);
					q1++;
					Change(i + 1, Q.front());
					Q.push(Q.front());
					D[i + 9 * count1 + 1] = c1;
					if (!Code(Q.front(), i + 1 + 9 * count1, 0))
					{
						Conflict2 = i + 9 * count1 + 1;
						return;
					}
					Change(i + 1, Q.front());
					q.push(i);
					q1++;
					Change(i + 2, Q.front());
					Q.push(Q.front());
					D[i + 9 * count1 + 2] = c1;
					if (!Code(Q.front(), i + 2 + 9 * count1, 0))
					{
						Conflict2 = i + 9 * count1 + 2;
						return;
					}
					Change(i, Q.front());
					q.push(i);
					q1++;
				}
			}
			Q.pop();
			q.pop();
			count1++;
			c1++;
			while (!D[c1] && c1 > 9)
			{
				c1++;
			}
		}
		while (p1 < 9 * C1)
		{
			B.resize(19 + 9 * count2);
			for (int i = 1; i < 9; i = i + 3)
			{
				if (i != p.front())
				{
					Change(i, P.front());
					P.push(P.front());
					B[i + 9 * count2] = c2;
					if (!Code(P.front(), i + 9 * count2, 1) || Code(P.front(), i + 9 * count2, 1) == 2)
					{
						Conflict2 = i + 9 * count2;
						return;
					}
					Change(i + 2, P.front());
					p.push(i);
					p1++;
					Change(i + 1, P.front());
					P.push(P.front());
					B[i + 9 * count2 + 1] = c2;
					if (!Code(P.front(), i + 1 + 9 * count2, 1) || Code(P.front(), i + 1 + 9 * count2, 1) == 2)
					{
						Conflict2 = i + 9 * count2 + 1;
						return;
					}
					Change(i + 1, P.front());
					p.push(i);
					p1++;
					Change(i + 2, P.front());
					P.push(P.front());
					B[i + 9 * count2 + 2] = c2;
					if (!Code(P.front(), i + 2 + 9 * count2, 1) || Code(P.front(), i + 2 + 9 * count2, 1) == 2)
					{
						Conflict2 = i + 9 * count2 + 2;
						return;
					}
					Change(i, P.front());
					p.push(i);
					p1++;
				}
			}
			P.pop();
			p.pop();
			count2++;
			c2++;
			while (!B[c2] && c2 > 9)
			{
				c2++;
			}
		}
		p1 = q1 = 0;
		C1 *= 6;
		C2 *= 6;
	}
}

void Cube::Recall(unsigned long long a, unsigned long long b) //回溯函数
{
	int count = 0;
	unsigned long long tmp = b;
	stack<int> Recall1;
	while (a)
	{
		if (a % 9)
		{
			Recall1.push(a % 9);
		}
		else
		{
			Recall1.push(9);
		}
		a = B[a];
		count++;
	}
	while (tmp)
	{
		tmp = D[tmp];
		count++;
	}
	printf("%d\n", count);
	while (!Recall1.empty())
	{
		Change(Recall1.top(), State);
		print(Recall1.top());
		Recall1.pop();
	}
	while (b)
	{
		if (b % 9)
		{
			Change(Operation(b % 9), State);
			print(Operation(b % 9));
			b = D[b];
		}
		else
		{
			Change(Operation(9), State);
			print(Operation(9));
			b = D[b];
		}
	}
}

void Cube::AntiSearch() //反向搜索
{
	int T1 = B.size();
	int T2 = D.size();
	if (T1 == 1)
	{
		printf("0\n");
		return;
	}
	if (Conflict1 == -1)
	{
		int temp = Conflict2;
		int count = 0;
		queue<int> Recall;
		while (temp)
		{
			Recall.push(temp % 10);
			temp = B[temp];
			count++;
		}
		printf("%d\n", count);
		while (!Recall.empty())
		{
			Change(Recall.front(), State);
			print(Recall.front());
			Recall.pop();
		}
		return;
	}
	if (Conflict1 % 10)
	{
		Recall(Conflict1 / 10, Conflict2);
	}
	else
	{
		Recall(Conflict2, Conflict1 / 10);
	}
}

int main()
{
	Cube temp;
	temp.Search();
	temp.AntiSearch();
	return 0;
}
