/*
 * ��Ŀ����
 * Сv������n�ſΣ�ÿ�Ŷ��п��ԣ�Ϊ���õ���ѧ��Сv�������Լ���ƽ���ɼ�����Ϊavg��
 * ÿ�ſ���ƽʱ�ɼ��Ϳ��Գɼ���ɣ�����Ϊr��������֪��ÿ�ſε�ƽʱ�ɼ�Ϊai ,���������ſεĿ��Գɼ�����һ�ֵĻ���
 * СvҪ��bi ��ʱ�临ϰ������ϰ�Ļ���Ȼ����0�֡�ͬʱ������Ȼ���Է��ָ�ϰ���ٶ�Ҳ�����õ��������ֵķ�����
 * Ϊ���õ���ѧ��Сv����Ҫ������ʱ�临ϰ��
 * ��������:
 * ��һ����������n,r,avg(n���ڵ���1С�ڵ���1e5��r���ڵ���1С�ڵ���1e9,avg���ڵ���1С�ڵ���1e6)��������n�У�
 * ÿ����������ai��bi����С�ڵ���1e6���ڵ���1
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info
{
	int a;
	int b;

	friend bool operator<(const info& left, const info& right)
	{
		return left.b < right.b;
	}
};

int Time(info* p, int n, int r, int avg)
{
	vector<info> v(p, p + n);
	sort(v.begin(), v.end());

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += v[i].a;
	}
	sum = n*avg - sum;
	int time = 0;
	for (int i = 0; i < n; i++)
	{
		if (sum - (r - v[i].a) <= 0)
		{
			time += sum*v[i].b;
			return time;
		}
		int grade = r - v[i].a;
		sum -= grade;
		time += grade * v[i].b;
	}

	return time;
}

int main()
{
	int n, r, avg;
	while (cin >> n >> r >> avg)
	{
		info *p = new info[n];

		for (int i = 0; i < n; i++)
		{
			cin >> p[i].a >> p[i].b;
		}

		int ret = Time(p, n, r, avg);
		cout << ret << endl;

		delete[] p;
	}


	return 0;
}