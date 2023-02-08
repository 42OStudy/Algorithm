#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
using namespace std;

int N;
pair<int, int> meetings[100000];

bool	cmp(pair<int, int>a, pair<int, int>b)
{
	if (a.second != b.second)
		return (a.second < b.second);
	return (a.first < b.first);
}
void	get_input()
{
	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		cin >> meetings[i].first >> meetings[i].second;
	}
	sort(meetings, meetings + N, cmp);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
//	for (int i = 0; i < N; ++i) 
//	{
//		cout << meetings[i].first << ' ' << meetings[i].second << '\n';
//	}
	int ans = 0;
	int cur_time = 0;
	for (int i = 0; i < N; ++i) 
	{
		if (cur_time > meetings[i].first)
			continue ;
		++ans;
		cur_time = meetings[i].second;
	}
	cout << ans;
}
//#include <iostream>
//#include <stack>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#include <utility>
//#include <string.h>
//using namespace std;
//
//// 가장 짧은 회의시간부터 채워넣는다.
//// 이러한 반례가 있구나 :
//// 3
//// 1 6
//// 5 8
//// 7 12
//// 아래 코드 경우엔 5,8부터 넣기 때문에 오답.
//int N;
//
//vector<pair<int, int>> meetings;
//
//bool cmp(pair<int, int>a, pair<int, int>b)
//{
//	int a_gap = abs(a.first - a.second);
//	int b_gap = abs(b.first - b.second);
//	return (a_gap < b_gap);
//}
// 
//void	get_input()
//{
//	cin >> N;
//	meetings.resize(N, {0, 0});
//	for (int i = 0; i < N; ++i) 
//	{
//		cin >> meetings[i].first >> meetings[i].second;
//	}
//	sort(meetings.begin(), meetings.end(), cmp);
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	get_input();
////	for (int i = 0; i < N; ++i) 
////	{
////		cout << meetings[i].first << ' ' << meetings[i].second << '\n';
////	}
//	int meeting_cnt = 1;
//	for (int i = 1; i < N; ++i) 
//	{	
//		bool is_overlapped = false;
//		int cur_start = meetings[i].first;
//		int cur_end = meetings[i].second;
//		for (int j = 0; j < i; ++j) 
//		{
//			int before_start = meetings[j].first;
//			int before_end = meetings[j].second;
//			cout << cur_start << ' ' << cur_end << ' ' << before_start << ' ' << before_end << '\n';
//			cout << meeting_cnt << '\n';
//			cout << '\n';
//			if (cur_start > before_start && cur_start < before_end)
//			{
//				cout << "!\n";
//				is_overlapped = true;
//				break ;
//			}
//			if (cur_end > before_start && cur_start < before_start)
//			{
//				cout << "@\n";
//				is_overlapped = true;
//				break ;
//			}
//		}
//		if (!is_overlapped)
//			++meeting_cnt;
//	}
//	cout << meeting_cnt;
//}
