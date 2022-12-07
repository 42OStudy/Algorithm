#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

void hanoi(int N, int A, int B)
{
	if (N == 1)
	{
		cout << A << ' ' << B << '\n';
		return ;
	}
	hanoi(N - 1, A, 6 - A - B);
	cout << A << ' ' << B << '\n';
	hanoi(N - 1, 6 - A - B, B);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;
	cout << (1 << N) - 1 << '\n';
	hanoi(N, 1, 3);
}
