#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

#define X first
#define Y second

int board[1000][1000];
int day[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> m >> n;
	// input
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];
	}
	// day initialize
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			day[i][j] = -1;
	}
	// save tomato position & day value initialize 
	queue<pair<int, int> > Q;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j] == 1)
			{
				Q.push({i, j});
				day[i][j] = 0;
			}
		}
	}
	// do bfs
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
			if (day[nx][ny] != -1 || board[nx][ny] == -1)
				continue ;
			day[nx][ny] = day[cur.X][cur.Y] + 1;
			Q.push({nx, ny});
		}
	}
	//get answer	
	int max = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (day[i][j] == -1 && board[i][j] == 0)
			{
				cout << -1;
				return (0);
			}
			if (max < day[i][j])
				max = day[i][j];
		}
	}
	cout << max;

#ifndef ONLINE_JUDGE
	cout << '\n';
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << day[i][j];
		}
		cout << '\n';
	}
#endif
	
	return (0);
}