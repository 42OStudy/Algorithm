#include <iostream>

using namespace std;


int cnt[2000002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int num;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		++cnt[num + 1000000];
	}
	for (int i = 0; i < 2000002; ++i)
	{
		while (cnt[i]--)
		{
			cout << i - 1000000 << '\n';
		}
	}

	return (0);
}