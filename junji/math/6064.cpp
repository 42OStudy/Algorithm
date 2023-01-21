#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int T;
int M, N, x, y;

int gcd(int a, int b)
{
	if (a == 0)
		return (b);
	return (gcd(b % a, a));
}

int lcm(int a, int b)
{
	return (a / gcd(a, b) * b);
}

void	get_input()
{
	cin >> T;
	for (int i = 0; i < T; ++i) 
	{
		bool is_find = false;
		cin >> M >> N >> x >> y;
		int end = lcm(M, N);
		for (int i = x; i <= end; i += M) 
		{
			if (i % N == y || (i % N == 0 && N == y))
			{
				cout << i << '\n';
				is_find = true;
				break ;
			}
		}
		if (!is_find)
			cout << "-1\n";
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
}
