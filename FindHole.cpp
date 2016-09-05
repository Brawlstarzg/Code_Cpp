/*
 * ��Ŀ����
 * һֻ���Ӳ�����20��Բ�����еĶ��У�����1��ʼ��ţ���һֻ�Ǵ�x�Ŷ���ʼ��,�´θ�һ������(����x��2�Ŷ���)��
 * ���´θ���������(����x��5�Ŷ���)��������n����Ȼû���ҵ��������ӿ�������Щ���С�
 * ��������:
 * �����ж������ݣ�ÿ������һ�����������ֱ�Ϊx��n(x <= 20,n <= 100000)
 * �������:
 * ÿ������һ�а���С�����˳��������ӿ����ڵĶ�������֮���ÿո��������ÿ�����������ܲ������ӣ����-1��
 */

#include <stdio.h>
#include <string.h>

void FindHole(int x, int n)
{
	char arr[20];
	memset(arr, 0, sizeof(arr));

	for (int i = 0; i < n; i++)
	{
		x %= 20;
		arr[x]++;
		x += i + 2;
	}

	int cnt = 0;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (arr[i] == 0)
		{
			printf("%d ", i + 1);
			cnt++;
		}
	}
	if (cnt == 0)
		printf("-1\n");
	else
		printf("\n");
}

int main()
{
	int x, n;
	while (scanf("%d%d", &x, &n) != EOF)
	{
		x--;
		FindHole(x, n);
	}

	return 0;
}