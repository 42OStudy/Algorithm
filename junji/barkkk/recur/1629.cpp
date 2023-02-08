#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;
using ll = long long;
//typedef long long ll;

ll A, B, C;
ll recur(ll A, ll B, ll C)
{
	if (B == 1)
		return A % C;
	ll half = recur(A, B / 2, C);
	ll remainder = half * half % C;
	if (B % 2) 
		return (remainder * A % C);
	return (remainder);

}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> A >> B >> C;
  cout << recur(A, B, C);
}
/*
 * 1. 첫번째 풀이
long long recur(int A, int B, int C)
{
	if (B == 1)
		return A % C;
	if (B % 2)
		return (recur(A, B / 2, C) * recur(A, B / 2, C) * A % C);
	return (recur(A, B / 2, C) * recur(A, B / 2, C) % C);
}
1. 틀린 이유: 홀수 일 때, 마지막에만 *A를 곱해줘야 하는데, 매 호출시마다 A를 곱해준다.
*/

/*
 * 2. 두번쨰 풀이
ll recur(ll A, ll B, ll C)
{
	if (B == 1)
		return A % C;
	ll remainder = recur(A, B / 2, C) * recur(A, B / 2, C) % C;
	if (B % 2) 
		return (remainder * A % C);
	return (remainder);
}
1. 틀린이유 : remainder에 재귀 함수를 2개 사용하게 되면, 연산량이 2배로 증가하기 때문에 시간초과에 걸린다.
*/

/* typedef vs using 
 * 1. 대체로 동일한 기능을 제공하지만, 문법상 미묘한 차이가 있다.
 * 2. typedef는 c와 c++ 호환이 가능하지만, using 그렇지 않다.
 * 3. using은 템플릿 사용에서 이점이 있다.
 * 4. typedef선언은 init_statement이므로 초기화문을 허용하지만, using은 alias-declaration이므로 초기화문을 사용할 수는 없다.
 */
