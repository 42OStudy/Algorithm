#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <set>
using namespace std;

int N;
int arr[1000000];

void	get_input()
{
	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		cin >> arr[i];
	}
	set<int> S(arr, arr + N);
	vector<int> V(S.begin(), S.end());
	for (int i = 0; i < N; ++i) 
	{
		cout << lower_bound(V.begin(), V.end(), arr[i]) - V.begin() << ' ';
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
}
