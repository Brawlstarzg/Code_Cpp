#define _CRT_SECURE_NO_WARNINGS

/*
 * �����һ����Ч�㷨���ٸ������ַ��������У��ҵ�����"Coder"���ַ���(�����ִ�Сд)����������Ϊһ���µ����鷵�ء�
 * ����ַ�����˳����"Coder"���ֵĴ����ݼ����У�����������"Coder"���ֵĴ�����ͬ���򱣳�������ԭ�����е�λ�ù�ϵ��
 * ����һ���ַ�������A�����Ĵ�Сn���뷵�ؽ�����顣��֤ԭ�����СС�ڵ���300,����ÿ�����ĳ���С�ڵ���200��
 * ͬʱ��֤һ�����ڰ���coder���ַ�����
 * ����������
 * ["i am a coder","Coder Coder","Code"],3
 * ���أ�["Coder Coder","i am a coder"]
 */

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Coder
{
public:
	vector<string> findCoder(vector<string> A, int n)
	{
		// write code here
		vector<string> ret(A);
		int *cnt = new int[n];

		for (int i = 0; i < n; i++)
		{
			cnt[i] = nums(A[i]);
		}

		InsertSort(ret, cnt, n);

		delete[] cnt;
		return ret;
	}

	void InsertSort(vector<string> &A, int *cnt, int n)
	{
		for (int i = 1; i < n; i++)
		{
			int tmp = cnt[i];
			string t = A[i];
			int j = i - 1;
			for (; j >= 0; j--)
			{
				if (cnt[j] >= tmp)
					break;
				else
				{
					cnt[j + 1] = cnt[j];
					A[j + 1] = A[j];
				}
					
			}
			j++;
			if (j != i)
			{
				cnt[j] = tmp;
				A[j] = t;
			}
		}

	}

	int nums(string &str)
	{
		char *s = new char[str.size() + 1];
		strcpy(s, str.c_str());
		strupr(s);
		char *tmp = s;
		int n = 0;

		while ((tmp = strstr(tmp, "coder")) != NULL)
		{
			tmp += 5;
			n++;
		}
		delete[] s;
		return n;
	}

	void strupr(char *str)
	{
		char *tmp = str;
		while (*tmp != '\0')
		{
			if (isupper(*tmp))
				*tmp += ('a' - 'A');
			tmp++;
		}
	}
};

int main()
{
	
	string s1("coder");
	string s2("dccoderrlcoderxxpicoderhcoderbiwcoderdcoderrcodermcoderdbvcodertrwvycoderimvcoderuswfccoderczecoderczncoderkfuehcoderocoderiuvccoderfwcodervdiycoderifqjcoder");
	string s3("vxroicoderdqcoderfvcodermtyrcoderlcoderwrygcoder");
	string s4("hcoderwzmjccoderamfmvcoderazmcoderhcodersnuccoderceocodermsmifcoderpwpcodertqbqcoderentbcoderxsgpkcoderrqrbcoderucoder");
	vector<string> v;
	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	v.push_back(s4);
	Coder c;
	c.findCoder(v, v.size());

	return 0;
}