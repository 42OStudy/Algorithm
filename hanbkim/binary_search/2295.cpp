#include <iostream>
#include <algorithm>
#include <vector>


std::vector<long long> two_sum;

int main()
{
	long long	*arr;
	int	N;

	std::cin >> N;
	arr = new long long[N];	
	for (int i = 0; i < N; ++i)
		std::cin >> arr[i];
	std::sort(arr, arr + N);

	for (int i = 0; i < N; ++i)
	{
		for(int j = i; j < N; ++j)
		{
			two_sum.push_back(arr[i] + arr[j]);
		}

	}
	std::sort(two_sum.begin(), two_sum.end());
	for (int i = N - 1; i >= 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (std::binary_search(two_sum.begin(), two_sum.end(), arr[i] - arr[j]))
			{
				std::cout << arr[i];
				return 0;
			}
		}
	}
}
