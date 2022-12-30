#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);	
	vector<int> step;
	vector<int> dp;
	// vector<int> prev;
	step.resize(400, 0);
	dp.resize(400, 0);
	// prev.resize(400, 0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> step[i];
	dp[1] = step[1];
	dp[2] = step[1] + step[2];
	for (int i = 3; i <= n; ++i)
		dp[i] = max(dp[i - 3] + step[i - 1] + step[i], dp[i - 2] + step[i]);
	// for (int i = 4; i <= n; ++i)
	// {
	// 	if (prev[i - 1] == i - 2)
	// 	{
	// 		dp[i] = dp[i - 2] + step[i];
	// 		prev[i] = i - 2;
	// 	}
	// 	else
	// 	{
	// 		if (dp[i - 1] > dp[i - 2])
	// 		{
	// 			dp[i] = dp[i - 1] + step[i];
	// 			prev[i] = i - 1;
	// 		}
	// 		else
	// 		{
	// 			dp[i] = dp[i - 2] + step[i];
	// 			prev[i] = i - 2;
	// 		}
	// 	}
	// }
	// for (int i = 0; i <= n; ++i)
	// 	cout << step[i] << ' ';
	// cout << '\n';
	// for (int i = 0; i <= n; ++i)
	// 	cout << dp[i] << ' ';
	// cout << '\n';
	// for (int i = 0; i <= n; ++i)
	// 	cout << prev[i] << "  ";
	// cout << '\n';
	cout << dp[n];
	return (0);
}