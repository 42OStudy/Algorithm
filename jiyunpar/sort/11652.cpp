#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<long long> V;
	V.reserve(100000);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		long long val;
		cin >> val;
		V.push_back(val);
	}
	sort(V.begin(), V.end());
	long long max_val = -((long long)1 << 62) - 1;
	int cur_cnt = 1;
	int max_cnt = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		if (V[i] == V[i + 1])
			cur_cnt++;
		else
		{
			if (cur_cnt > max_cnt)
			{
				max_val = V[i];
				max_cnt = cur_cnt;
			}
			cur_cnt = 1;
		}
	}
	if (cur_cnt > max_cnt)
		max_val = V[n - 1];
	cout << max_val;
	return (0);
}