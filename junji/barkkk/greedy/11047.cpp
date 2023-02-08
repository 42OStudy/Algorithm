#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int	N, K;
int	coin[10];

void	get_input()
{
	cin >> N >> K;
	for (int i = 0; i < N; ++i) 
	{
		cin >> coin[i];
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	get_input();

	int need_money = K;
	int coin_cnt = 0;

	for (int i = N - 1; i >= 0; --i)
	{
		if (!need_money)
			break ;
//		cout << "i: " << i << '\n';
//		cout << need_money << ' ' << coin_cnt << '\n';
		while (need_money >= coin[i])
		{
			need_money -= coin[i];
			++coin_cnt;
		}
	}
	cout << coin_cnt;
}
/*
 * 제일 큰 동전금액부터 최대한 구매한다면 가장 적은 동전 갯수가 된다.
 */
