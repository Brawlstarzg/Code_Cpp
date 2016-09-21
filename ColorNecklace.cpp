/* 
 * ��һ����ɫ��ʯ���������ɺܶ��ֲ�ͬ�ı�ʯ��ɵģ������챦ʯ������ʯ����ʯ����䣬����ȡ�
 * ��һ������������ʹ͸���һ��ѧ�ߣ�������˵������Դ����������������������ϲ���챦ʯ������ʯ����ˮ����������ʯ�����֣���Ҫ��������н�ȡ������һС�λ����ң���һ���б���������е������ֱ�ʯ��ʣ�µĲ�������Դ��ߡ�����޷��ҵ���һ��Ҳ�޷����ߡ������ѧ���ҳ�����з��������ܹ��õ����ı�ʯ��
 * ����
 * ������ÿ���ַ�����һ�ֱ�ʯ��A��ʾ�챦ʯ��B��ʾ����ʯ��C������ˮ����D������䣬E������ʯ��F������ʯ��G�������ȵȣ�������һ��ȫ��Ϊ��д��ĸ���ַ����б�ʾ�����ı�ʯ���У�ע����������β��ӵġ�ÿ�д���һ�������
 * ���
 * ���ѧ���ܹ��õ������ı�ʯ������ÿ��һ��
 */

#include <iostream>
#include <string>

using namespace std;

int Cnt(string &list, int cur, string tar)
{
	int cnt = 0;	// ��Ҫ�и������
	int pos = cur;
	const char* str = list.c_str();
	for (; pos < list.length(); ++pos)
	{
		cnt++;
		if (*(str + pos) >= 'A' && *(str + pos) <= 'E')
		{
			for (size_t i = 0; i < tar.size(); i++)
			{
				if (*(str + pos) == tar[i])
				{
					tar.erase(i, 1);
					break;
				}
			}
			if (tar.empty())
				return cnt;
		}
	}

	for (pos = 0; pos != cur; ++pos)
	{
		cnt++;
		if (*(str + pos) >= 'A' && *(str + pos) <= 'E')
		{
			for (size_t i = 0; i < tar.size(); i++)
			{
				if (*(str + pos) == tar[i])
				{
					tar.erase(i, 1);
					break;
				}
			}
			if (tar.empty())
				return cnt;
		}
	}
	return -1;
}

int main()
{
	string tar("ABCDE");
	string list;
	cin >> list;

		int min = -1;
		int p = 0;
		const char* str = list.c_str();

		for (; p < list.length(); ++p)
		{
			if (*(str + p) >= 'A' && *(str + p) <= 'E')
			{
				int ret = Cnt(list, p, tar);
				if (ret == -1)
					continue;
				if (ret < min || min == -1)
					min = ret;
			}
		}
		cout << list.length() - min << endl;


	return 0;
}