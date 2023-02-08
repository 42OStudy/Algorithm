#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int X;
int dp[1000000];
int path[1000000];

void	get_input()
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
	path[0] = 0;
	path[1] = 0;
	for (int i = 2; i <= X; ++i) 
	{
		dp[i] = dp[i - 1] + 1;
		path[i] = i - 1;
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
		{
			dp[i] = dp[i / 3] + 1;
			path[i] = i / 3;
		}
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
		{
			dp[i] = dp[i / 2] + 1;
			path[i] = i / 2;
		}
	}
	int end = X;
	cout << dp[X] << '\n';
	cout << end << ' ';
	while (end != 1)
	{
		cout << path[end] << ' ';
		end = path[end];
	}
}

//dp[i] = min({dp[i - 1], three, two}) + 1;
//처음엔 이런식으로 해줬는데, dp에 따라서 갱신해야할 path값이 다르기 때문에 하나하나 나누어야 함.


//1. 10^6이 100만이 아니라 10만인줄 알았다.
//2. 10 9 3 1로 저장하고 싶은데, 10 9 8 1 로 덮어쓰여지는 문제 
//int X;
//int is_visited[1000001];
//int path[1000001];
//int number[1000001];
//
//void	get_input()
//{
//	cin >> X;
//}
//
//void	bfs()
//{
//	queue<pair<int, int>> Queue;
//	stack<int> Stack;
//
//	int end = X;
//	is_visited[X] = true;
//	path[X] = X;
//	Queue.push({X, 0});
//	
//
//	while (!Queue.empty())
//	{
//		auto cur = Queue.front();
//		int num = cur.first;
//		int cnt = cur.second;
//
//		Queue.pop();
//		if (num == 1)
//		{
//			cout << cnt << '\n';
//			int Start = 1;
//			while (Start != end)
//			{
//				Stack.push(Start);
//				Start = path[Start];
//			}
//			while (!Stack.empty())
//			{
//				cout << path[Stack.top()] << ' ';
//				Stack.pop();
//			}
//			cout << 1;
//			break ;
//		}
//		if (num % 3 == 0 && !is_visited[num / 3])
//		{
//			path[num / 3] = num;
//			is_visited[num / 3] = true;
//			Queue.push({num / 3, cnt + 1});
//		}
//		if (num % 2 == 0 && !is_visited[num / 2])
//		{
//			path[num / 2] = num;
//			is_visited[num / 2] = true;
//			Queue.push({num / 2, cnt + 1});
//		}
//		if (num - 1 >= 0 && !is_visited[num - 1])
//		{
//			path[num - 1] = num;
//			is_visited[num - 1] = true;
//			Queue.push({num - 1, cnt + 1});
//		}
//	}
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	get_input();
//	bfs();
//}

/* dfs
 */

//#include <iostream>
//#include <stack>
//#include <queue>
//#include <vector>
//#include <utility>
//#include <algorithm>
//#include <string.h>
//using namespace std;
//
//int X;
//int path[1000001];
//int numbers[1000001];
//int ans = 0x7fffffff;
//
//void	get_input()
//{
//	cin >> X;
//}
//
//void	dfs(int x, int cnt)
//{
//	if (cnt > ans)
//		return ;
//	if (x == 1)
//	{
//		if (cnt < ans)
//		{
//			ans = cnt;
//			for (int i = 0; i < cnt; ++i) 
//				path[i] = numbers[i];
//		}
//		return ;
//	}
//	numbers[cnt] = x;
//	if (x % 3 == 0)
//		dfs(x / 3, cnt + 1);
//	if (x % 2 == 0)
//		dfs(x / 2, cnt + 1);
//	if (x - 1 >= 0)
//		dfs(x - 1, cnt + 1);
//}
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	get_input();
//	dfs(X, 0);
//	cout << ans << '\n';
//	for (int i = 0; i < ans; ++i)
//	{
//		cout << path[i] << ' ';
//	}
//	cout << 1;
//}
/*
 * 잘못된 dfs풀이
 */
// dfs, 당연 시간초과, 시간초과 안나게도 풀 수가 있네? 현재까지 본 가장 짧은 깊이보다 깊이가 커진다면 더 탐색하지 않고 종료하면 시간초과를 막을 수 있음.
// dfs를 풀 때 visited배열은 필요가 없다. 최대 깊이부터 들어가기에 매번 중복여부를 따질 필요가 없음.
//int X;
//int ans = 0x7fffffff;
//int number[1000001];
//bool is_visited[1000001];
//
//void	get_input()
//{
//	cin >> X;
//	is_visited[X] = true;
//}
//
//void	dfs(int X, int cnt)
//{
////	cout << "cnt: " << cnt << " X: " << X << '\n';
//	if (X == 1)
//	{
//		ans = min(ans, cnt);
//		number[cnt] = 1;
//		return ;
//	}
//	if (X % 3 == 0 && !is_visited[X / 3])
//	{
//		is_visited[X / 3] = true;
//		number[cnt] = X;
//		dfs(X / 3, cnt + 1);
//		is_visited[X / 3] = false;
//	}
//	if (X % 2 == 0 && !is_visited[X / 2])
//	{
//		is_visited[X / 2] = true;
//		number[cnt] = X;
//		dfs(X / 2, cnt + 1);
//		is_visited[X / 2] = false;
//	}
//	if (X - 1 >= 0 && !is_visited[X - 1])
//	{
//		is_visited[X - 1] = true;
//		number[cnt] = X;
//		dfs(X - 1, cnt + 1);
//		is_visited[X - 1] = false;
//	}
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	get_input();
//	dfs(X, 0);
//	cout << ans << '\n';
//	for (int i = 0; number[i]; ++i) 
//		cout << number[i] << ' ';
//}
