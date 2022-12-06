// 50M
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int N, r, c;
void get_input()
{
	cin >> N >> r >> c;
}

int square(int N, int r, int c)
{
	if (N == 1)
	{
		if (r == 0 && c == 0)
			return (0);
		if (r == 0 && c == 1)
			return (1);
		if (r == 1 && c == 0)
			return (2);
		if (r == 1 && c == 1)
			return (3);
	}
	int half = (1 << (N - 1));
	int offset = half * half;
	if (r < half && c < half)
		return (square(N - 1, r, c));
	if (r < half && c >= half)
		return (offset + square(N - 1, r, c - half));
	if (r >= half && c < half)
		return (2 * offset + square(N - 1, r - half, c));
	return (3 * offset + square(N - 1, r - half, c - half));
}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	int ans = square(N, r, c);
	cout << ans;
}
