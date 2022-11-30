//10:09
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int picture_max_size;
int number_of_picture;
int board[500][500];
int visited[500][500];
int n, m;

void get_input()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i) 
	{
		for (int j = 0; j < m; ++j) 
		{
			cin >> board[i][j];
		}
	}
}
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	queue<pair<int, int>> Queue;
	int dy[] = {1, -1, 0, 0};
	int dx[] = {0, 0, -1, 1};
	get_input();
	for (int i = 0; i < n; ++i) 
	{
		for (int j = 0; j < m; ++j) 
		{
			if (board[i][j] == 1 && !visited[i][j])
			{
				visited[i][j] = 1;
				Queue.push({i, j});
				++number_of_picture;

				int size = 0;
				while (!Queue.empty())
				{
					auto cur = Queue.front();
					++size;
					Queue.pop();
					for (int dir = 0; dir < 4; ++dir) 
					{
						int ny = cur.first + dy[dir];
						int nx = cur.second + dx[dir];

						if (ny < 0 || nx < 0 || ny >= n || nx >= m)
							continue ;
						if (visited[ny][nx] || board[ny][nx] == 0)
							continue ;
						visited[ny][nx] = 1;
						Queue.push({ny, nx});
					}
				}
				picture_max_size = max(picture_max_size, size);
			}
		}
	}
	cout << number_of_picture << '\n' << picture_max_size;
}
