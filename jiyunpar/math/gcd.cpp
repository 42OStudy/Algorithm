#include <iostream>
#include <vector>

using namespace std;

int	gcd(int a, int b)
{
	if (b == 0)
		return (a);
	return (gcd(b, a % b));
}

int lcm(int a, int b)
{
	return (a / gcd(a, b) * b);
}

int main(void)
{
	int a, b, ans;
	cin >> a >> b;
	ans = lcm(a, b);
	cout << ans;
	return (0);
}