#include <iostream>

using namespace std;

void move_plate(int a, int b, int n)
{
	if (n == 1)
	{
		cout << a << ' ' << b << '\n';
		return ;
	}
	move_plate(a, 6 - b - a, n - 1);
	cout << a << ' ' << b << '\n';
	move_plate(6 - b - a, b, n - 1);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	cout << (1<<n) - 1 << '\n';
	move_plate(1, 3, n);
	return (0);
}
