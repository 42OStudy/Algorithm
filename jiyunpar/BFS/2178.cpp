#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

#define X first
#define Y second

int n, m;
string board[100];
int dis[100][100];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> board[i];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			dis[i][j] = -1;
	}
	queue<pair<int, int> > Q;
	dis[0][0] = 0;
	Q.push({0, 0});
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue ;
			if (dis[nx][ny] != -1 || board[nx][ny] == '0')
				continue ;
			dis[nx][ny] = dis[cur.X][cur.Y] + 1;
			Q.push({nx, ny});
		}
	}
	cout << dis[n - 1][m - 1] + 1;
	return (0);
}