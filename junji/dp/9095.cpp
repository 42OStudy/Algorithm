#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int dp[11];
int T, n;

void	get_input()
{
	cin >> T;
	while (T--)
	{
		cin >> n;
		cout << dp[n] << '\n';
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 10; ++i) 
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	get_input();
}

