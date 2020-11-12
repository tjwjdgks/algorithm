#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

int main() {
	int N, L;
	cin >> N >> L;
	vector<vector<int>> arr(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	int answer = 0;
	// x ÆÇº°
	for (int i = 0; i < N; i++) {
		int count = 1;
		int checknum = arr[i][0];
		int j;
		for (j = 1; j < N; j++) {
			if (checknum == arr[i][j]) {
				count++;
			}
			else if (checknum > arr[i][j] && checknum - arr[i][j] == 1) {
				checknum = arr[i][j];
				int k = 0;
				for (k = 0; k < L; k++) {
					if (j + k >= N)break;
					if (checknum != arr[i][j + k])break;
				}
				if (k != L)break;
				else {
					j = j + k - 1;
					count = 0;
				}
			}
			else if (checknum < arr[i][j] && arr[i][j] - checknum == 1) {
				if (count < L) break;
				checknum = arr[i][j];
				count = 1;
			}
			else {
				break;
			}
		}
		if (j == N)answer++;
	}
	for (int i = 0; i < N; i++) {
		int count = 1;
		int checknum = arr[0][i];
		int j;
		for (j = 1; j < N; j++) {
			if (checknum == arr[j][i]) {
				count++;
			}
			else if (checknum > arr[j][i] && checknum - arr[j][i] == 1) {
				checknum = arr[j][i];
				int k = 0;
				for (k = 0; k < L; k++) {
					if (j + k >= N)break;
					if (checknum != arr[j + k][i])break;
				}
				if (k != L)break;
				else {
					j = j + k - 1;
					count = 0;
				}
			}
			else if (checknum < arr[j][i] && arr[j][i] - checknum == 1) {
				if (count < L) break;
				checknum = arr[j][i];
				count = 1;
			}
			else {
				break;
			}
		}
		if (j == N)answer++;
	}
	cout << answer;
}