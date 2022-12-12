#include <iostream>

using namespace std;

int arr[10];
bool used[10];
int n, m;

void	backtracking(int step)
{
	if (step == m)
	{
		for (int i = 0; i < m; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		return ;
	}
	for (int i = 1; i <= n; ++i)
	{
		if(!used[i])
		{
			arr[step] = i;
			used[i] = true;
			backtracking(step + 1);
			used[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	backtracking(0);
	return (0);
}