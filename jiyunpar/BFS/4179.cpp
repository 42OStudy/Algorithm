// 서로다른 종류의 BFS를 돌리는 경우
// 단, 각각의 BFS가 서로 독립적이다(하나의 결과가 다른 것이 BFS를 돌 때 영향을 주지 않는다.)
#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring> // memset

using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int r, c;
string board[1000];
int fire[1000][1000];
int pos[1000][1000];
queue<pair<int, int> > F;
queue<pair<int, int> > P;

void get_input(void)
{
	cin >> r >> c;
	memset(fire, -1, sizeof(fire));
	memset(pos, -1, sizeof(pos));
	for (int i = 0; i < r; ++i)
		cin >> board[i];
	for (int i= 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (board[i][j] == 'F')
			{
				fire[i][j] = 0;
				F.push({i, j});
			}
			if (board[i][j] == 'J')
			{
				pos[i][j] = 0;
				P.push({i, j});
			}
		}
	}
}

void bfs_fire(void)
{
	while (!F.empty())
	{
		auto cur = F.front();
		F.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
				continue ;
			if (fire[nx][ny] >= 0 || board[nx][ny] == '#')
				continue ;
			fire[nx][ny] = fire[cur.X][cur.Y] + 1;
			F.push({nx, ny});
		}
	}
	#ifndef ONLINE_JUDGE
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
				cout << fire[i][j];
			cout << '\n';
		}
	#endif
}

void bfs_pos(void)
{
	while (!P.empty())
	{
		auto cur = P.front();
		P.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
			{
				cout << pos[cur.X][cur.Y] + 1;
				return ;
			}
			if (pos[nx][ny] >= 0 || board[nx][ny] == '#')
				continue ;
			if (fire[nx][ny] != -1 && pos[cur.X][cur.Y] + 1 >= fire[nx][ny])
				continue ;
			pos[nx][ny] = pos[cur.X][cur.Y] + 1;
			P.push({nx, ny});
		}
	}
	#ifndef ONLINE_JUDGE
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
				cout << pos[i][j];
			cout << '\n';
		}
	#endif
	cout << "IMPOSSIBLE";
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	get_input();
	bfs_fire();
	bfs_pos();
	return (0);
}
// fire를 -1로 초기화 한 상황에서 불이 없으면 전체가 -1임
// 불이 아예 없는 경우를 생각하지 못하여 오래 걸렸음
// 반례를 생각할 때 조건 중 무언가 없을 때를 생각해볼 필요가 있음