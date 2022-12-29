#include <iostream>
#include <vector>

using namespace std;

int a[20];
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int val;
		cin >> val;
		a[1] = 1;
		a[2] = 2;
		a[3] = 4;
		for (int i = 4; i <= val; ++i)
		{
			a[i] = a[i - 1] + a[i - 2] + a[i - 3];
		}
		cout << a[val] << '\n';
	}
	return (0);	
}