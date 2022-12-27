// 09 15 ~ 
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
int cnt;
bool col_check[15][15];
bool diag1_check[15][15];
bool diag2_check[15][15];

bool is_exist_col(int row, int col)
{	
	for (int i = 0; i < N; ++i) 
	{
		if (col_check[i][col] == true)
			return true;
	}
	return false;
}

/*
 * \
 */
bool is_exist_diag1(int row, int col)
{
	for (int i = 0; i < N; ++i) 
	{
		if (row + i >= N || col + i >= N)
			break ;
		if (diag1_check[row + i][col + i] == true)
			return true;
	}
	for (int i = 0; i < N; ++i) 
	{
		if (row - i < 0 || col - i < 0)
			break ;
		if (diag1_check[row - i][col - i] == true)
			return true;
	}
	return false;
}


bool is_exist_diag2(int row, int col)
{
	for (int i = 0; i < N; ++i) 
	{
		if (row - i < 0 || col + i >= N)
			break ;
		if (diag2_check[row - i][col + i] == true)
			return true;
	}
	for (int i = 0; i < N; ++i) 
	{
		if (row + i >= N || col - i < 0)
			break ;
		if (diag2_check[row + i][col - i] == true)
			return true;
	}
	return false;
}


void dfs(int row)
{
	if (row == N)
	{
		++cnt;
		return ;
	}
	for (int col = 0; col < N; ++col) 
	{
		if (!is_exist_col(row, col) && !is_exist_diag1(row, col) && !is_exist_diag2(row, col))
		{
			col_check[row][col] = 1;
			diag1_check[row][col] = 1;
			diag2_check[row][col] = 1;
			dfs(row + 1);
			col_check[row][col] = 0;
			diag1_check[row][col] = 0;
			diag2_check[row][col] = 0;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	dfs(0);
	cout << cnt;
}

