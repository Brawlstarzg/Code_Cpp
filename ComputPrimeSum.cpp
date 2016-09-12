#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

// �ж��Ƿ�Ϊ����
bool IsPrime(int n)
{
	int end = sqrt(n);
	for (int i = 2; i <= end; i++)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

// [left, right]
// ��������֮�������ĸ���
int PrimerNumsInTwoNum(int left, int right)
{
	int cnt = 0;
	for (int i = left; i <= right; i++)
	{
		if (IsPrime(i))
			cnt++;
	}

	return cnt;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n, 0);

	int flag = false;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	// ����ÿ���ڵ�������֮�������ĸ���
	for (int i = 1; i < n; i++)
	{
		arr[i - 1] = PrimerNumsInTwoNum(arr[i - 1], arr[i]);
	}

	int sum = 0;
	int tmp;
	for (int i = 0; i < n - 1; i++)
	{
		tmp = 0;
		for (int j = i; j < n - 1; j++)
		{
			tmp += arr[j];
			sum += tmp;
		}
	}
	cout << sum << endl;

	return 0;
}
