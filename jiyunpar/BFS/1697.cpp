// 일차원 배열에서 bfs
#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int r[3] = {2, 1, 1};
int m[3] = {0, 1, -1};

int ans[100001];
int n, k;
queue<int> Q;
void get_input(void)
{
	memset(ans, -1, sizeof(ans));
	cin >> n >> k;
	ans[n] = 0;
	Q.push(n);
}

void bfs(void)
{
	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		for (int i = 0; i < 3; ++i)
		{
			int nx = r[i] * cur + m[i];
			if (nx < 0 || nx >= 100001)
				continue ;
			if (ans[nx] != -1)
				continue ;
			ans[nx] = ans[cur] + 1;
			Q.push(nx);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	get_input();
	bfs();
	#ifndef ONLINE_JUDGE
	for (int i = 0; i < 20; ++i)
		cout << ans[i] << ' ';
	#endif
	cout << ans[k];
	return (0);
}