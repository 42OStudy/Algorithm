#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
int A[100000];
int M;

void binary_search(int number)
{
	int left = 0;
	int right = N - 1;
	bool is_find = false;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (A[mid] == number)
			is_find = true;
		if (A[mid] < number)
			left = mid + 1;
		else
			right = mid - 1;
	}
	if (is_find)
		cout << 1;
	else
		cout << 0;
	cout << '\n';
}

void get_input()
{
	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		cin >> A[i];
	}
	sort(A, A + N);
	cin >> M;
	for (int i = 0; i < M; ++i) 
	{
		int number;
		cin >> number;
		binary_search(number);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
}
