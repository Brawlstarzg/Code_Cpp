/*
 * һֻ����Ҫ�Ӻ���������Ӷ԰����Ӻܿ����Ǻ��м���˺ܶ�׮�ӣ�ÿ��һ�׾���һ����ÿ��׮���϶���һ�����ɣ�
 * �������������ϾͿ������ĸ�Զ��ÿ������������ͬ����һ�����ִ������������������������Ϊ5��
 * �ʹ��������һ������ܹ���5�ף����Ϊ0���ͻ��ݽ�ȥ�޷�������Ծ������һ��N�׿������ʼλ�þ��ڵ�һ���������棬
 * Ҫ�������һ������֮���������ˣ�����ÿ�����ɵ������������������Ҫ�������ܹ�����԰�������޷��������-1
 * ����
 * ��������У���һ�������鳤��N���ڶ�����ÿһ���ֵ���ÿո�ָ�
 * ���
 * ������ٵ��������޷��������-1
 */

#include <iostream>
#include <vector>

using namespace std;

int Judge(vector<int> arr)
{
	vector<int> cnt(arr.size() + 1, 0);	//��ǰ��������

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] != 0 && (cnt[i] != 0 || i == 0))	// ��ǰ���ӿ��Ե���
		{
			for (int j = i + 1; j <= arr[i] + i && j < cnt.size(); j++)
			{
				int n = cnt[i] + 1;
				if (n < cnt[j] || cnt[j] == 0)
					cnt[j] = n;
			}
		}
	}

	if (cnt.back() != 0)
		return cnt.back();
	return -1;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int ret = Judge(arr);
	cout << ret << endl;

	return 0;
}