/*
 *������dijstra���·�Ĵ�����ϰ
 *ʱ�䣺2016��5��3��
 */

#include<iostream>
#include<string.h>
using namespace std;


#define  MAX_LEN 100
#define  INFINITE 1000
typedef struct grah
{
	int nodenum;
	int edgenum;
	int matrix[MAX_LEN][MAX_LEN];
}Graph;

typedef struct stack
{
	int bottom;
	int top;
	int printout[MAX_LEN];

}mstack;

int in[MAX_LEN];
int len[MAX_LEN];
int path[MAX_LEN];

void InitStack(mstack *s)
{
	s->bottom = 0;
	s->top = 0;
	memset(s->printout, 0, sizeof(int)*MAX_LEN);
}

void push(mstack *s, int m)
{
	s->printout[s->top++] = m;//��ջ
}

int pop(mstack *s)
{
	return s->printout[s->top--];
}

void InitGraph(Graph *g, int n)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
			{
				g->matrix[i][j] = 0;
			}
			else
			{
				g->matrix[i][j] = INFINITE;//��ʼ��Ϊ���ֵ������������
			}
		}
	}

	for (i = 1; i <= n; i++)
	{
		in[i] = 0;
		len[i] = INFINITE;
		path[i] = 0;
	}
}

int main()
{
	int n, m, i, A, B, templen, count, min, tempmin, si, temp;

	cin >> n >> m;

	count = 0;
	Graph mGraph;
	mGraph.edgenum = m;
	mGraph.nodenum = n;
	InitGraph(&mGraph, n);//��ʼ��ͼ
	for (i = 0; i < m; i++)
	{
		cin >> A >> B >> templen;
		mGraph.matrix[A][B] = templen;//���й�ϵ�ı߸���Ȩ��
	}

	in[1] = 1;
	path[1] = 1;
	len[1] = 0;

	for (i = 2; i <= n; i++)
	{
		len[i] = mGraph.matrix[1][i];
		if (len[i] != INFINITE)
		{
			path[i] = 1;
		}
	}

	min = 0;
	si = 1;

	while (count < n - 1)
	{
		tempmin = INFINITE;
		for (i = 1; i <= n; i++)
		{
			if (in[i] == 0 && len[i] < tempmin)
			{
				tempmin = len[i];
				si = i;
			}
		}

		in[si] = 1;

		//����·��
		for (i = 1; i <= n; i++)
		{
			if (in[i] == 0 && (tempmin + mGraph.matrix[si][i]) < len[i])
			{
				len[i] = tempmin + mGraph.matrix[si][i];
				path[i] = si;	//����i������·�����¼����
			}
		}
		count++;


	}

	mstack s;
	for (i = 1; i <= n; i++)
	{
		temp = i;
		InitStack(&s);
		if (path[temp] == 0)
		{
			printf("no path\n");
			continue;
		}
		while (path[temp] != 1)
		{
			push(&s, path[temp]);
			temp = path[temp];	//��¼��ǰһ���ڵ�����
		}

		printf("1-->");
		s.top--;
		while (s.bottom <= s.top)
		{
			printf("%d-->", pop(&s));

		}

		printf("%d min length is %d\n", i, len[i]);
	}

	system("pause");
	return 0;
}
