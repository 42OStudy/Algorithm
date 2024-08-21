#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int dp[100001];
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<pair<int, int> >item;
	item.reserve(200);
	for (int i = 0; i < n; ++i)
	{
		pair<int, int> val;
		cin >> val.first >> val.second;
		item.push_back(val);
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = k; j >= item[i].first; --j)
		{
			dp[j] = max(dp[j], dp[j - item[i].first] + item[i].second);
		}
	}
	cout << dp[k];

	return (0);
}

// int weight_cnt[200000];

// int get_max_val(vector<pair<int, int> > &item, int start)
// {
// 	int ret = 0;
// 	for (int i = start; i < start + weight_cnt[item[start].first]; ++i)
// 	{
// 		ret = max(ret, item[i].second);
// 	}
// 	return (ret);
// }

// int main(void)
// {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);

// 	int n, k;
// 	cin >> n >> k;
// 	vector<pair<int , int> > item;
// 	item.reserve(200);
// 	for (int i = 0; i < n; ++i)
// 	{
// 		pair<int, int> value;
// 		cin >> value.first >> value.second;
// 		++weight_cnt[value.first];
// 		item.push_back(value);
// 	}
// 	sort(item.begin(), item.end());
// 	// for (auto i : item)
// 	// 	cout << i.first << ' ' << i.second << '\n';
// 	vector<int> ans_vec;
// 	ans_vec.resize(200, 0);
// 	int i = 0;
// 	while (i < n)
// 	{
// 		int ans = 0;
// 		int cur_weight = item[i].first;
// 		// int cur_val = get_max_val(item, i);
// 		int cur_val = item[i].second;
// 		int j = i + 1;
// 		while (j < n)
// 		{
// 			cur_weight += item[j].first;
// 			// cur_val += get_max_val(item, j);
// 			cur_val += item[j].second;
// 			if (cur_weight > k)
// 				break;
// 			ans = max(ans, cur_val);
// 			// j += weight_cnt[item[j].first];
// 			++j;
// 		}
// 		ans_vec.push_back(ans);
// 		// i += weight_cnt[item[i].first];
// 		++i;
// 	}
// 	cout << *max_element(ans_vec.begin(), ans_vec.end());
// 	return (0);
// }