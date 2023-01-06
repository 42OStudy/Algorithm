#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> seq;
	seq.reserve(200000);
	for (int i = 0; i < n; ++i)
	{
		int val;
		cin >> val;
		seq.push_back(val);
	}
	sort(seq.begin(), seq.end());
	// for (auto i : seq)
	// 	cout << i;
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int cur = seq[i] * (n - i);
		ans = max(ans, cur);
	}
	cout << ans;
	return (0);
}
