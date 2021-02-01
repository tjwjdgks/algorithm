#include <iostream>
#include <vector>
using namespace std;

int N, M, D;
int getAttack(int first, int second, int third, vector<vector<int>> curarr) {
	int y = N;
	int totalnum = 0;
	for (int i = 0; i < N; i++) {
		//사정거리
		bool check[3] = { false,false,false };
		int tempx[3] = { 0,0,0 };
		int tempy[3] = { 0,0,0 };
		for (int j = 1; j <= D; j++) {			
			int x = -1;
			for (int k = 0; k < 3; k++) {
				if (check[k]) continue;
				if (k == 0) x = first;
				else if (k == 1) x = second;
				else x = third;
				for (int left = 0; left < M; left++) {
					int xgap = abs(left - x);
					if (xgap >= j) continue;
					int cury = j - xgap;
					if (y - cury >= 0 && curarr[y-cury][left] == 1) {
						check[k] = true;
						tempx[k] = left;
						tempy[k] = y - cury;
						break;
					}
				}
			}
			if (check[0] && check[1] && check[2]) break;
		}
		for (int j = 0; j < 3; j++) {
			if (check[j] && curarr[tempy[j]][tempx[j]] == 1) {
				totalnum++;
				curarr[tempy[j]][tempx[j]] = 0;
			}
		}
		y--;
	}
	return totalnum;
}
int main() {
	cin >> N >> M >> D;
	vector<vector<int>> arr(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	// 궁수 postion
	int max = 0;
	for(int i=0; i<M-2;i++){
		for (int j = i+1; j < M - 1; j++) {
			for (int k = j + 1; k < M; k++) {
				int curNum = getAttack(i, j, k,arr);
				if (curNum > max) max = curNum;
			}
		}
	}
	cout << max;
}