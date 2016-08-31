/*
 * ��Ŀ����
 * ����һ���ַ�����������ַ����������ַ�����
 * ��������:
 * ÿ����������һ���ַ������ַ�����󳤶�Ϊ100����ֻ������ĸ��������Ϊ�մ������ִ�Сд��
 * �������:
 * ÿ������һ�У����ַ���ԭ�е��ַ�˳������ַ����ϣ����ظ����ֲ��������ĸ�������
 */

#include <stdio.h>
#include <string.h>

void CharSet(char *buf)
{
	int set[52];
	memset(set, 0, 52 * sizeof(set[0]));

	char *str = buf;
	while ('\0' != *str)
	{
		if (*str >= 'a')
			set[*str - 'a' + 26]++;
		else
			set[*str - 'A']++;
		str++;
	}

	for (int i = 0; buf[i] != '\0'; i++)
	{
		int index;
		if (buf[i] >= 'a')
			index = buf[i] - 'a' + 26;
		else
			index = buf[i] - 'A';

		if (set[index] > 0)
		{
			printf("%c", buf[i]);
			set[index] = 0;
		}
	}
	printf("\n");

}

int main()
{
	char buf[101];
	while (scanf("%s", buf) != EOF)
	{
		CharSet(buf);
	}


	return 0;
}