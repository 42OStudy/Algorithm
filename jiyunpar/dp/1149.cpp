#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int> > dp(2000, vector<int>(3, 0));
	vector<vector<int> > cost;
	cost.reserve(2000);
	for (int i = 1; i <= n; ++i)
	{
		vector<int> val;
		val.resize(3);
		for (int j = 0; j < 3; ++j)
		{
			cin >> val[j];
		}
		cost[i] = val;
	}
	dp[1][0] = cost[1][0];
	dp[1][1] = cost[1][1];
	dp[1][2] = cost[1][2];
	for (int i = 2; i <= n; ++i)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
	}
	cout << min({ dp[n][0], dp[n][1], dp[n][2] });
	return 0;
}
// int main(void)
// {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
// 	int n;
// 	cin >> n;
// 	vector<vector<int> > cost;
// 	cost.reserve(1000);
// 	vector<int> dp;
// 	dp.resize(1000, 4000);
// 	for (int i = 0; i < n; ++i)
// 	{
// 		vector<int> val;
// 		val.resize(3, 0);
// 		for (int j = 0; j < 3; ++j)
// 		{
// 			cin >> val[j];
// 		}
// 		cost.push_back(val);
// 	}
// 	int get_second;
// 	int second_min = 4000;
// 	int color;
// 	for (int i = 0; i < 3; ++i)
// 	{
// 		for (int j = 0; j < 3; ++j)
// 		{
// 			if (i != j)
// 			{
// 				get_second = cost[0][i] + cost[1][j];
// 				if (second_min > get_second)
// 				{
// 					second_min = get_second;
// 					cout << second_min << '\n';
// 					color = j;
// 				}	
// 			}
// 		}
// 	}
// 	dp[1] = second_min;
// 	for (int i = 2; i < n; ++i)
// 	{
// 		for (int j = 0; j < 3; ++j)
// 		{
// 			if (j != color)
// 			{
// 				if (dp[i - 1] + cost[i][j] < dp[i])
// 				{
// 					dp[i] = dp[i - 1] +cost[i][j];
// 					color = j;
// 				}
// 			}
// 		}
// 	}
// 	cout << dp[n - 1];
// 	return (0);
// }