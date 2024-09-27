#include <iostream>
#include <algorithm>
#include <queue>

#define Y first
#define X second

int map[500][500];
bool visit[500][500];
std::queue<std::pair<int, int> > queue;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

int	bfs(std::pair<int, int> point, int n, int m)
{
	int	area = 0;

	queue.push(point);
	visit[point.first][point.second] = true;
	
	while (!queue.empty())
	{
		++area;
		std::pair<int, int> p = queue.front();
		queue.pop();
		for (int i = 0; i < 4; ++i)
		{
			int	ny = p.Y + dy[i];
			int	nx = p.X + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m || visit[ny][nx] == true || map[ny][nx] == 0)
				continue ;
			queue.push(std::make_pair(ny, nx));
			visit[ny][nx] = true;
		}
	}
	return area;
}

int main()
{
	int	n, m;

	std::cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j) 
		{
			std::cin >> map[i][j];
		}
	}

	int	picture_count = 0, max_area = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j) 
		{
			if (map[i][j] == 1 && visit[i][j] == false)
			{
				++picture_count;
				max_area = std::max(max_area, bfs(std::make_pair(i, j), n, m));
			}
		}
	}
	std::cout << picture_count << ' ' << max_area;

}
