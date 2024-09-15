#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > absolute_queue;

int	smallest_number()
{
	if (absolute_queue.size() == 0)
		return (0);

	const pair<int, int> min_value = absolute_queue.top();
	absolute_queue.pop();
	return (min_value.second);
}

int main()
{
	int N, input;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> input;
		if (input == 0)
		{
			cout << smallest_number() << '\n';
			continue ;
		}
		absolute_queue.push(make_pair(abs(input), input));
	}
}
