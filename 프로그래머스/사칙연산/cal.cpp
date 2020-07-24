#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int solution(vector<string>arr) {
	int answer = 1;
	int numsize = arr.size() / 2 + 1;

	vector<vector<int>> dp_max(200, vector<int>(200, -10000));
	vector<vector<int>> dp_min(200, vector<int>(200, 10000));

	for (int i = 0; i < numsize; i++) {
		dp_max[i][i] = stoi(arr[i * 2]);
		dp_min[i][i] = stoi(arr[i * 2]);
	}
	for (int cal = 1; cal < numsize; cal++) {
		for (int i = 0; i < numsize - cal; i++) {
			int j = i + cal;
			for (int k = i; k < j; k++) {
				if (arr[k * 2 + 1] == "-") {
					dp_max[i][j] = max(dp_max[i][k] - dp_min[k + 1][j], dp_max[i][j]);
					dp_min[i][j] = min(dp_min[i][k] - dp_max[k + 1][j], dp_min[i][j]);
				}
				else if (arr[k * 2 + 1] == "+") {
					dp_max[i][j] = max(dp_max[i][k] + dp_max[k + 1][j], dp_max[i][j]);
					dp_min[i][j] = min(dp_min[i][k] + dp_min[k + 1][j], dp_min[i][j]);
				}
			}
		}
	}
	answer = dp_max[0][numsize - 1];
	return answer;
}
