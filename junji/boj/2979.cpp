#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
using namespace std;

int fee[4];
int parking_time[101];

void	get_input()
{
	for (int i = 1; i <= 3; ++i) 
	{
		cin >> fee[i];
	}
	for (int i = 0; i < 3; ++i) 
	{
		int start, end;
		cin >> start >> end;
		for (int i = start; i < end; ++i) 
		{
			parking_time[i]++;
		}
	}
	int total_fee = 0;
	for (int i = 0; i < 101; ++i) 
	{
		int per_person_rate = fee[parking_time[i]];
		total_fee += (per_person_rate *= parking_time[i]);
	}
	cout << total_fee;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
}
