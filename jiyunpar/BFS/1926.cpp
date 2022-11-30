#include <iostream>
#include <queue> // queue
#include <utility> // pair
#include <algorithm>

using namespace std;

#define X first
#define Y second
int vis[500][500];
int board[500][500];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
		}
	}
	int ret = 0;
	int pic_num = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (vis[i][j] != 1 && board[i][j] == 1)
			{
				++pic_num;
				int count = 0;
				queue<pair<int, int> > Q;
				vis[i][j] = 1;
				Q.push({i,j});
				++count;
				while (!Q.empty())
				{
					pair<int, int> cur = Q.front();
					Q.pop();
					for (int i = 0; i < 4; ++i)
					{
						int nx = cur.X + dx[i];
						int ny = cur.Y + dy[i];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m)
							continue;
						if (vis[nx][ny] || board[nx][ny] == 0)
							continue;
						vis[nx][ny] = 1;
						Q.push({nx, ny});
						++count;
					}	
				}
				ret = max(ret, count);
			}
		}
	}
	cout << pic_num << '\n' << ret;

	return (0);
}