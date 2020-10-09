#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstar(vector<vector<pair<int, int>>>& arry, int num) {
	vector<int> dist(arry.size(), INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,num });
	dist[num] = 0;
	while (!pq.empty()) {
		pair<int, int> curp = pq.top();
		pq.pop();
		for (int i = 0; i < arry[curp.second].size(); i++) {
			int nexte = arry[curp.second][i].first;
			int nextc = curp.first + arry[curp.second][i].second;
			if (nextc < dist[nexte]) {
				dist[nexte] = nextc;
				pq.push({ nextc,nexte });
			}
		}
	}
	return dist;
}
int main() {
	int N, M, X;
	cin >> N >> M >> X;
	vector<vector<pair<int, int>>> forward(N + 1), backward(N + 1);
	for (int i = 0; i < M; i++) {
		int first, second, val;
		cin >> first >> second >> val;
		forward[first].push_back({ second,val });
		backward[second].push_back({ first,val });
	}
	vector<int> toParty = dijkstar(backward, X);
	vector<int> toHome = dijkstar(forward, X);
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		if (toParty[i] + toHome[i] > answer)
			answer = toParty[i] + toHome[i];
	}
	cout << answer;
}