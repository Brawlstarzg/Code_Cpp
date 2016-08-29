#define _CRT_SECURE_NO_WARNINGS


/*
 * ��Ŀ����
 * ss��cc��������㣬�����ɻ���Ϊn��m�ĸ��ӣ�ÿ�������в�ͬ�ĸ��ʵ����㣬ccһֱ������(x,y)�ĸ��ӵ��㣬
 * ��ssÿ���������һ�����ӡ���t���Ӻ�����˭���ٵ���һ����ĸ��ʴ�Ϊ���٣�
 * ��������:
 * ��һ���������n,m,x,y,t(1��n,m,t��1000,1��x��n,1��y��m);
 * ������Ϊһ��n��m�ľ���ÿ��m��һλС������n�У���i�е�j������������Ϊ(i,j)�ĸ��ӵ�����ĸ���Ϊp(0��p��1)
 * �������:
 * ������С���һ��Ϊ���ʴ���˵�����(cc/ss/equal),�ڶ���Ϊ�������(����2λС��)
 */

#include <stdio.h>

void MaxP(float *p, int n, int m, int x, int y, int t)
{
	x--;
	y--;
	int size = n * m;
	float ssP = 0.0f;
	for (int i = 0; i < size; i++)
		ssP += p[i];
	ssP = ssP / size * t;

	float ccP = p[x*n + y] * t;

	if (ssP > ccP)
		printf("ss\n%.2f\n", ssP);
	else if (ssP < ccP)
		printf("cc\n%.2f\n", ccP);
	else
		printf("equal\n%.2f\n", ssP);
}

int main()
{
	int n, m, x, y, t;
	float *p;
	while (scanf("%d%d%d%d%d", &n, &m, &x, &y, &t) != EOF)
	{
		p = new float[n * m];
		int i = 0;
		int size = n * m;
		while (i < size)
		{
			scanf("%f", p + i);
			i++;
		}

		MaxP(p, n, m, x, y, t);

		delete[] p;
	}

	return 0;
}