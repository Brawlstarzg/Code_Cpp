/*
 * C������Ҫת��һ���ﷸ��D�У�C����n���ﷸ����������ʱ����˳������ÿ���ﷸ��һ������ֵ��ֵԽ����Խ�ء�
 * ����Ϊ�˷�������г�����ת������ʱ��������c�����ˣ�ͬʱҪ��ת�Ʒ��˵�����ֵ֮�Ͳ�����t�����ж�����ѡ��ķ�ʽ��
 * ��������:
 * ��һ��������������:n��t��c(1��n��2e5,0��t��1e9,1��c��n)���ڶ��а�����ʱ�����ÿ�����˵�����ֵai(0��ai��1e9)
 * �������:
 * һ������𰸡�
 */

#include <stdio.h>

int MethodsNum(int crime[], int n, int t, int c)
{
	if (NULL == crime || n <= 0 || c > n)
		return 0;
	int first = 0, second = 0;
	int cnt = 0;
	int sum = 0;
	for (; second < c; second++)
	{
		sum += crime[second];
	}
	second--;

	while (second < n)
	{
		if (t >= sum)
		{
			cnt++;
		}

		sum -= crime[first++];
		if (++second > n)
			break;
		sum += crime[second];
	}

	return cnt;
}

int main()
{
	int n, t, c;
	int *crime;
	while (scanf("%d%d%d", &n, &t, &c) != EOF)
	{
		crime = new int[n];
		for (int i = 0; i < n; i++)
		{
			scanf("%d", crime + i);
		}
		int ret = MethodsNum(crime, n, t, c);
		printf("%d\n", ret);

		delete[] crime;
	}

	return 0;
}