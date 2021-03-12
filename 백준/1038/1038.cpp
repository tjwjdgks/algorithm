#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, cnt, dp[1024];

void dfs(long long num) {
	long long rest = num % 10;
	long long value = num * 10;
	for (int i = 0; i < rest; i++) {
		dp[cnt++] = value + i;
		dfs(value + i);
	}
}
int main() {
	cin >> N;
	for (int i = 0; i <= 9; i++) {
		dp[cnt++] = i;
		dfs(i);
	}
	sort(dp, dp + cnt);

	if (N < cnt)
		cout << dp[N];
	else
		cout << -1;
}