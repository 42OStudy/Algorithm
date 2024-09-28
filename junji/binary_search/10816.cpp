#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
int S[500000];
int M;

int	find_end_idx(int number)
{
	int	left = 0;
	int right = N;

	while (left < right)
	{
		int mid = (left + right) / 2;
		if (S[mid] <= number)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	return (left);
}

int	find_start_idx(int number)
{
	int left = 0;
	int right = N; // N - 1이 아니다

	while (left < right) // = 등호가 없다!
	{
		int mid = (left + right) / 2;
		if (S[mid] < number) // 10이 들어갈 수 있는 가장 왼쪽의 위치는 mid이하라는 거
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	return (left);
}

void	get_input()
{
	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		cin >> S[i];
	}
	cin >> M;
	sort(S, S + N);
	for (int i = 0; i < M; ++i) 
	{
		int number;
		cin >> number;
		cout << find_end_idx(number) - find_start_idx(number) << ' ';
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
}
