#include <iostream>
using namespace std;

int N;
int dp[17][17][3];
int check[17][17];
int arry[17][17];

// flags 0 가로 1세로 2 대각
int getAnswer(int endy, int endx, int flags) {
	if (endy == N - 1 && endx == N - 1) return 1;
	if (endy < 0 || endx < 0 || endy >= N || endx >= N) return 0;
	if (dp[endy][endx][flags] != 0) return dp[endy][endx][flags];
	check[endy][endx] = true;
	if (flags == 0) {
		if (arry[endy][endx + 1] != 1) dp[endy][endx][flags] += getAnswer(endy, endx + 1, 0);
		if (arry[endy][endx + 1] != 1 && arry[endy + 1][endx + 1] != 1 && arry[endy + 1][endx] != 1)
			dp[endy][endx][flags] += getAnswer(endy + 1, endx + 1, 2);
	}
	else if (flags == 1) {
		if (arry[endy + 1][endx] != 1) dp[endy][endx][flags] += getAnswer(endy + 1, endx, 1);
		if (arry[endy][endx + 1] != 1 && arry[endy + 1][endx + 1] != 1 && arry[endy + 1][endx] != 1)
			dp[endy][endx][flags] += getAnswer(endy + 1, endx + 1, 2);
	}
	else {
		if (arry[endy][endx + 1] != 1) dp[endy][endx][flags] += getAnswer(endy, endx + 1, 0);
		if (arry[endy + 1][endx] != 1) dp[endy][endx][flags] += getAnswer(endy + 1, endx, 1);
		if (arry[endy][endx + 1] != 1 && arry[endy + 1][endx + 1] != 1 && arry[endy + 1][endx] != 1)
			dp[endy][endx][flags] += getAnswer(endy + 1, endx + 1, 2);
	}
	return dp[endy][endx][flags];
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arry[i][j];
		}
	}
	int a = getAnswer(0, 1, 0);
	cout << a;
}