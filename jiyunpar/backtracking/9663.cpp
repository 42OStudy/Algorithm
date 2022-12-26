#include <iostream>

using namespace std;

int vis[14][14];
int cnt;
int n;

bool is_row_left(int row, int col)
{
	for (int i = 0; i < col; ++i)
	{
		if (vis[row][i] == 1)
			return true;
	}
	return false;
}
// for문 한번으로 줄이기
bool is_diag_up(int row, int col)
{
	for (int i = 0; i < col + 1; ++i)
	{
		if (col - i < 0 || row - i < 0) 
			break ;
		if (vis[row - i][col - i] == 1)
			return true;
	}
	return false;
}
// bool is_diag_up(int row, int col)
// {
// 	for (int i = 0; i < row; ++i)
// 	{
// 		for (int j = 0; j < col; ++j)
// 		{
// 			if (col - j == row - i && vis[i][j] == 1)
// 				return true;
// 		}
// 	}
// 	return false;
// }

// for문 한번으로 줄이기
bool is_diag_down(int row, int col)
{
	for (int i = 0; i < n - row + 1; ++i)
	{
		if (row + i >= n || col - i < 0)
			break ;
		if (vis[row + i][col - i] == 1)
			return true;
	}
	return false;
}
// bool is_diag_down(int row, int col)
// {
// 	for (int i = row + 1; i < n; ++i)
// 	{
// 		for (int j = 0; j < col; ++j)
// 		{
// 			if (col - j == i - row && vis[i][j] == 1)
// 			{
// 				return true;
// 			}
// 		}
// 	}
// 	return false;
// }

void	backtracking(int col)
{
	if (col == n)
	{
		++cnt;
		// for (int i = 0; i < n; ++i)
		// {
		// 	for (int j = 0; j < n; ++j)
		// 	{
		// 		cout << vis[i][j];
		// 	}
		// 	cout << '\n';
		// }
		// cout << "--------------\n";
		return ;
	}
	for (int i = 0; i < n; ++i)
	{
		if (!is_row_left(i, col) && !is_diag_up(i, col) && !is_diag_down(i, col))
		{
			vis[i][col] = 1;
			backtracking(col + 1);
			vis[i][col] = 0;
		}
	}

}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	backtracking(0);
	cout << cnt;

	return (0);
}