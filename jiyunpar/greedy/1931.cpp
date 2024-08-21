#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

// 1. 해결 방법이 현재기준 앞에 회의를 보면서 현재와 연결될 수 있는 회의에서 + 1 dp방법 만 생각남... O(n^2) -> 시간 초과(n = 100000)
// 2. 탐색 범위를 줄일 수 있을지 생각해 봐야함... 생각 안남.... 
// 3. 회의가 끝나는 시간 기준으로 정렬하는 힌트 보고 구현함
// 4. 1, 3 / 4, 4 / 3, 4 반례 = 정렬 올바르게 할 것.
bool comp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return (a.first < b.first);
	return (a.second < b.second);
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int> > time;
	time.reserve(200000);
	for (int i = 0; i < n; ++i)
	{
		pair<int, int> value;
		cin >> value.first >> value.second;
		time.push_back(value);
	}
	sort(time.begin(), time.end(), comp);
	// for (int i = 0; i < n; ++i)
	// 	cout << time[i].first << ' ' << time[i].second << '\n';
	int cnt = 1;
	pair<int , int> prev;
	prev.first = time[0].first;
	prev.second = time[0].second;
	for (int i = 1; i < n; ++i)
	{
		if (prev.second <= time[i].first)
		{
			++cnt;
			prev.first = time[i].first;
			prev.second = time[i].second;
			continue;
		}
	}
	cout << cnt;
	return (0);
}