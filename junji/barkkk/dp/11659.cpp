#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;
// 5 ~ 10까지의 구간 합은
// -> 1 ~ 10까지의 구간합 - 1 ~ 4까지의 구간합
// 1 ~ 5까지의 구간합은
// 1 ~ 5까지의 구간합 - 0 ~ 0까지의 구간합

// 다 풀고보니까, dp배열을 입력과 동시에 만들 수 있음.
// 처음부터 인덱스를 1로 받았으면 불필요한 예외처리가 없어도 됨>
int N, M;
int number[100000];
int	dp[100000];

void	make_dp_table()
{
	dp[0] = number[0];
	for (int i = 1; i < N; ++i) 
	{
		dp[i] = dp[i - 1] + number[i];
	}
}

void	get_input()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i) 
		cin >> number[i];
	make_dp_table();
	int start, end;
	int before_prefix_sum;
	for (int i = 0; i < M; ++i) 
	{
		cin >> start >> end;
		if (start == 1)
			before_prefix_sum = 0;
		else
			before_prefix_sum = dp[start - 2];
		cout << dp[end - 1] - before_prefix_sum << '\n';
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
}
