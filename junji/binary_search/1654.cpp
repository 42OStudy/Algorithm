#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int N, K;
int lan[10000];
int Max;

void	get_input()
{
	cin >> N >> K;
	for (int i = 0; i < N; ++i) 
	{
		cin >> lan[i];
		if (Max < lan[i])
			Max = lan[i];
	}
}

long long b_search(long long left, long long right)
{
	long long ans = 0;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long cnt = 0;
		for (int i = 0; i < N; ++i) 
			cnt += lan[i] / mid;
		if (cnt < K)
		{
			right = mid - 1;
		}
		else
		{
			ans = mid;
			left = mid + 1;
		}
	}
	return (ans);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	cout << (b_search(1, Max));
}
