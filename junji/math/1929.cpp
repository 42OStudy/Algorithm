#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int M, N;

void	get_input()
{
	cin >> M >> N;
}

vector<int> find_primes(int M, int N)
{
	vector<int> primes;
	vector<bool> state(N + 1, true);
	state[1] = false;
	for (int i = 2; i * i <= N; ++i) 
	{
		for (int j = i * i; j <= N; j += i) 
			state[j] = false;
	}
	for (int i = M; i <= N; ++i) 
	{
		if (state[i])
			primes.push_back({i});
	}
	return primes;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	vector<int> primes;

	primes = find_primes(M, N);
	for (int i = 0; i < primes.size(); ++i) 
		cout << primes[i] << ' ';
}
