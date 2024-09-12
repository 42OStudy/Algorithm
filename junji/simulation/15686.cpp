#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int N, M;
int city[50][50];
int min_dist = 0x7fffffff;
int total_dist = 0;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

void get_input()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			cin >> city[i][j];
			if (city[i][j] == 1)
				house.push_back({i, j});
			else if (city[i][j] == 2)
				chicken.push_back({i, j});
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	get_input();
	int visited[13] = {};
	fill(visited + M, visited + chicken.size(), 1);
//	cout << '\n';
//	for (int i = 0; i < chicken.size(); ++i) 
//	{
//		cout << visited[i] << ' ';
//	}
	do {
		total_dist = 0;
		for (auto h : house)
		{
			int chicken_dist = 0x7fffffff;
			for (int i = 0; i < chicken.size(); ++i) 
			{
				if (!visited[i])
				{
					//						cout <<	chicken[i].first << ' ' << chicken[i].second << ' ' << '\n';
					//						cout << h.first << ' ' << h.second << ' ' << '\n';

					chicken_dist = min(chicken_dist, abs(h.first - chicken[i].first) + abs(h.second - chicken[i].second));
					//						cout << "chicken_dist: " << chicken_dist << '\n';
				}
			}
			total_dist += chicken_dist;
			//				cout << "total_dist: " << total_dist << '\n';
		}
		min_dist = min(min_dist, total_dist);
		//			cout << "min_dist: " << min_dist << '\n';
	} while (next_permutation(visited, visited + chicken.size()));

	cout << min_dist;
}
