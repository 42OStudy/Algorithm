#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
long long arr[100000];
long long MAX = 0;

void get_input()
{
	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		cin >> arr[i];
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	sort(arr, arr + N);
	long long before = arr[0];
	long long comb = 1;
	pair<long long, long long> stat;
	stat.first = 1;
	stat.second = arr[0];
	for (int i = 1; i < N; ++i) 
	{
		if (before == arr[i])
		{
			++stat.first;
			if (MAX < stat.first)
			{
				MAX = stat.first;
				stat.second = arr[i];
			}
		}
		else
		{
			stat.first = 1;
			before = arr[i];
		}
	}
	cout << stat.second;
}
