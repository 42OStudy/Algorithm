#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, ans, flag;
int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ans = 0;
	vector<int> input;
	input.reserve(100);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> input[i];
	for (int i = 0; i < n; ++i)
	{
		if (input[i] == 1)
			continue;
		for (int j = 2; j < input[i]; ++j)
		{
			if (input[i] % j == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			++ans;
		if (flag == 1)
			flag = 0;
	}

	cout << ans;	
	return (0);
}