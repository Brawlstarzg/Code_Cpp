/*
 * ��Ŀ���� 
 * ������һ���ַ����б���һ���ؼ����б������һ����Ч�㷨���������ؼ����б��йؼ���(һ������)���ַ�����
 * �����ַ�������A�����Ĵ�Сn�Լ��ؼ�������key�����Ĵ�Сm���뷵��һ���ź���ĺ��ؼ��ʵ��ַ�����ŵ��б�
 * ��֤�����ַ�������С�ڵ���100���ؼ��ʸ���С�ڵ���100���ַ�������С�ڵ���200����֤�����ַ���ȫ����СдӢ���ַ���ɡ�
 * �������ں��ؼ��ֵ��ַ������뷵��һ��ֻ��-1�����顣
 * ����������
 * ["nowcoder","hello","now"],3,["coder",now],2
 * ���أ�[0,2]
 */

class KeywordDetect
{
public:
	vector<int> containKeyword(vector<string> A, int n, vector<string> keys, int m)
	{
		// write code here
		vector<int> ret;
		int i = 0;
		for (; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (A[i].find(keys[j]) != string::npos)
				{
					ret.push_back(i);
					break;
				}
			}
		}
		if (ret.empty())
			ret.push_back(-1);

		return ret;
	}
};