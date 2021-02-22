#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N, M, K;
struct rotateInfo {
	int r = 0;
	int c = 0;
	int s = 0;
};
int main() {
	int answer = 987654321;
	cin >> N >> M >> K;
	vector<vector<int>> arr(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	map<int, rotateInfo> m;
	for (int i = 0; i < K; i++) {
		rotateInfo tempinfo;
		int tempr, tempc, temps;
		cin >> tempr >> tempc >> temps;
		tempinfo.r = tempr - 1;
		tempinfo.c = tempc - 1;
		tempinfo.s = temps;
		m[i] = tempinfo;
	}
	vector<int> index(K, 0);
	for (int i = 0; i < K; i++) {
		index[i] = i;
	}
	do {
		vector<vector<int>> curarr(arr);
		for (int k = 0; k < index.size(); k++) {
			rotateInfo curinfo = m[index[k]];
			int firsty = curinfo.r - curinfo.s;
			int firstx = curinfo.c - curinfo.s;
			int count = curinfo.s * 2 + 1;
			for (int t = count; t > 0; t -= 2) {
				if (t == 1) continue;
				int firstnum = curarr[firsty][firstx];
				//¿ª¼ø
				for (int tt = 0; tt < t - 1; tt++) {
					curarr[firsty + tt][firstx] = curarr[firsty + tt + 1][firstx];
				}
				for (int tt = 0; tt < t - 1; tt++) {
					curarr[firsty + t - 1][firstx + tt] = curarr[firsty + t - 1][firstx + tt + 1];
				}
				for (int tt = 0; tt < t - 1; tt++) {
					curarr[firsty + t - 1 - tt][firstx + t - 1] = curarr[firsty + t - 1 - tt - 1][firstx + t - 1];
				}
				for (int tt = 0; tt < t - 1; tt++) {
					curarr[firsty][firstx + t - 1 - tt] = curarr[firsty][firstx + t - 1 - tt - 1];
				}
				curarr[firsty][firstx + 1] = firstnum;
				firsty += 1;
				firstx += 1;
			}
		}
		for (int i = 0; i < N; i++) {
			int temptotal = 0;
			for (int j = 0; j < M; j++) {
				temptotal += curarr[i][j];
			}
			if (answer > temptotal)
				answer = temptotal;
		}
	} while (next_permutation(index.begin(), index.end()));
	cout << answer;

}