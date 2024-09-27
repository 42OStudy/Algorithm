#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int N, K;

void	get_input()
{
	cin >> N >> K;

	int ans = 1;
	for (int i = 1; i <= N; ++i)
		ans *= i;
	for (int i = 1; i <= K; ++i)
		ans /= i;
	for (int i = 1; i <= (N - K); ++i) 
		ans /= i;
	cout << ans;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
}
