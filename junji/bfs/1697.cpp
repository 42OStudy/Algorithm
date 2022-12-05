// 46
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int N, K;
int visited[100001];
queue<pair<int, int>> Queue;

void bfs()
{
	visited[N] = 1;
	Queue.push({N, 0});

	while (!Queue.empty())
	{
		auto cur = Queue.front();
		Queue.pop();

		int location = cur.first;
		int time = cur.second;
		if (location == K)
		{
			cout << cur.second;
			return ;
		}

		if (location + 1 <= 100000 && !visited[location + 1])
		{
			visited[location + 1] = 1;
			Queue.push({location + 1, time + 1});
		}
		if (location - 1 >= 0 && !visited[location - 1])
		{
			visited[location - 1] = 1;
			Queue.push({location - 1, time + 1});
		}
		if (location * 2 <= 100000 && !visited[2 * location])
		{
			visited[2 * location] = 1;
			Queue.push({2 * location, time + 1});
		}
	}
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> N >> K;
	bfs();
}
