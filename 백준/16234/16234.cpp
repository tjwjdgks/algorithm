#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int arry[51][51];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
bool checkarr[51][51];
int main() {
	int N, L, R;
	//L이상 R이하 조건
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arry[i][j];
		}
	}
	int answer = 0;
	vector<vector<pair<int, int>>> v;
	while (true) {
		bool check = false;
		memset(checkarr, 0, sizeof(checkarr));
		v.clear();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (checkarr[i][j]) continue;
				vector<pair<int, int>> varr;
				queue<pair<int, int>> q;
				q.push({ i,j });
				checkarr[i][j] = true;
				int checknum = 0;
				int totalnum = 0;
				while (!q.empty()) {
					int cury = q.front().first;
					int curx = q.front().second;
					varr.push_back({ cury, curx });
					checknum++;
					totalnum += arry[cury][curx];
					q.pop();

					for (int k = 0; k < 4; k++) {
						int tempy = cury + dy[k];
						int tempx = curx + dx[k];
						if (tempx >= 0 && tempx < N && tempy >= 0 && tempy < N && checkarr[tempy][tempx] == false) {
							int absnum = abs(arry[cury][curx] - arry[tempy][tempx]);
							if (absnum >= L && absnum <= R) {
								q.push({ tempy,tempx });
								checkarr[tempy][tempx] = true;
								check = true;
							}
						}
					}
				}
				if (checknum == 1) continue;
				else {
					varr.push_back({ checknum,totalnum });
					v.push_back(varr);
				}
			}
		}
		for (int i = 0; i < v.size(); i++) {
			int tempcount = v[i][v[i].size() - 1].first;
			int temptotal = v[i][v[i].size() - 1].second;
			int newnum = temptotal / tempcount;
			for (int j = 0; j < v[i].size() - 1; j++) {
				arry[v[i][j].first][v[i][j].second] = newnum;
			}
		}
		if (!check) break;
		else answer++;
	}
	cout << answer;
}