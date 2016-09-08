/*
 * ��Ŀ����
 * һ����l�ı�ֱ�Ľֵ�����n��·�ƣ��������ֵ����Ϊ0���յ�Ϊl����i��·������Ϊai��ÿյ�ƿ��Ը���
 * ������Զ����Ϊd��Ϊ�������������еƵĵƹ���븲�������֣�����Ϊ��ʡ�磬Ҫ�����d��С�����ҵ������С��d��
 * ��������:
 * ÿ�����ݵ�һ����������n��l��n����0С�ڵ���1000��lС�ڵ���1000000000����0�����ڶ�����n������
 * (�����ڵ���0С�ڵ���l)��Ϊÿյ�Ƶ����꣬���·�ƿ�����ͬһ�㡣
 */

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

float MinDistance(vector<int>& v, int l)
{
	sort(v.begin(), v.end());
	int size = v.size();

	float max = 0;
	for (int i = 1; i < size; i++)
	{
		if (v[i] - v[i - 1] > max)
			max = v[i] - v[i - 1];
	}
	max /= 2;
	if (v[0] > max)
		max = v[0];
	if (l - v[size - 1] > max)
		max = l - v[size - 1];
	return max;
}

int main()
{
	int n, l;
	vector<int> v;
	while (cin >> n >> l)
	{
		v.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		float ret = MinDistance(v, l);
		printf("%.2f\n", ret);
	}

	return 0;
}