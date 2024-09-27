#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int N, K;
int comb[1001][1001];
int mod = 10007;

void	get_input()
{
	cin >> N >> K;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; i <= 1000; ++i) 
	{
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; ++j) 
		{
			comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
		}
	}
	get_input();
	cout << comb[N][K];
}
