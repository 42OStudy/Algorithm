#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int	N;

void	get_input()
{
	cin >> N;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	vector<int> primes;

	int start = 1;
	int backup = N;
	for (int i = 2; i <= N / i; ++i) 
	{
		while (N % i == 0)
		{
			primes.push_back(i);
			N /= i;
		}
	}
	if (N != 1)
		primes.push_back(N);
	for (int i = 0; i < primes.size(); ++i) 
		cout << primes[i] << '\n';
}
