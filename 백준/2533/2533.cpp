#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int total;
vector<int> node[1000001];
bool check[1000001];
int dp[1000001][2];

void dfs(int num) {
	check[num] = true;
	dp[num][0] = 0;
	dp[num][1] = 1;
	for (int i = 0; i < node[num].size(); i++) {
		if (check[node[num][i]]) continue;
		dfs(node[num][i]);
		dp[num][0] += dp[node[num][i]][1];
		dp[num][1] += min(dp[node[num][i]][0], dp[node[num][i]][1]);
	}
}
int main() {
	cin >> total;
	for (int i = 0; i < total - 1; i++) {
		int first, end;
		cin >> first >> end;
		node[first].push_back(end);
		node[end].push_back(first);
	}
	dfs(1);
	int answer = min(dp[1][0], dp[1][1]);
	cout << answer;
}
