#include <iostream>

using namespace std;


// 0,0 -> 0,1 -> 1,0 -> 1,1
int visit_z(int n, int r, int c)
{
	if (n == 0)
		return (0);
	int range = 1 << (n - 1);
	if (r < range && c < range)
		return visit_z(n - 1, r , c);
	if (r < range && c >= range)
		return visit_z(n - 1, r, c - range) + range * range;
	if (r >= range && c < range)
		return visit_z(n - 1, r - range, c) + 2 * range * range;
	return visit_z(n - 1, r - range, c - range) + 3 * range * range;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, r, c;
	cin >> n >> r >> c;
	cout << visit_z(n, r, c);

	return (0);
}