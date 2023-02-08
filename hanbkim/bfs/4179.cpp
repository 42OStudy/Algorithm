#include <iostream>
#include <algorithm>
#include <queue>


int	fire[1001][1001];
int	jihun[1001][1001];
int map[1001][1001];
std::queue<std::pair<int, int> > queue;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

int	bfs(int R, int C, int jihun_y, int jihun_x)
{
	while (!queue.empty())
	{
		auto node = queue.front();
		queue.pop();
		for (int i = 0; i < 4; ++i)
		{
			int ny = node.first + dy[i];
			int nx = node.second + dx[i];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C)
				continue ;
			if (map[ny][nx] != '.' || fire[ny][nx] != 0)
				continue ;
			queue.push(std::make_pair(ny, nx));	
			fire[ny][nx] = fire[node.first][node.second] + 1;
		}
	}

	queue.push(std::make_pair(jihun_y, jihun_x));

	while (!queue.empty())
	{
		auto node = queue.front();
		std::cout << node.first << " " << node.second << "\n";
		queue.pop();
		if (node.first == R - 1 || node.first == 0 || node.second == 0 || node.second == C - 1)
			return jihun[node.first][node.second];
		for (int i = 0; i < 4; ++i)
		{
			int ny = node.first + dy[i];
			int nx = node.second + dx[i];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C)
				continue ;
			if (jihun[ny][nx] != 0 || map[ny][nx] != '.')
				continue;
			if (fire[ny][nx] != 0 && jihun[node.first][node.second] + 1 >= fire[ny][nx])
				continue ;
			queue.push(std::make_pair(ny, nx));	
			jihun[ny][nx] = jihun[node.first][node.second] + 1;
		}
	}
	return -1;
}


int main()
{
	int	R, C;

	std::cin >> R >> C;
	int jihun_y, jihun_x;
	for (int i = 0; i < R; ++i)
	{
		std::string line;
		std::cin >> line;
		for (int j = 0; j < C; ++j)
		{
			map[i][j] = line[j];
			if (map[i][j] == 'J')
			{
				jihun_y = i;
				jihun_x = j;
				jihun[i][j] = 1;
			}
			if (map[i][j] == 'F')
			{
				fire[i][j] = 1;
				queue.push(std::make_pair(i, j));
			}
		}
	}
	int minute = bfs(R, C, jihun_y, jihun_x);

	if (minute == -1)
		std::cout << "IMPOSSIBLE";
	else 
		std::cout << minute;
}
