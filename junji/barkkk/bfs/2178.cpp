//0610
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

string maze[100];
int dist[100][100];
int N, M;

void get_input()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i) 
	{
		cin >> maze[i];
	}
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	get_input();
	queue<pair<int, int>> Queue;
	int dy[] = {1, -1, 0, 0};
	int dx[] = {0, 0, -1, 1};

	Queue.push({0, 0});
	dist[0][0] = 1;
	
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
			if (dist[ny][nx] || maze[ny][nx] == '0')
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
	cout << dist[N - 1][M - 1];
}
