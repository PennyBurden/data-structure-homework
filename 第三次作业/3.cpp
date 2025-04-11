#include<iostream>
#include<cmath>
using namespace std;
#define STACKINITSIZE 256
#define STACKINCREMENT 128

typedef struct Point
{
	int col;
	int row;
};
typedef Point ElemType;
struct SeqStack
{
	ElemType* pTop;
	ElemType* pBase;
	int stacksize;
};
int InitStack(SeqStack* s)
{
	s->pBase = (ElemType*)malloc((STACKINCREMENT) * sizeof(ElemType));
	if (s->pBase == NULL)
	{
		exit(0);
	}
	s->pTop = s->pBase;
	s->stacksize = STACKINCREMENT;
	return 0;
}
int JudgeQueenConfiliction(Point newQueen, SeqStack StkQueen) //判断新的皇后位置与已有皇后位置是否冲突 
{
	ElemType* curQueen;
	int x1 = newQueen.col;
	int y1 = newQueen.row;
	curQueen = StkQueen.pBase;
	int tag = 1;
	while (curQueen < StkQueen.pTop)
	{
		int x2 = curQueen->col;
		int y2 = curQueen->row;
		if (x1 == x2)   //同一列 
		{
			tag = 0;
			break;
		}
		if (abs(x1 - x2) == (y1 - y2)) //同一正斜线或逆斜线 
		{
			tag = 0;
			break;
		}
		curQueen++;
	}
	return tag;
}
int push(SeqStack* s, ElemType e)
{
	if (s->pTop - s->pBase == s->stacksize)
	{
		s->pBase = (ElemType*)realloc(s->pBase, (s->stacksize + STACKINCREMENT) * sizeof(ElemType));
		if (s->pBase == NULL)
			exit(0);
	}
	*s->pTop = e;
	s->pTop++;
	return 0;
}
int StackEmpty(SeqStack s)
{
	if (s.pBase == s.pTop)
		return 1;
	else
	{
		return 0;
	}
}
int Pop(SeqStack* s, ElemType* e)
{
	if (s->pBase == s->pTop)
		return 0;
	*e = *(s->pTop - 1);
	s->pTop--;
	return 1;
}

int ExpressQueen(SeqStack s, int m)
{
	ElemType* temp;
	temp = s.pBase;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == temp->row && j == temp->col)
			{
				cout << "1 ";
			}
			else cout << "0 ";
		}
		cout << endl;
		temp++;
	}
	cout << "****************" << endl;
	return 0;
}
int PlaceQueen(int N)
{
	SeqStack stkQueen;
	Point curQueen;
	int ret;

	InitStack(&stkQueen);
	int resultCount = 0;
	curQueen.row = 1;
	curQueen.col = 1;
	push(&stkQueen, curQueen);
	curQueen.row = 2;
	curQueen.col = 1;
	while (curQueen.row <= N && curQueen.col <= N)
	{
		while (curQueen.col <= N)
		{
			ret = JudgeQueenConfiliction(curQueen, stkQueen);
			if (ret == 1)
				break;
			curQueen.col += 1;
		}

		if (ret == 1)
		{
			push(&stkQueen, curQueen);
			curQueen.row += 1;
			curQueen.col = 1;
			if (curQueen.row > N)
			{
				ExpressQueen(stkQueen, N);

				resultCount++;
				Pop(&stkQueen, &curQueen);
				curQueen.col += 1;
				while (curQueen.col > N && !StackEmpty(stkQueen))
				{
					Pop(&stkQueen, &curQueen);
					curQueen.col += 1;
				}
			}
		}
		else
		{
			Pop(&stkQueen, &curQueen);
			curQueen.col += 1;
			while (curQueen.col > N && !StackEmpty(stkQueen))
			{
				Pop(&stkQueen, &curQueen);
				curQueen.col += 1;
			}
		}
	}
	cout << "  有" << resultCount << "种情况" << endl;
	return 0;
}
int main()
{
	SeqStack s;
	cout << " 计算八皇后求解" << endl;
	int i = 8;
	 
	PlaceQueen(i);

}
