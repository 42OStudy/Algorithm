#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
int rope[100000];
int max_weight;

bool cmp(int a, int b)
{
	return (a > b);
}

void get_input()
{
	cin >> N;
	int cur_weight = 0;
	int total = 0;
	for (int i = 0; i < N; ++i) 
	{
		cin >> rope[i];
	}
	sort(rope, rope + N, cmp);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	int cur_weight;
	for (int i = 0; i < N; ++i) 
	{
		cur_weight = rope[i] * (i + 1);
		max_weight = max(max_weight, cur_weight);
	}
	cout << max_weight;
}

//처음에는 5 3 1 1 1 1 1입력이 들어온다고 햇을 때,
//5와 3을보고, 6으로 갱신하고, 다음 1이 들어오면 3이 줄어드므로 끝까지 탐색 안하고 break함. (끝까지 탐색하면, 7임)
//int N;
//int rope[100000];
//
//bool cmp(int a, int b)
//{
//	return (a > b);
//}
//
//void get_input()
//{
//	cin >> N;
//	for (int i = 0; i < N; ++i) 
//	{
//		cin >> rope[i];
//	}
//	sort(rope, rope + N, cmp);
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	get_input();
//	int total = 0;
//	int max_weight;
//	for (int i = 0; i < N; ++i) 
//	{
//		if (rope[i] * (i + 1) <= total)
//		{
//			max_weight = total;
//			break ;
//		}
//		total += rope[i];
//		if (i == N - 1)
//		{
//			int min_value = rope[i];
//			max_weight = min_value * N;
//		}
//	}
//	cout << max_weight;
//}

