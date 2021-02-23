#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
bool check[8][8];
int x[4] = { 0,-1,0,1 };
int y[4] = { 1,0,-1,0 };
int main() {
	cin >> N >> M;
	map<int, pair<int, int>> m;
	vector<vector<int>> arry(N, vector<int>(M, 0));
	int pcount = 0;
	int wallcount = 0;
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tempnum;
			cin >> tempnum;
			arry[i][j] = tempnum;
			if (tempnum == 0) {
				m[pcount] = make_pair(i, j);
				pcount++;
			}
			else if (tempnum == 1) {
				wallcount++;
			}
		}
	}
	vector<int> indexarr(m.size(), 0);
	for (int i = 0; i < indexarr.size(); i++) {
		indexarr[i] = i;
	}

	for (int i = 0; i < indexarr.size()-2; i++) {
		for (int j = i + 1; j < indexarr.size()-1; j++) {
			for (int k = j + 1; k < indexarr.size(); k++) {
				vector<vector<int>> curarr(arry);
				
				curarr[m[i].first][m[i].second] = 1;
				curarr[m[j].first][m[j].second] = 1;
				curarr[m[k].first][m[k].second] = 1;
				int spreadsize = 0;
				for (int ii = 0; ii < N; ii++) {
					for (int jj = 0; jj < M; jj++) {
						if (curarr[ii][jj] == 2) {
							queue<pair<int, int>> q;
							q.push(make_pair(ii, jj));
							curarr[ii][jj] = 2;
							while (!q.empty()) {
								int cury = q.front().first;
								int curx = q.front().second;
								q.pop();
								spreadsize++;
								for (int kk = 0; kk < 4; kk++) {
									int tempy = cury + y[kk];
									int tempx = curx + x[kk];
									if (tempy >= 0 && tempx >= 0 && tempy < N && tempx < M && curarr[tempy][tempx] == 0) {
										curarr[tempy][tempx] = -1;
										q.push(make_pair(tempy, tempx));
									}
								}
							}
						}
					}
				}
				int tempanswer = N * M - (wallcount + 3) - spreadsize;
				answer = max(answer, tempanswer);
			}
		}
	}
	cout << answer;
}