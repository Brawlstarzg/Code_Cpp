/*
 * ��һ����Ϊn������A��������0��a��b<n��A[b]-A[a]�����ֵ��
 * ��������A�����Ĵ�Сn���뷵������ֵ��
 */

class LongestDistance
{
public:
	int getDis(vector<int> A, int n)
	{
		// write code here
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			int m = A[i];
			for (int j = i + 1; j < n; j++)
			{
				if (A[j] > m)
					m = A[j];
			}
			if (m - A[i] > max)
				max = m - A[i];
		}
		return max;
	}
};