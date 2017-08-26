#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int> PRIME_ARRAY;

bool isPrime(int n)
{
	if (n != 2 && n % 2 == 0 || n < 2)
	{
		return false;
	}
	for (int i = 3; i <= sqrt(n); i += 2)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int input;
	cin >> input;
	for (int i = 2; i <= input; i++)
	{
		if (isPrime(i))
			PRIME_ARRAY.push_back(i);
	}

	int s, e, sum;
	s = 0;
	e = 0;
	sum = 0;
	int result = 0;
	while (1)
	{
		
		if (sum >= input) //������Ʈ �����߿�
		{
			sum = sum - PRIME_ARRAY[s++];
		}
		else if (e == PRIME_ARRAY.size())//�����߿�
			break;
		else if (sum < input)//�����߿�
		{
			sum = sum + PRIME_ARRAY[e++];
		}

		if (sum == input)	//���Ǹ��� �κ���
		{
			result++;
		}
	}

	cout << result << '\n';
}