//15 + 20 + 10
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int R, C;
string maze[1000];
queue<pair<int, int>> jihun;
queue<pair<int, int>> fire;
int fire_dist[1000][1000];
int jihun_dist[1000][1000];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};

void get_input()
{
	memset(jihun_dist, -1, sizeof(jihun_dist));
	memset(fire_dist, -1, sizeof(fire_dist));
	cin >> R >> C;
	for (int i = 0; i < R; ++i) 
	{
		cin >> maze[i];
	}
	for (int i = 0; i < R; ++i) 
	{
		for (int j = 0; j < C; ++j) 
		{
			if (maze[i][j] == 'J')
			{
				jihun.push({i, j});
				jihun_dist[i][j] = 0;
			}
			else if (maze[i][j] == 'F')
			{
				fire.push({i, j});
				fire_dist[i][j] = 0;
			}
		}
	}
}
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	get_input();
	while (!fire.empty())
	{
		auto cur = fire.front();
		fire.pop();
		
		for (int dir = 0; dir < 4; ++dir) 
		{
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];

			if (ny < 0 || ny >= R || nx < 0 || nx >= C)
				continue ;
			if (maze[ny][nx] == '#' || fire_dist[ny][nx] != -1)
				continue ;
			fire_dist[ny][nx] = fire_dist[cur.first][cur.second] + 1;
			fire.push({ny, nx});
		}
	}
	#ifndef ONLINE_JUDGE
	cout << "fire_dist\n";
	for (int i = 0; i < R; ++i) 
	{
		for (int j = 0; j < C; ++j) 
		{
			cout << fire_dist[i][j] << ' ';
		}
		cout << '\n';
	}
	#endif
	int shortest_time = 0;
	bool is_escape = false;
	while (!jihun.empty())
	{
		auto cur = jihun.front();
		jihun.pop();
		if (cur.first == 0 || cur.first == R - 1 || cur.second == 0 || cur.second == C - 1)
		{
			shortest_time = jihun_dist[cur.first][cur.second] + 1;
			is_escape = true;
			break ;
		}
		for (int dir = 0; dir < 4; ++dir) 
		{
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];

			if (maze[ny][nx] == '#' || jihun_dist[ny][nx] != -1)
				continue ;
			if (fire_dist[ny][nx] != -1 && jihun_dist[cur.first][cur.second] + 1 >= fire_dist[ny][nx])
				continue ;
			jihun_dist[ny][nx] = jihun_dist[cur.first][cur.second] + 1;
			jihun.push({ny, nx});
		}
	}
	#ifndef ONLINE_JUDGE
	cout << "jihun_dist\n";
	for (int i = 0; i < R; ++i) 
	{
		for (int j = 0; j < C; ++j) 
		{
			cout << jihun_dist[i][j] << ' ';
		}
		cout << '\n';
	}
	#endif
	if (is_escape)
		cout << shortest_time;
	else
		cout << "IMPOSSIBLE";
}
// 반례를 안봤으면 맞출 수 있었을까?
// 불이 아예 없었을 떄 0으로 초기화되었기 때문에 지훈은 갈 수가 없었음.
// 해당 경우로 종료된 경우, ++로 갯수를 카운트 했다면 벽에 다가가기 전에 다른 곳을 들린다면 갯수가 +1 이 되어 오답이 됨
