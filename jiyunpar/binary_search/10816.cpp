#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int n, m;
vector<int> seq;
vector<int> target;

int	upperbound(int val)
{
	int st = 0;
	int end = n;
	while (st < end)
	{
		int mid = (st + end) / 2;
		if (seq[mid] > val)
			end = mid;
		else
			st = mid + 1;
	}
	return (st);
}

int	lowerbound(int val)
{
	int st = 0;
	int end = n;
	while (st < end)
	{
		int mid = (st + end) / 2;
		if (seq[mid] >= val)
			end = mid;
		else
			st = mid + 1;
	}
	return (st);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	seq.reserve(500000);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int val;
		cin >> val;
		seq.push_back(val);
	}
	sort(seq.begin(), seq.end());
	cin >> m;
	while (m--)
	{
		int val;
		cin >> val;
		cout << upperbound(val) - lowerbound(val) << " ";	
	}
	return (0);
}