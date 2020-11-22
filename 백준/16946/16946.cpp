#include<iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

int arr[1001][1001];
int valarr[1001][1001];
int arrx[4] = { 0,1,0,-1 };
int arry[4] = { 1,0,-1,0 };
int N, M;
int maxcount;
void dfs(int y, int x, int index) {
	valarr[y][x] = index;
	maxcount++;
	for (int i = 0; i < 4; i++) {
		int tempy = y + arry[i];
		int tempx = x + arrx[i];
		if (tempy >= 0 && tempx >= 0 && tempy < N && tempx < M) {
			if (arr[tempy][tempx] == 0 && valarr[tempy][tempx] == 0)
				dfs(tempy, tempx, index);
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string sarr;
		cin >> sarr;
		for (int j = 0; j < M; j++) {
			arr[i][j] = sarr[j] - '0';
		}
	}
	int index = 0;
	map<int, int> m;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0 && valarr[i][j] == 0) {
				dfs(i, j, ++index);
				m.insert({ index,maxcount });
				maxcount = 0;
			}
		}
	}
	set<int> areacheck;
	vector<vector<int>> area(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) continue;
			else {
				int sum = 1;
				for (int k = 0; k < 4; k++) {
					int tempy = i + arry[k];
					int tempx = j + arrx[k];
					if (tempy >= 0 && tempx >= 0 && tempy < N && tempx < M) {
						if (arr[tempy][tempx] == 0) {
							areacheck.insert(valarr[tempy][tempx]);
						}
					}
				}
				for (auto z : areacheck) {
					sum += m[z];
				}
				arr[i][j] = sum % 10;
				areacheck.clear();
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}

}