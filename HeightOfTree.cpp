/*
 * ������һ�úϷ��Ķ����������Ľڵ㶼�������ֱ�ʾ�����ڸ�������������еĸ��ӹ�ϵ����������ĸ߶�
 * ����
 * ����ĵ�һ�б�ʾ�ڵ�ĸ���n��1<=n<=1000���ڵ�ı��Ϊ0��n-1����ɣ�
 * ������n-1�У�ÿ����������������һ������ʾ���ڵ�ı�ţ��ڶ�������ʾ�ӽڵ�ı��
 * ���
 * ������ĸ߶ȣ�Ϊһ������
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> father(n - 1);
	vector<int> child(n - 1);
	for (int i = 0; i < n - 1; i++)
	{
		cin >> father[i] >> child[i];
	}

	vector<int> height(n);
	height[0] = 1;
	for (int i = 0; i < n-1; i++)
	{
		height[i+1] = height[father[i]] + 1;
	}
	int max = height[0];
	for (int i = 1; i < n; i++)
		if (max < height[i])
			max = height[i];
	cout << max << endl;

	return 0;
}