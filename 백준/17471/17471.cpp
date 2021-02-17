#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


int N;
int arr[10][10];
int parr[10];
bool visited[10];
int dfs(int v, vector<int>& target, int type) {
	int count = 1;
	visited[v] = true;
	for (int i = 0; i < N; i++) {
		if (target[i] == type && arr[v][i] == 1 && visited[i] == false)
			count += dfs(i, target, type);
	}
	return count;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> parr[i];
	}
	for (int i = 0; i < N; i++) {
		int tempNum = -1;
		cin >> tempNum;
		for (int j = 0; j < tempNum; j++) {
			int nearNum = -1;
			cin >> nearNum;
			arr[i][nearNum - 1] = 1;
		}
	}
	int answer = 987654321;
	for (int i = 1; i <= N - 1; i++) {
		vector<int> targetArry(i, 0);
		for (int k = i + 1; k <= N; k++) {
			targetArry.push_back(1);
		}
		do {
			int firstidx = -1;
			int secondidx = -1;
			for (int j = 0; j < N; j++) {
				if (targetArry[j] == 0)
					firstidx = j;
				else
					secondidx = j;
				if (firstidx != -1 && secondidx != -1) break;
			}
			int firstcnt = 0;
			int secondcnt = 0;
			int firsttotal = 0;
			int secondtotal = 0;
			memset(visited, 0, sizeof(visited));
			firstcnt = dfs(firstidx, targetArry, 0);
			memset(visited, 0, sizeof(visited));
			secondcnt = dfs(secondidx, targetArry, 1);
			if (firstcnt == i && secondcnt == N - i) {
				for (int i = 0; i < targetArry.size(); i++) {
					if (targetArry[i] == 0)
						firsttotal += parr[i];
					else
						secondtotal += parr[i];
				}
				if (answer > abs(firsttotal - secondtotal))
					answer = abs(firsttotal - secondtotal);
			}

		} while (next_permutation(targetArry.begin(), targetArry.end()));
	}
	if (answer == 987654321)
		cout << -1;
	else cout << answer;
}