#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;
// 2 * 1 : 1개 |
// 2 * 2 : 2개 ㅡㅡ, ||
// 2 * 3 : 3개 ㅡㅡ|, |||, |ㅡㅡ
// 2 * 4 : 5개 ㅡㅡ||, ||||, |ㅡㅡ|,  ㅡㅡㅡㅡ,||ㅡㅡ 
// 2 * 5 : 8개 ㅡㅡ|||, |||||, |ㅡㅡ||, ㅡㅡㅡㅡ|, ||ㅡㅡ|
//		   ㅡㅡ|ㅡㅡ, |ㅡㅡㅡㅡ, |||ㅡㅡ 

int n;
int dp[1000];

void	get_input()
{
	cin >> n;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; ++i) 
		dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
	cout << dp[n] % 10007;
}	
