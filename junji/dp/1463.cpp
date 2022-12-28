#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int X;
int dp[1000001];

void get_input()
{
	cin >> X;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	dp[0] = 0;
	dp[1] = 0;
	for (int i = 2; i <= X; ++i) 
	{	
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
	}
	cout << dp[X];
}
/*
 * 점화식이 떠오르지 않아..
 * 테이블 정의하기
 * D[i] = i를 1로 만들기 위해 필요한 연산 사용 횟수의 최솟값?
 * 점화식 찾기
 * D[12]를 어떻게 구할까?
 * min(D[3] + 1, D[6] + 1, D[11] + 1);
 * 초기값 정하기
 * d[1] = 0;
 */
//bool visited[1000001];
//int X;
//
//void get_input()
//{
//	cin >> X;
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	get_input();
//	queue<pair<int, int>> Queue;
//	Queue.push({X, 0});
//	visited[X] = true;
//	while (!Queue.empty())
//	{
//		auto cur = Queue.front();
//		Queue.pop();
//
//		int number, count;
//		tie(number, count) = cur;
//		if (number == 1)
//		{
//			cout << cur.second;
//			return (0);
//		}
//		if (number % 3 == 0 && !visited[number % 3])
//		{
//			visited[number / 3] = true;
//			Queue.push({number / 3, count + 1});
//		}
//		if (number % 2 == 0 && !visited[number % 2])
//		{
//			visited[number / 2] = true;
//			Queue.push({number / 2, count + 1});
//		}
//		if (number - 1 >= 0 && !visited[number - 1])
//		{
//			visited[number - 1] = true;
//			Queue.push({number - 1, count + 1});
//		}
//	}
//}
