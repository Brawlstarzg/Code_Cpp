/*
 * ��Ŀ����
 * �ȶ�����һ������ֽ������ֽ����һЩ����ĵ㣬ÿ���㶼��������ϣ��������񿴳�һ��������ƽ���������ߵ�����ϵ�Ļ���
 * ÿ���������һ������x��y����ʾ���ȶ��ܱ������������߻�һ�������Σ�ʹ���е��������ε��ڲ����߽߱硣Ȼ�����������μ��������ʼ��������ε���С����Ƕ��١�
 * ��������:
 * ��һ��һ����n(2��n��1000)��ʾ������������ÿ��һ������xi,yi(��1e9<=xi,yi<=1e9)��ʾ�����ϵĵ�
 * �������:
 * һ�������С���
 */

#include <stdio.h>

int MinArea(int *x, int *y, int n)
{
	if (NULL == x || NULL == y || n < 0)
		return -1;

	int max_x = x[0];
	int min_x = x[0];
	int max_y = y[0];
	int min_y = y[0];
	for (int i = 1; i < n; i++)
	{
		if (x[i] > max_x)
			max_x = x[i];
		if (x[i] < min_x)
			min_x = x[i];
		if (y[i] > max_y)
			max_y = y[i];
		if (y[i] < min_y)
			min_y = y[i];
	}

	int sub_x = max_x - min_x;
	int sub_y = max_y - min_y;
	int area = sub_x > sub_y ? sub_x*sub_x : sub_y*sub_y;
	return area;
}


int main()
{
	int n;
	int *x, *y;

	while (scanf("%d", &n) != EOF)
	{
		int i = 0;
		x = new int[n];
		y = new int[n];
		while (i < n)
		{
			scanf("%d%d", x + i, y + i);
			i++;
		}

		int min = MinArea(x, y, n);
		printf("%d\n", min);

		delete[] x;
		delete[] y;
	}

	return 0;
}