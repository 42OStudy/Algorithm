#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
using namespace std;

int dwarf[9];
int selected[9];

void	get_input()
{
	for (int i = 0; i < 9; ++i) 
		cin >> dwarf[i];
	sort(dwarf, dwarf + 9);
	fill(selected + 7, selected + 9, 1);
//	for (int i = 0; i < 9; ++i) 
//	{
//		cout << selected[i] << ' ';
//	}
//	cout << '\n';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	do {
		int sum = 0;
		for (int i = 0; i < 9; ++i) 
		{
			if (selected[i] == 0)
			{
				sum += dwarf[i];
			}
		}
		if (sum == 100)
		{
			for (int i = 0; i < 9; ++i) 
			{
				if (selected[i] == 0)
				{
					cout << dwarf[i] << '\n';
				}
			}
			break ;
		}
	} while (next_permutation(selected, selected + 9));
}
