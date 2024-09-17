/*
 * cctv 하나당 방향은 4개
 * cctv2개면 경우의 수는 16개?
 * 실은 1,3,4번은 경우의 수가 4개
 * 2번은 2개 5번은 1개 있지만 문제를 단순화하려면..
 */
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;


int N, M;
int office[8][8];
int backup[8][8];
vector<pair<int, int>> cctv;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
int empty_area;
int blind_area = 0x7fffffff;
void get_input()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < M; ++j) 
		{
			cin >> backup[i][j];
			if (backup[i][j] >= 1 && backup[i][j] <= 5)
				cctv.push_back({i, j});
			if (backup[i][j] == 0)
				++empty_area;
		}
	}
}

void monitor(int dir, int y, int x)
{
//	cout << dir << ' ' << y << ' ' << x << '\n';
	dir %= 4;
	while (1)
	{
		y += dy[dir];
		x += dx[dir];
		if (y < 0 || y >= N || x < 0 || x >= M)
			break ;
		if (office[y][x] == 6)
			break ;
		if (office[y][x] >= 1 && office[y][x] <= 5)
			continue ;
		office[y][x] = 7;
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();

	for (int tmp = 0; tmp < (1 << (2 * cctv.size())); ++tmp) 
	{
		for (int i = 0; i < N; ++i) 
		{
			for (int j = 0; j < M; ++j) 
			{
				office[i][j] = backup[i][j];
			}
		}
		int brute = tmp;
		for (int rotate = 0; rotate < cctv.size(); ++rotate) 
		{
			int dir = brute % 4;
			brute /= 4;
			pair<int, int> point = cctv[rotate];
			if (office[point.first][point.second] == 1)
			{
				monitor(dir, point.first, point.second);
			}
			else if (office[point.first][point.second] == 2)
			{
				monitor(dir, point.first, point.second);
				monitor(dir + 2, point.first, point.second);
			}
			else if (office[point.first][point.second] == 3)
			{
				monitor(dir, point.first, point.second);
				monitor(dir + 3, point.first, point.second);
			}
			else if (office[point.first][point.second] == 4)
			{
				monitor(dir, point.first, point.second);
				monitor(dir + 2, point.first, point.second);
				monitor(dir + 3, point.first, point.second);
			}
			else
			{
				monitor(dir, point.first, point.second);
				monitor(dir + 1, point.first, point.second);
				monitor(dir + 2, point.first, point.second);
				monitor(dir + 3, point.first, point.second);
			}
		}
//		cout << '\n';
//		for (int i = 0; i < N; ++i) 
//		{
//			for (int j = 0; j < M; ++j) 
//			{
//				cout << office[i][j] << ' ';
//			}
//			cout << '\n';
//		}
		empty_area = 0;
		for (int i = 0; i < N; ++i) 
		{
			for (int j = 0; j < M; ++j) 
			{
				if (office[i][j] == 0)
					++empty_area;
			}
		}
		blind_area = min(blind_area, empty_area);
	}
	cout << blind_area;
}
