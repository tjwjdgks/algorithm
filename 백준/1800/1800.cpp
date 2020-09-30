#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;
vector<pair<int, int>> edge[1001];
int N, P, K;
int dist[1001];
//다익스트라
bool dijkstra(int num) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,1 });
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int index = pq.top().second;
		pq.pop();
		if (dist[index] < cost) continue;
		for (auto i : edge[index]) {
			int tempindex = i.first;
			int tempcost = cost + (i.second > num);
			if (tempcost < dist[tempindex]) {
				dist[tempindex] = tempcost;
				pq.push({ -tempcost,tempindex });
			}
		}
	}
	return dist[N] <= K;
}
//다익스트라 이용
// 막 힐때 다른 방향으로 생각 전환, 최소의 값을 찾기
int main() {
	cin >> N >> P >> K;
	for (int i = 0; i < P; i++) {
		int first, end, value;
		cin >> first >> end >> value;
		edge[first].push_back({ end,value });
		edge[end].push_back({ first,value });
	}
	int answer = -1;
	int minnum = 0;
	int maxnum = 1000000000;
	while (minnum <= maxnum) {
		int mid = (minnum + maxnum) / 2;
		if (dijkstra(mid)) {
			answer = mid;
			maxnum = mid - 1;
		}
		else {
			minnum = mid + 1;
		}
	}
	cout << answer;
}