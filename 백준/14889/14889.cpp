#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int answer = 987654321;
	int N;
	cin >> N;
	vector<vector<int>> arr(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}
	vector<int> temparr1;
	vector<int> temparr2;
	for (int i = 0; i < (1 << N); i++) {
		temparr1.clear();
		temparr2.clear();
		for (int j = 0; j < N; j++) {
			if ((i & (1 << j)) == 0)
				temparr1.push_back(j);
			else temparr2.push_back(j);
		}
		if (temparr1.size() != temparr2.size())continue;
		int temptotal1 = 0;
		int temptotal2 = 0;
		for (int k = 0; k < temparr1.size(); k++) {
			for (int k2 = 0; k2 < temparr1.size(); k2++) {
				if (k == k2) continue;
				temptotal1 += arr[temparr1[k]][temparr1[k2]];
				temptotal2 += arr[temparr2[k]][temparr2[k2]];
			}
		}
		int diff = abs(temptotal1 - temptotal2);
		if (answer > diff)
			answer = diff;
	}
	cout << answer;
}