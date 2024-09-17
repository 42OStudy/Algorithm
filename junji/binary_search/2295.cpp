#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
int U[1000];
vector<int> two;

void	get_input()
{
	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		cin >> U[i];
	}
	sort(U, U + N);
	int idx = 0;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = i; j < N; ++j) 
			two.push_back(U[i] + U[j]);
	}
	sort(two.begin(), two.end());
//	for (int i = 0; i < two.size(); ++i) 
//	{
//		cout << two[i] << ' ';
//	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	for (int i = N - 1; i > 0; --i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			int find = U[i] - U[j];
			if (binary_search(two.begin(), two.end(), find))
			{
				cout << U[i];
				return (0);
			}
		}
	}
}
