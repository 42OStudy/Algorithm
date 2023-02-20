#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> seq;
vector<int> target;

int binarysearch(int i)
{
	int start, end, mid;
	start = 0;
	end = n -1;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (seq[mid] < target[i])
			start = mid + 1;
		else if (seq[mid] > target[i])
			end = mid - 1;
		else
			return (1);
	}
	return (0);
}

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
		if (binarysearch(i))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
	return (0);
}