#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int N, M, K;
int notebook[40][40];
int sticker[100][10][10];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};
vector<pair<int, int>> coord;

void get_input()
{
	cin >> N >> M >> K;
	for (int i = 0; i < K; ++i) 
	{
		int y, x;
		cin >> y >> x;
		coord.push_back({y, x});
		for (int j = 0; j < y; ++j) 
		{
			for (int k = 0; k < x; ++k) 
			{
				cin >> sticker[i][j][k];
			}
		}
	}
}

void rotate(int sequence)
{
	int temp[10][10];
	int height = coord[sequence].first;
	int width = coord[sequence].second;

	for (int i = 0; i < height; ++i) 
	{
		for (int j = 0; j < width; ++j) 
		{
			temp[i][j] = sticker[sequence][i][j];
		}
	}
	for (int i = 0; i < height; ++i) 
	{
		for (int j = 0; j < width; ++j) 
		{
			 sticker[sequence][j][height - 1 - i] = temp[i][j];
		}
	}
	swap(coord[sequence].first, coord[sequence].second);
}

bool is_connected(int sequence)
{
	int height = coord[sequence].first;
	int width = coord[sequence].second;
	int visited[10][10];
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>> Queue;
	bool is_pushed = false;
	for (int i = 0; i < height; ++i) 
	{
		if (is_pushed)
			break ;
		for (int j = 0; j < width; ++j) 
		{
			if (sticker[sequence][i][j] == 1)
			{
				Queue.push({i, j});
				is_pushed = true;
				break ;
			}
		}
	}
	while (!Queue.empty())
	{
		auto cur = Queue.front();
		Queue.pop();
		if (!visited[cur.first][cur.second])
		{
			visited[cur.first][cur.second] = 1;
		}
		for (int dir = 0; dir < 4; ++dir) 
		{
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];
			if (ny < 0 || ny >= height || nx < 0 || nx >= width)
				continue ;
			if (!sticker[sequence][ny][nx] || visited[ny][nx])
				continue ;
			Queue.push({ny, nx});
		}
	}
	for (int i = 0; i < height; ++i) 
	{
		for (int j = 0; j < width; ++j) 
		{
			if (sticker[sequence][i][j] == 1)
			{
				if (visited[i][j] != 1)
					return false;
			}
		}
	}
	return true;
}

bool check_sticker(int k, int i, int j)
{
	int height = coord[k].first;
	int width = coord[k].second;

	if (i + height > N || j + width > M)
		return false;
	for (int m = i; m < i + height; ++m) 
	{
		for (int n = j; n < j + width; ++n) 
		{
			if (sticker[k][m - i][n - j] == 1)
			{
				if (notebook[m][n] == 1)
					return false;
			}
		}
	}
	return true;
}

void put_sticker(int k, int i, int j)
{
	int height = coord[k].first;
	int width = coord[k].second;

	for (int m = i; m < i + height; ++m) 
	{
		for (int n = j; n < j + width; ++n) 
		{
			if (sticker[k][m - i][n - j] == 1)
				notebook[m][n] = 1;
		}
	}
}

void put_sticker_possible(int k)
{
	int height = coord[k].first;
	int width = coord[k].second;

	for (int dir = 0; dir < 5; ++dir) 
	{
		if (dir != 0)
			rotate(k);
		for (int i = 0; i < N; ++i) 
		{
			for (int j = 0; j < M; ++j) 
			{
				if (check_sticker(k, i, j) == true)
				{
					put_sticker(k, i, j);
					return ;
				}
			}
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	for (int k = 0; k < K; ++k) 
	{
		if (!is_connected(k))
			continue ;
		put_sticker_possible(k);
	}
	int count = 0;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < M; ++j) 
		{
			if (notebook[i][j] == 1)
				++count;
		}
	}
	cout << count;
}
