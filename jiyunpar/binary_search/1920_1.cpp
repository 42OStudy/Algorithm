#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> seq;
vector<int> target;

// using STL binary_search
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	seq.reserve(100000);
	target.reserve(100000);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int val;
		cin >> val;
		seq.push_back(val);
	}
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int val;
		cin >> val;
		target.push_back(val);
	}
	sort(seq.begin(), seq.end());
	for (int i = 0; i < m; ++i)
	{
		if (binary_search(seq.begin(), seq.end(), target[i]))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
	return (0);
}