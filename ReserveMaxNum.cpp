/*
 * ��Ŀ������
 * ����һ��ʮ���Ƶ�������number��ѡ�������ȥ��һ�������֣�ϣ������������������ɵ����������
 * ����
 * ����Ϊ�������ݣ���һ����������number��ע������Ǻܴ�ġ��ڶ�����ϣ��ȥ��������������
 * ���
 * ������������Ľ����
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string num;
	cin >> num;
	int n;
	cin >> n;

	while (n-- && !num.empty())
	{
		string::iterator pos = num.begin(), min = pos;
		for (++pos; pos != num.end(); ++pos)
		{
			if (*pos < *min)
				min = pos;
		}
		num.erase(min);
	}
	if (num.empty())
		cout << 0 << endl;
	else
		cout << num << endl;

	return 0;
}