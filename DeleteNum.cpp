/* 
 * ��Ŀ����
 * ��һ������a[N]˳����0~N - 1��Ҫ��ÿ��������ɾ��һ��������ĩβʱѭ������ͷ�������У������һ����ɾ��������ԭʼ�±�λ�á���8����(N = 7)Ϊ��:��0��1��2��3��4��5��6��7����0->1->2(ɾ��)->3->4->5(ɾ��)->6->7->0(ɾ��), ���ѭ��ֱ�����һ������ɾ����
 * �������� :
 * ÿ������Ϊһ��һ������n(С�ڵ���1000)��Ϊ�����Ա��, �������1000�����a[999]���м��㡣
 * ������� :
 * һ��������һ����ɾ��������ԭʼ�±�λ�á�
 */

#include <iostream>
#include <list>

using namespace std;

int LastIndex(int n)
{
	list<int> l;
	int i = 0;
	while (i < n)
	{
		l.push_back(i);
		i++;
	}

	list<int>::iterator pos = l.begin();
	list<int>::iterator del;
	while (l.size() > 1)
	{
		++pos;
		if (pos == l.end())
			pos = l.begin();
		++pos;
		if (pos == l.end())
			pos = l.begin();
		del = pos;
		++pos;
		if (pos == l.end())
			pos = l.begin();
		l.erase(del);
	}
	return *pos;
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (n > 1000)
			n = 1000;
		int ret = LastIndex(n);
		printf("%d\n", ret);
	}

	return 0;
}