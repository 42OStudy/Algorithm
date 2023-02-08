#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int counting_table[2000001];

int N;
void	get_input()
{
	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		int number;
		cin >> number;
		++counting_table[number + 1000000];
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	for (int i = 0; i < 2000001; ++i) 
	{
		while (counting_table[i])
		{
			cout << i - 1000000 << '\n';
			--counting_table[i];
		}
	}
}
