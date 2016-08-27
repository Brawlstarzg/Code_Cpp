/*
 * ���ֵ�����s1��s2֮��ģ�������len1��len2���ַ����ĸ��������mod 1000007��
 * ��������:
 * ÿ�����ݰ���s1������С��100����s2������С��100����len1��С��100000����len2������len1��С��100000��
 */

#include <stdio.h>
#include <string.h>

int StrToInt(const char *str)
{
	int ret = 0;
	const char *tmp = str;
	while (*tmp != '\0')
	{
		ret = ret * 26 + (*tmp) - 'a';
		tmp++;
	}

	return ret;
}

int StringNums(char *str1, char *str2, int len1, int len2)
{
	if (len1 > len2 || str1 == NULL || str2 == NULL)
		return 0;
	int l1 = strlen(str1);
	int l2 = strlen(str2);

	if (len1 > l1)
	{
		int i = l1;
		while (i < len1)
		{
			str1[i++] = 'a';
		}
		str1[i] = '\0';
	}
	if (len2 > l2)
	{
		int i = l2;
		while (i < len2)
		{
			str2[i++] = 'a';
		}
		str2[i] = '\0';
	}

	int IntStr1 = StrToInt(str1);
	int IntStr2 = StrToInt(str2);

	return (IntStr2 - IntStr1 - 1) % 1000007;
}

int main()
{
	char str1[100];
	char str2[100];
	int len1, len2;

	while (scanf("%s%s%d%d", str1, str2, &len1, &len2) != EOF)
	{
		int ret = StringNums(str1, str2, len1, len2);
		printf("%d\n", ret);
	}

	return 0;
}