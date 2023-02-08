#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
using namespace std;

int N;
int score[301];
int dp[301];

void	get_input()
{
	cin >> N;
	for (int i = 1; i <= N; ++i) 
		cin >> score[i];
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	dp[1] = score[1];
	dp[2] = score[1] + score[2];
	for (int i = 3; i <= N; ++i) 
		dp[i] = max(dp[i - 3] + score[i - 1] + score[i], dp[i - 2] + score[i]);
	cout << dp[N];
}

//#include <iostream>
//#include <stack>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#include <utility>
//#include <string.h>
//using namespace std;
//
//int N;
//int score[301];
//int dp[301][3];
//
//void	get_input()
//{
//	cin >> N;
//	for (int i = 1; i <= N; ++i) 
//		cin >> score[i];
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	get_input();
//	dp[1][1] = score[1];
//	dp[2][1] = score[2];
//	dp[1][2] = score[1];
//	dp[2][2] = score[1] + score[2];
//	for (int i = 3; i <= N; ++i) 
//	{
//		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + score[i];
//		dp[i][2] = dp[i - 1][1] + score[i];
//	}
//	cout << max(dp[N][1], dp[N][2]);
//}
