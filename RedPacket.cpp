/*
 * ��Ŀ����
 * �����ڼ�С��ʹ��΢���յ��ܶ��������ǳ����ġ��ڲ鿴��ȡ�����¼ʱ���֣�ĳ����������ֵĴ�������
 * �˺��������һ�롣���С���ҵ��ú����д�������㷨˼·�ʹ���ʵ�֣�Ҫ���㷨�����ܸ�Ч��
 * ����һ������Ľ������gifts�����Ĵ�Сn���뷵���������Ľ�
 * ��û�н���������һ�룬����0�� 
 */

class Gift
{
public:
	int getValue(vector<int> gifts, int n)
	{
		// write code here
		if (n <= 0)
			return 0;

		int num = gifts[0];
		int cnt = 1;
		for (int i = 1; i < gifts.size(); i++)
		{
			if (num == gifts[i])
			{
				cnt++;
			}
			else
			{
				cnt--;
				if (cnt == 0)
				{
					num = gifts[i];
					cnt = 1;
				}
			}
		}
		cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (gifts[i] == num)
				cnt++;
		}
		if (cnt > n / 2)
			return num;
		return 0;
	}

};