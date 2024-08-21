#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b)
{
	return (a > b);
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a;
	vector<int> b;
	a.reserve(100);
	b.reserve(100);
	for (int i = 0; i < n; ++i)
	{
		int val;
		cin >> val;
		a.push_back(val);
	}
	for (int i = 0; i < n; ++i)
	{
		int val;
		cin >> val;
		b.push_back(val);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), comp);
	// for (auto i : a)
	// 	cout << i << ' ';
	// cout << '\n';
	// for (auto i : b)
	// 	cout << i << ' ';
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += a[i] * b[i];
	}
	cout << ans;
	return (0);
}