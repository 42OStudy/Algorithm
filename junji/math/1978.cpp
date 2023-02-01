#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int N;

bool	is_prime(int number)
{
	if (number == 1)
		return (false);
	for (int i = 2; i <= number / i; ++i) 
	{
		if (number % i == 0)
			return (false);
	}
	return (true);
}
void	get_input()
{
	cin >> N;
	int cnt = 0;
	for (int i = 0; i < N; ++i) 
	{
		int number;
		cin >> number;
		if (is_prime(number))
			++cnt;
	}
	cout << cnt;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
}
