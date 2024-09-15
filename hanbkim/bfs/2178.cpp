#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

int map[100][100];
int visit[100][100];
std::queue<std::tuple<int, int, int> > queue;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

int	bfs(int init_i, int init_j, int N, int M)
{
	queue.push(std::make_tuple(init_i, init_j, 1));
	visit[init_i][init_j] = true;

	while (!queue.empty())
	{
		std::tuple<int, int, int> next = queue.front();
		queue.pop();
		if (std::get<0>(next) == N - 1 && std::get<1>(next) == M - 1)
			return std::get<2>(next);
		for (int i = 0; i < 4; ++i)
		{
			int ny = std::get<0>(next) + dy[i];
			int nx = std::get<1>(next) + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue ;
			if (visit[ny][nx] || map[ny][nx] != 1)
				continue;
			visit[ny][nx] = true;
			queue.push(std::make_tuple(ny, nx, std::get<2>(next) + 1));
		}
	}
	return 0;
}

int main()
{
	int	N, M;

	std::cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		std::string line;
		std::cin >> line;
		for (int j = 0; j < M; ++j)
		{
			 map[i][j] = line[j] - '0';
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (map[i][j] == 1 && visit[i][j] == false)
			{
				int result = bfs(i, j, N, M);
				if (result != 0)
				{
					std::cout << result << '\n';
					return 0;
				}
			}
		}
	}
	
}
