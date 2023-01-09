#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int N, S;
int A[50], B[50];

bool	cmp(int a, int b)
{
	if (a != b)
		return (a > b);
	return (a > b);
}
void	get_input()
{
	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) 
	{
		cin >> B[i];
	}
	sort(A, A + N);
	sort(B, B + N, cmp);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	for (int i = 0; i < N; ++i) 
	{
		S += (A[i] * B[i]);
	}
	cout << S;
}
