/*
 * ��Ŀ������
 * ����һ�����ӣ�ֻ������ĸ�Ϳո񣩣� �������еĵ���λ�÷�ת�������ÿո�ָ�, ����֮��ֻ��һ���ո�ǰ��û�пո�
 * ���磺
 * ��1�� ��hello xiao mi��-> ��mi xiao hello��
 * ����
 * ���������ж��飬ÿ��ռһ�У�����һ������(���ӳ���С��1000���ַ�)
 * ���
 * ����ÿ������ʾ����Ҫ����������е��ʷ�ת���γɵľ���
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	string tmp;
	while (cin >> tmp)
	{
		str += tmp;
		str += " ";
	}
	str.erase(str.length()-1, 1);	

	string ret;
	const char* finish = str.c_str();
	char* end = (char*)(finish + str.length() - 1);
	
	while (end >= finish)
	{
		while (end >= finish && *end != ' ')
			end--;
		if (end < finish)
		{
			ret += end + 1;
		}
		else
		{
			*end = '\0';
			ret += end + 1;
			ret += " ";
		}
	}
	cout << ret << endl;

	return 0;
}