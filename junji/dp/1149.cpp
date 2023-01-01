#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
int house[1001][3];
int dp[1001][3];

void	get_input()
{
	cin >> N;
	for (int i = 1; i <= N; ++i) 
	{
		for (int j = 0; j < 3; ++j) 
		{
			cin >> house[i][j];
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	dp[1][0] = house[1][0];
	dp[1][1] = house[1][1];
	dp[1][2] = house[1][2];
	for (int i = 2; i <= N; ++i) 
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + house[i][2];
	}
	cout << min({dp[N][0], dp[N][1], dp[N][2]});
}
