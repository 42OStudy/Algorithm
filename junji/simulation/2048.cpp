#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
int board[20][20];
int backup[20][20];
int biggest_block = 0x80000000;

void get_input()
{
	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			cin >> backup[i][j];
		}
	}
}

void rotate()
{
	int temp[20][20];

	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			temp[i][j] = board[i][j];
		}
	}
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			board[j][N - 1 - i] = temp[i][j];
		}
	}
}

void tilt(int dir)
{
	while (dir--)
		rotate();
	int tilted[20];
	for (int i = 0; i < N; ++i) 
	{
		memset(tilted, 0, sizeof(tilted));
		int idx = 0;
		for (int j = 0; j < N; ++j) 
		{
			if (board[i][j] == 0)
				continue ;
			if (tilted[idx] == 0)
				tilted[idx] = board[i][j];
			else if (tilted[idx] == board[i][j])
				tilted[idx++] *= 2;
			else 
				tilted[++idx] = board[i][j];
		}
		for (int j = 0; j < N; ++j) 
		{
			board[i][j] = tilted[j];
		}
	}
}
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	get_input();
	for (int tmp = 0; tmp < (1 << (2 * 5)); ++tmp) 
	{
		for (int i = 0; i < N; ++i) 
		{
			for (int j = 0; j < N; ++j) 
			{
				board[i][j] = backup[i][j];
			}
		}
		int brute = tmp;
		for (int i = 0; i < 5; ++i) 
		{
			int dir = brute % 4;
			tilt(dir);
			brute /= 4;
		}
		for (int i = 0; i < N; ++i) 
		{
			for (int j = 0; j < N; ++j) 
			{
				biggest_block = max(biggest_block, board[i][j]);
			}
		}
	}
	cout << biggest_block;
}
