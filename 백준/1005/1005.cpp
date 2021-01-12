#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//위상정렬로 풀기
int main() {
	int T;
	cin >> T;
	int	buliding[1001];
	for (int j = 0; j < T; j++) {
		int N, K;
		cin >> N >> K;
		vector<int> arr[1001];
		int	pre[1001] = { 0, };
		for (int i = 0; i < N; i++) {
			cin >> buliding[i];
		}
		for (int i = 0; i < K; i++) {
			int X, Y;
			cin >> X >> Y;
			arr[X - 1].push_back(Y-1);
			pre[Y - 1]++;
		}
		int W;
		cin >> W;
		W--;
		queue<int> q;
		int result[1001] = { 0, };
		for (int i = 0; i < N; i++) {
			if (pre[i] == 0) q.push(i);
		}
		while (pre[W] > 0) {
			int cur = q.front();
			q.pop();
			for (int next : arr[cur]) {
				result[next] = max(result[next], result[cur] + buliding[cur]);
				if (--pre[next] == 0) q.push(next);
			}
		}
		cout << result[W] + buliding[W] << endl;
	}
}