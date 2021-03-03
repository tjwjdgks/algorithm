#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

deque<int> arr[10][10];
int insertGround[10][10];
int ground[10][10];
int N, M, K;
int dy[] = { -1,-1,-1,0,0,1,1,1 };
int dx[] = { -1,0,1,-1,1,-1,0,1 };
void SpringAndSummer() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j].size() == 0) continue;
			int deathTree = 0;
			int indexsize = arr[i][j].size();
			for (int k = 0; k < indexsize; k++) {
				int age = arr[i][j].front();
				arr[i][j].pop_front();
				if (ground[i][j] >= age) {
					ground[i][j] -= age;
					arr[i][j].push_back(age + 1);
				}
				else {
					deathTree += age / 2;
				}
			}
			ground[i][j] += deathTree;
		}
	}
}
void FallAndWinder() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ground[i][j] += insertGround[i][j];
			if (arr[i][j].size() == 0) continue;
			for (int k = 0; k < arr[i][j].size(); k++) {
				if (arr[i][j][k] % 5 == 0) {
					for (int a = 0; a < 8; a++) {
						int tempy = i + dy[a];
						int tempx = j + dx[a];
						if (tempy >= 0 && tempx >= 0 && tempy < N && tempx < N) {
							arr[tempy][tempx].push_front(1);
						}
					}
				}
			}
		}
	}
}
int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> insertGround[i][j];
			ground[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		int r, c, year;
		cin >> r >> c >> year;
		arr[r - 1][c - 1].push_back(year);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j].size() == 0) continue;
			sort(arr[i][j].begin(), arr[i][j].end());
		}
	}

	for (int i = 0; i < K; i++) {
		SpringAndSummer();
		FallAndWinder();
	}
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			answer += arr[i][j].size();
		}
	}
	cout << answer;
}
