#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char input[1005];

int min_result = 2123456789;

int solution(string s) {

	min_result = 2123456789;
	char input[1005];
	strcpy(input, s.c_str());
	int str_len = strlen(input);

	for (int len = 1; len <= str_len; len++) //1.���ڿ� �ڸ� ���� ����
	{
		int result = 0;
		int count = 0; //��� ��Ī �����ߴ��� ���

		for (int cnt = 0; cnt < str_len / len; cnt++) //2.��ü ���ڿ����� ���° ���� �˻������� Ȯ��
		{
			if (cnt == 0) //ó������ prev������ ������ �ʴ´�
			{
				count++;
			}
			else //ó���̾ƴ϶�� prev������ ���ݰ��� ���Ѵ�
			{
				int flag = 0; //Ʋ���� �߰ߵǸ� 1�� �ȴ�.
				for (int cur = 0; cur < len; cur++)
				{
					if (input[cnt*len + cur] != input[(cnt - 1)*len + cur])
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					count++;
				}
				else
				{
					if (count == 1)
						result += len;
					else if (count < 10)
						result += len + 1;
					else if (count >= 10 && count < 100)
						result += len + 2;
					else if (count >= 100 && count < 1000)
						result += len + 3;
					count = 1;
				}
			}
		}
		if (count == 1)
			result += len;
		else if (count < 10)
			result += len + 1;
		else if (count >= 10 && count < 100)
			result += len + 2;
		else if (count >= 100 && count < 1000)
			result += len + 3;

		result += str_len % len;
		if (min_result > result)
			min_result = result;
	}

	return min_result;
}

int main()
{
	freopen("Text.txt", "r", stdin);
	string s;
	cin >> s;
	

	printf("%d\n", solution(s));
}

//TODO: �ٸ���� Ǯ�� �м� https://programmers.co.kr/learn/courses/30/lessons/60057/solution_groups?language=cpp&type=all