#include <iostream>

using namespace std;

// nCk = n-1Ck-1 + n-1Ck

int dp[1005][1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		dp[i][0] = 1;
		dp[i][i] = 1;
		for (int j = 1; j <= i; ++j)
		{
			if (i == 1)
				break;
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
		}
	}
	cout << dp[n][k];
	return (0);

}