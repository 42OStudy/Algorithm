#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int rest_area[52];
int dist[52];
int N, M, L;

void	get_input()
{
	cin >> N >> M >> L;
	rest_area[0] = 0;
	for (int i = 1; i <= N; ++i) 
	{
		cin >> rest_area[i];
	}
	rest_area[N + 1] = L;
	sort(rest_area, rest_area + (N + 2));
	for (int i = 1; i <= N + 1; ++i) 
	{
		dist[i - 1] = rest_area[i] - rest_area[i - 1];
	}
//	for (int i = 0; i <= N; ++i) 
//	{
//		cout << dist[i] << ' ';
//	}
}

int parametric_search()
{
	int left = rest_area[0] + 1;
	int right = rest_area[N + 1] - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2; // mid가 휴게소 사이의 간격
		int count = 0;
		for (int i = 0; i <= N; ++i) 
		{
			count += dist[i] / mid;
			if (dist[i] % mid == 0)
				--count;
		}
		if (count > M)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return (left);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	cout << parametric_search();
}
