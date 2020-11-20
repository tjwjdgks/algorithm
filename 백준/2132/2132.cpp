#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10001];
int n;
int first, last;
vector<vector<int>> edge;
vector<int> firstarry;
vector<pair<int, int>> anarr;
int maxcost;
void dfs(int start, int prev, int cost) {
	if (maxcost < cost) {
		maxcost = cost;
		firstarry.clear();
		firstarry.push_back(start);
	}
	if (maxcost == cost) {
		firstarry.push_back(start);
	}
	for (auto& i : edge[start]) {
		if (i == prev)continue;
		dfs(i, start, cost + arr[i]);
	}
}
void dfs2(int start, int prev, int cost, int first) {
	if (maxcost < cost) {
		maxcost = cost;
		anarr.clear();
		anarr.push_back({ start,first });
		anarr.push_back({ first,start });
	}
	if (maxcost == cost) {
		anarr.push_back({ start,first });
		anarr.push_back({ first,start });
	}
	for (auto& i : edge[start]) {
		if (i == prev) continue;
		dfs2(i, start, cost + arr[i], first);
	}
}
int main() {
	cin >> n;
	edge.resize(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> arr[i + 1];
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> first >> last;
		edge[first].push_back(last);
		edge[last].push_back(first);
	}
	dfs(1, 1, arr[1]);
	maxcost = 0;
	for (auto& i : firstarry) {
		dfs2(i, i, arr[i], i);
	}
	sort(anarr.begin(), anarr.end());
	cout << maxcost << " " << anarr[0].first;
}