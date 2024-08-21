#include <iostream>
#include <vector>

using namespace std;

int n, m;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	vector<bool> a;
	a.resize(1000001, true);
	a[1] = false;
	for (int i = 2; i <= m; ++i)
	{
		int j = 2;
		while (i * j <= m)
		{
			a[i * j] = false;
			++j;
		}
	}
	int ans = 0;
	for (int i = n; i <= m; ++i)
	{
		if (a[i] == true)
			cout << i << '\n';
	}
	return (0);
}