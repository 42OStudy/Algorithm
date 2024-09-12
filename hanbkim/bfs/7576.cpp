#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

int map[1000][1000];
int visit[1000][1000];
std::queue<std::tuple<int, int, int> > queue;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

int	bfs(int N, int M)
{
	int day = 0;
	while (!queue.empty())
	{
		std::tuple<int, int, int> next = queue.front();
		queue.pop();
		day = std::get<2>(next);
		for (int i = 0; i < 4; ++i)
		{
			int ny = std::get<0>(next) + dy[i];
			int nx = std::get<1>(next) + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue ;
			if (visit[ny][nx] || map[ny][nx] == -1)
				continue;
			visit[ny][nx] = true;
			map[ny][nx] = 1;
			queue.push(std::make_tuple(ny, nx, std::get<2>(next) + 1));
		}
	}
	return day;
}

int main()
{
	int	N, M;

	std::cin >> M >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			std::cin >> map[i][j];
			if (map[i][j] == 1)
			{
				queue.push(std::make_tuple(i, j, 0));
				visit[i][j] = true;
			}
		}
	}

	int day = bfs(N, M);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (map[i][j] == 0)
			{
				std::cout << -1 << '\n';
				return 0;
			}

		}
	}
	std::cout << day << '\n';
}
