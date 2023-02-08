//646
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>

using namespace std;

int box[1000][1000];
int dist[1000][1000];
queue<pair<int, int>> Queue;
int M, N;

void get_input()
{
	cin >> M >> N;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < M; ++j) 
		{
			cin >> box[i][j];
			if (box[i][j] == 1)
			{
				Queue.push({i, j});
				dist[i][j] = 0;
			}
		}
	}
}

void bfs()
{
	int dy[] = {1, -1, 0, 0};
	int dx[] = {0, 0, -1, 1};

	while (!Queue.empty())
	{
		auto cur = Queue.front();
		Queue.pop();

		for (int dir = 0; dir < 4; ++dir) 
		{
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue ;
			if (box[ny][nx] != 0 || dist[ny][nx] != -1)
				continue ;
			dist[ny][nx] = dist[cur.first][cur.second] + 1;
			Queue.push({ny, nx});
		}
	}
	#ifndef ONLINE_JUDGE
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < M; ++j) 
		{
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
	#endif
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	memset(dist, -1, sizeof(dist));
	get_input();
	bfs();

	bool is_error = false;
	int max_day = 0;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < M; ++j) 
		{
			if (box[i][j] == 0 && dist[i][j] == -1)
			{
				is_error = true;
				break ;
			}
			max_day = max(max_day, dist[i][j]);
		}
	}
	if (is_error)
		cout << "-1";
	else 
		cout << max_day;
}
