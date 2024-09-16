#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int sequence[20];
bool visited[20];
int cnt;
int N, S;
void get_input()
{
	cin >> N >> S;
	for (int i = 0; i < N; ++i) 
	{
		cin >> sequence[i];
	}
}

void dfs(int depth, int sum, int idx)
{
//	cout << depth << ' ' << sum << ' ' << idx << '\n';
	if (depth == N)
	{
		return ;
	}
	for (int i = idx; i < N; ++i) 
	{
		if (!visited[i])
		{
			visited[i] = true;
			sum += sequence[i];
			if (sum == S)
				++cnt;
			dfs(depth + 1, sum, i);
			sum -= sequence[i];
			visited[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	sort(sequence, sequence + N);
	dfs(0, 0, 0);
	cout << cnt;
}
// 바킹독 풀이, next_permutation 풀이
