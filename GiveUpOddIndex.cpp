/*
 * ��Ŀ����
 * ����һ����0..n����������������ɵ����У�����Ҫ����һЩɸѡ��ÿ������ȡ��ǰ���������д�С����ĵ�����λ��������
 * �����䶪�����ظ���һ����ֱ�����ʣ��һ��������������ʣ�µ����֡�
 * ��������:
 * ÿ������һ��һ�����֣�Ϊ��Ŀ�е�n(nС�ڵ���1000)��
 * �������:
 * һ��������ʣ�µ����֡�
 */

#include <iostream>
#include <list>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		list<int> l;
		for (int i = 0; i <= n; i++)
			l.push_back(i);
		list<int>::iterator pos = l.begin(), next;

		while (l.size() != 1)
		{
			next = pos;
			++next;
			l.erase(pos);
			pos = next;
			++pos;
			if (pos == l.end())
				++pos;
		}
		cout << *pos << endl;
	}


	return 0;
}