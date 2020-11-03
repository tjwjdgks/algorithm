#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
	int N, K;
	cin >> N >> K;
	priority_queue<int> pq;
	vector<pair<int, int>> narry;
	vector<int> karry;
	for (int i = 0; i < N; i++) {
		int tval, tw;
		cin >> tw >> tval;
		narry.push_back({ tw,tval });
	}
	for (int i = 0; i < K; i++) {
		int tw;
		cin >> tw;
		karry.push_back(tw);
	}
	sort(narry.begin(), narry.end());
	sort(karry.begin(), karry.end());
	int index = 0;
	long long answer = 0;
	for (int i = 0; i < K; i++) {
		while (index < N && karry[i] >= narry[index].first) {
			pq.push(narry[index].second);
			index++;
		}
		if (!pq.empty()) {
			answer += pq.top();
			pq.pop();
		}
	}
	cout << answer;
}