#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

bool check[101];
int answerarry[101];
int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> arry(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i < M; i++) {
		int first, end;
		cin >> first >> end;
		arry[first][end] = 1;
		arry[end][first] = 1;
	}

	for (int i = 1; i <= N; i++) {
		queue<pair<int, int>> q;
		q.push({ i, 0 });
		memset(check, 0, sizeof(check));
		check[i] = true;
		int answer = 0;
		while (!q.empty()) {
			int num = q.front().first;
			int val = q.front().second;
			q.pop();
			answer += val;
			for (int j = 1; j <= N; j++) {
				if (arry[num][j] == 1 && check[j] == false) {
					int secondnum = val + 1;
					q.push({ j,secondnum });
					check[j] = true;
				}
			}
		}
		answerarry[i] = answer;
	}
	int answerindex = -1;
	int answermin = 987654321;
	for (int i = 1; i <= N; i++) {
		if (answermin > answerarry[i]) {
			answermin = answerarry[i];
			answerindex = i;
		}
	}
	cout << answerindex;
}