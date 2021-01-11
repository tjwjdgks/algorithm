#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
unsigned long long arr[10001];
vector<pair<int, int>> graph[10001];
void dfs(unsigned long long a, unsigned long long b) {
	for (const auto& i : graph[a]) {
		if (arr[i.first]) continue;
		arr[i.first] = b + i.second;
		dfs(i.first, i.second + b);
	}
}
int main() {
	string str;
	unsigned long long index = 0;	
	while (getline(cin, str)) {
		if (str.empty()) break;
		stringstream ss(str);
		long long a, b, c;
		ss >> a >> b >> c;	
		index = a;
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}
	unsigned long long maxnum = 0;
	for (unsigned long long i = 0; i < 10001; i++) arr[i] = 0;
	dfs(index, 0);
	for (unsigned long long i = 0; i < 10001; i++) {
		if (maxnum < arr[i]) {
			maxnum = arr[i];
			index = i;
		}
	}
	for (unsigned long long i = 0; i < 10001; i++) arr[i] = 0;
	maxnum = 0;
	dfs(index, 0);
	for (unsigned long long i = 0; i < 10001; i++) maxnum = max(maxnum, arr[i]);
	cout << maxnum;
}