#include <iostream>

using namespace std;


long long	multiple_n_time(long long a, long long b, long long c)
{
	if (b == 1)
		return a % c;
	long long ret = multiple_n_time(a, b / 2, c);
	ret = ret * ret % c;
	if (b % 2 == 0)
		return ret;
	return ret * a % c;
}

// 시간 초과 걸리는 풀이
// long long	multiple_n_time(long long a, long long b, long long ans)
// {
// 	if (b == 0)
// 		return ans;
// 	ans *= a;
// 	return (multiple_n_time(a, b - 1, ans));	
// }


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long ans;
	long long a, b, c;
	cin >> a >> b >> c;
	ans = multiple_n_time(a, b, c);
	cout << ans;
	return (0);
}