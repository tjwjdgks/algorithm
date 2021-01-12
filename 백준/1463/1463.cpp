#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];
int minnum = 987654321;
int dfs(int num) {
	if (num == 1) return 0;
	if (dp[num] != 0) return dp[num];
	int minnum = 987654321;
	if (num % 2 == 0) minnum = min(minnum, dfs(num / 2) + 1);
	if (num % 3 == 0) minnum = min(minnum, dfs(num / 3) + 1);
	minnum = min(minnum, dfs(num - 1) + 1);
	return dp[num] = minnum;
}
int main() {
	int N;
	cin >> N;
	cout << dfs(N);
}