#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
using namespace std;

int A[1000000];
int B[1000000];
int	C[2000000];

int N, M;

void	get_input()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i) 
	{
		cin >> A[i];
	}
	for (int i = 0; i < M; ++i) 
	{
		cin >> B[i];
	}
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	get_input();
	int	A_idx = 0;
	int	B_idx = 0;
	for (int index = 0; index < N + M; ++index) 
	{
		if (A_idx >= N)
			A[A_idx] = 0x7fffffff;
		if (B_idx >= M)
			B[B_idx] = 0x7fffffff;
		if (A[A_idx] >= B[B_idx])
			C[index] = B[B_idx++];
		else
			C[index] = A[A_idx++];
	}
	for (int index = 0; index < N + M; ++index) 
	{
		cout << C[index] << ' ';
	}
}
