#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define HOUSE 1
#define CHIKEN 2

vector<pair<int, int> > house;
vector<pair<int, int> > chicken;

void	fill_input(int &N, int &M)
{
	int	input;

	cin >> N;
	cin >> M;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> input;
			if (input == HOUSE)
			{
				house.push_back(make_pair(i, j));
			}
			if (input == CHIKEN)
			{
				chicken.push_back(make_pair(i, j));
			}
		}
	}

}

int	get_min_chicken_distance(int M, int depth, int *chicken_combination, int chicken_i)
{
	int	sum_distance = 0;
	if (M != depth)
	{
		int min_distance = INT_MAX;
		for(int i = chicken_i; i < chicken.size(); ++i)
		{
			chicken_combination[depth] = i;
			min_distance = min(min_distance, get_min_chicken_distance(M, depth + 1, chicken_combination, i + 1));
		}
		return min_distance;
	}

	for (int i = 0; i < house.size(); ++i)
	{
		int	min_distance = INT_MAX;
		int house_r = house[i].first;
		int house_c = house[i].second;
		for (int j = 0; j < M; j++)
		{
			int	chicken_r = chicken[chicken_combination[j]].first;	
			int	chicken_c = chicken[chicken_combination[j]].second;	
			int	distance = abs(house_r - chicken_r) + abs(house_c - chicken_c);
			min_distance = min(min_distance, distance);
		}
		sum_distance += min_distance;
	}
	return (sum_distance);
}

int main()
{
	int N, M;

	fill_input(N, M);

	int *chicken_combination = new int[M];
	fill(chicken_combination, chicken_combination + M, 0);

	int result = INT_MAX;
	for (int i = 0; i < chicken.size(); ++i)
	{
		result = min(result, get_min_chicken_distance(M, 0, chicken_combination, 0));
	}
	cout << result << endl;
}
