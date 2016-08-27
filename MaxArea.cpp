/*
 * ��һ��ֱ��ͼ����һ�����������ʾ������ÿ�еĿ��Ϊ1��������ֱ��ͼ�����������������
 * ���磬����ֱ��ͼ[2,7,9,4],���������������ε����Ϊ14(��[7,9]������7x2�ľ���)��
 * ����һ��ֱ��ͼA�������ܿ��n���뷵���������������ֱ֤��ͼ���С�ڵ���500����֤�����int��Χ�ڡ�
 */

class MaxInnerRec
{
public:
	int countArea(vector<int> A, int n)
	{
		// write code here
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				int height = MinHeight(A, i, j);
				int area = height * (j - i + 1);
				if (area > max)
					max = area;
			}
		}
		return max;
	}

	int MinHeight(vector<int> &A, int i, int j)
	{
		int min = A[i];
		for (int k = i + 1; k <= j; k++)
		{
			if (A[k] < min)
				min = A[k];
		}
		return min;
	}
};