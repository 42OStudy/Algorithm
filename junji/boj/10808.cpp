#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
using namespace std;

int alpha[26];
string str;

void	get_input()
{
	cin >> str;
	for (int i = 0; str[i]; ++i) 
	{
		alpha[str[i] - 'a']++;
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	for (int i = 0; i < 26; ++i) 
	{	
		cout << alpha[i] << ' ';
	}
}
