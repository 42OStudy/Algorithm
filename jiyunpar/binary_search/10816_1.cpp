#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int n, m;
vector<int> seq;
vector<int> target;

// using STL lowerbound upperbound
// return val : if array -> pointer
//				if stl container -> iterator

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
		cout << upper_bound(seq.begin(), seq.end(), val) - lower_bound(seq.begin(), seq.end(), val) << " ";	
	}
	return (0);
}