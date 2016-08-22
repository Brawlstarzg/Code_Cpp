/*
 * �˿�����Ϸ���Ӧ�ö��Ƚ���Ϥ�ˣ�һ������54����ɣ���3~A��2��4�ţ�С��1�ţ�����1�š�
 * �����С�����������ַ����ַ�����ʾ�����У�Сдjoker��ʾС������дJOKER��ʾ������:)
 * 3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
 * ���������ƣ�������֮���á�-�����ӣ�ÿ���Ƶ�ÿ�����Կո�ָ�����-������û�пո��磺4 4 4 4-joker JOKER
 * ��Ƚ������ƴ�С������ϴ���ƣ���������ڱȽϹ�ϵ�����ERROR
 * ��������
 * ��1������ÿ���ƿ����Ǹ��ӣ����ӣ�˳�ӣ�����5�ţ���������ը�����ĸ����Ͷ����е�һ�֣����������������
 *�������뱣֤�����ƶ��ǺϷ��ģ�˳���Ѿ���С�������У�
 * ��2������ը���Ͷ������Ժ������ƱȽ�֮�⣬�������͵���ֻ�ܸ���ͬ���͵Ĵ��ڱȽϹ�ϵ���磬���Ӹ����ӱȽϣ������������Ƚϣ���
 ���������ǲ���������磺�����Ӳ�ֳɸ��ӣ�
 * ��3����С��������ƽʱ�˽�ĳ���������ͬ�����ӣ����ӣ������Ƚ������С��˳�ӱȽ���С�ƴ�С��ը������ǰ�����е��ƣ�
 ����ը��֮��Ƚ������С�������������ƣ�
 * ��4������������Ʋ��������ȵ������
 * ����ʾ��
 * ��1������ը���Ͷ���֮�⣬��������ͬ���ͱȽϡ�
 * ��2�������Ѿ���֤�Ϸ��ԣ����ü�������Ƿ��ǺϷ����ơ�
 * ��3�������˳���Ѿ�������С����������˲�����������.
 * ��������:
 * ���������ƣ�������֮���á�-�����ӣ�ÿ���Ƶ�ÿ�����Կո�ָ�����-������û�пո���4 4 4 4-joker JOKER��
 * �������:
 * ����������нϴ�����֣��������ӷ����˿���˳�򲻱䣬���Կո��������������ڱȽϹ�ϵ�����ERROR��
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <strings.h>

using namespace std;

int num(const char *buf)
{
	if (buf[1] != '\0')
	{
		if (buf[1] == '0' && *buf == '1')
			return 10;
	}
	if (*buf == 'J')
		return 11;
	else if (*buf == 'Q')
		return 12;
	else if (*buf == 'K')
		return 13;
	else if (*buf == 'A')
		return 14;
	else if (*buf == '2')
		return 15;
	else if (*buf == 'j' || *buf == 'J')
		return 16;
	else
		return *buf - '0';
}

int judge_num(const char *buf)
{
	const char *str = buf;
	// ����
	// 3~16
	int len = strlen(buf);
	if ((len == 5 && (strcasecmp(buf, "joker") == 0)) ||
		(len == 1) ||
		(*buf == '1' && buf[1] == '0')
		)
	{
		return num(buf);
	}

	// ����
	// 23~35
	if (len == 3 || (len == 5 && buf[0] == '1' && buf[1] == '0'))
		return num(buf) + 20;

	// ����
	// 53~55
	if (len == 5 || (len == 8 && buf[0] == '1' && buf[1] == '0'))
		return num(buf) + 50;

	// ˳��
	// 103~115
	if (len >= 9 && (strcasecmp(buf, "joker joker") != 0))
		return num(buf) + 100;

	// ը��
	// 503~1000
	return num(buf) + 500;

	// ����
	return 1000;
}

bool IsIn(int left, int right)
{
	if (left < 20 && right < 20)
		return true;
	if (left < 50 && right < 50)
		return true;
	if (left < 100 && right < 100)
		return true;
	if (left < 500 && right < 500)
		return true;
	if (left > 500 || right > 500)
		return true;
	return false;
}


void call()
{
	char buf1[15];
	char buf2[15];
	memset(buf1, '\0', 15);
	memset(buf2, '\0', 15);
	int index1 = 0;
	int index2 = 0;
	int ch;
	bool flag = true;
	while ((ch = getchar()) != '\n')
	{
		if (ch == '-')
		{
			flag = false;
			continue;
		}
		if (flag)
			buf1[index1++] = ch;
		else
			buf2[index2++] = ch;
	}

	int left = judge_num(buf1);
	int right = judge_num(buf2);

	if (IsIn(left, right))
	{
		if (left > right)
			printf("%s\n", buf1);
		else
			printf("%s\n", buf2);
	}
	else
		printf("ERROR\n");
}

int main()
{
	call();

	return 0;
}