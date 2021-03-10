#include <iostream>
#include <algorithm>
using namespace std;

int K, N;
int arr[101][2];
int dp[101][100001];
int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> arr[i][0] >> arr[i][1];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j >= arr[i][0]) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i][0]] + arr[i][1]);
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[N][K];
}
