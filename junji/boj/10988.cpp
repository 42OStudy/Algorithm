#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
using namespace std;

string str;

void	get_input()
{
	cin >> str;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	int start = 0;
	int end = str.length() - 1;

	while (start < end)
	{
		if (str[start] != str[end])
		{
			cout << 0;
			return (0);
		}
		else
		{
			++start;
			--end;
		}
	}
	cout << 1;
}
