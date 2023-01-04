#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> coin;
	coin.resize(20, 0);
	for (int i = 0; i < n; ++i)
		cin >> coin[i];
	int ans = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		ans += k / coin[i];	
		k = k % coin[i];
		if (k == 0)
			break ;
	}
	cout << ans;
	return (0);
}