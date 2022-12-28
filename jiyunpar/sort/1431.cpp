#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>

using namespace std;
//1. string length
//2. smallest after sum number
//3. dictionary(number < alpha)

int get_sum(string a)
{
	int len = a.length();
	int sum = 0;
	for (int i = 0; i < len; ++i)
	{
		if (isdigit(a[i]))
			sum += (a[i] - '0');
	}
	return (sum);
}
bool first_func(string a, string b)
{
	int a_sum = get_sum(a);
	int b_sum = get_sum(b);	

	if (a.length() != b.length())
		return (a.length() < b.length());
	else if (a_sum != b_sum)
		return (a_sum < b_sum);
	else 
		return (a < b);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<string> V;
	V.reserve(60);
	for (int i = 0; i < n; ++i)
	{
		string val;
		cin >> val;
		V.push_back(val);
	}
	sort(V.begin(), V.end(), first_func);
	for (auto val : V)
		cout << val << '\n';
	
	return (0);
}