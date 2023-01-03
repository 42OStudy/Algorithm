#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> dp;
	vector<int> prev;
	dp.resize(1000000, 0);
	prev.resize(1000000, 0);
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	prev[1] = 0;
	prev[2] = 1;
	prev[3] = 1;
	for (int i = 4; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + 1;
		prev[i] = i - 1;
		if (i % 3 == 0)
		{
			if (dp[i / 3] < dp[i])
			{
				dp[i] = dp[i / 3] + 1;
				prev[i] = i / 3;
			}
		}
		if (i % 2 == 0)
		{
			if (dp[i / 2] < dp[i])
			{
				dp[i] = dp[i / 2] + 1;
				prev[i] = i / 2;
			}
		}
	}
	cout << dp[n] << '\n';
	int i = n;
	if (n == 1)
	{
		cout << 0;
		return (0);
	}
	cout << n << ' ';
	while (prev[i] != 1)
	{
		cout << prev[i] << ' ';
		i = prev[i];
	}
	cout << 1;
	return (0);
}