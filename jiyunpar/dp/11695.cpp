#include <iostream>
#include <vector>

using namespace std;


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> seq;
	seq.resize(n + 1);
	vector<int> dp;
	dp.resize(100001, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> seq[i];
	}
	dp[1] = seq[1];
	for (int i = 2; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + seq[i];
	}
	for (int i = 0; i < m; ++i)
	{
		int index, jndex;
		cin >> index >> jndex;
		cout << dp[jndex] - dp[index - 1] << '\n';
	}
	return (0);
}

// 시간 초과 생각 안하고 풀었음.... O(nm)
// int main(void)
// {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);

// 	int n, m;
// 	cin >> n >> m;
// 	vector<int> seq;
// 	seq.resize(n + 1);
// 	vector<int> dp;
// 	dp.resize(100001, 0);
// 	for (int i = 1; i <= n; ++i)
// 	{
// 		cin >> seq[i];
// 	}
// 	for (int i = 0; i < m; ++i)
// 	{
// 		int index, jndex;
// 		cin >> index >> jndex;
// 		dp[index] = seq[index];
// 		for (int j = index + 1; j <= jndex; ++j)
// 		{
// 			dp[j] = dp[j - 1] + seq[j];
// 		}
// 		cout << dp[jndex];
// 	}
// 	return (0);
// }