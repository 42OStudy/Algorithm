#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int N, M;

int visited[9];
int arr[8];
int select[8];

void get_input()
{
	cin >> N >> M;
}

//void dfs(int depth)
//{
//	if (depth == M)
//	{
//		for (int i = 0; i < M; ++i) 
//		{
//			cout << arr[i] << ' ';
//		}
//		cout << '\n';
//		return ;
//	}
//	for (int i = 1; i <= N; ++i) 
//	{
//		if (!visited[i])
//		{
//			visited[i] = 1;
//			arr[depth] = i;
//			dfs(depth + 1);
//			visited[i] = 0;
//		}
//	}
//}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input(); 
	for (int i = 0; i < 8; ++i) 
		arr[i] = i + 1;
	do {
		for (int i = 0; i < M; ++i) 
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		reverse(arr + M, arr + N);
	} while (next_permutation(arr, arr + N));
}	
