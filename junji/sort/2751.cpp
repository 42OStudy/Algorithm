#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int backup[1000000];
int	numbers[1000000];
int N;
void	get_input()
{
	cin >> N;
	for (int i = 0; i < N; ++i) 
		cin >> backup[i];
}

void	merge(int start, int end)
{
	int mid = (start + end) / 2;
	int l_idx = start;
	int r_idx = mid;

	for (int i = start; i < end; ++i) 
	{
		if (l_idx == mid)
			numbers[i] = backup[r_idx++];
		else if (r_idx == end)
			numbers[i] = backup[l_idx++];
		else if (backup[l_idx] <= backup[r_idx])
			numbers[i] = backup[l_idx++];
		else
			numbers[i] = backup[r_idx++];
	}
	for (int i = start; i < end; ++i) 
	{
		backup[i] = numbers[i];
	}
}
void merge_sort(int start, int end)
{
	if (end - start == 1)
		return ;
	int mid = (start + end) / 2;
	merge_sort(start, mid);
	merge_sort(mid, end);
	merge(start, end);
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	merge_sort(0, N);
	for (int i = 0; i < N; ++i) 
	{
		cout << backup[i] << '\n';
	}
}
