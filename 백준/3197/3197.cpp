#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#define Max 1500
using namespace std;
int R, C;
bool Visit[Max][Max];
char Map[Max][Max];
bool check;

int dy[4] = { 0,-1,0,1 };
int dx[4] = { -1,0,1,0 };
queue<pair<int, int>> Swan_q, Swan_nq, W_q, W_nq;
pair<int, int> Swan;
void Water_bfs() {
	while (!W_q.empty()) {
		int cury = W_q.front().first;
		int curx = W_q.front().second;
		W_q.pop();
		for (int i = 0; i < 4; i++) {
			int tempy = cury + dy[i];
			int tempx = curx + dx[i];
			if (tempy >= 0 && tempx >= 0 && tempy < R && tempx < C) {
				if (Map[tempy][tempx] == 'X') {
					Map[tempy][tempx] = '.';
					W_nq.push({ tempy,tempx });
				}
			}
		}
	}
}
void Swan_bfs() {
	while (!Swan_q.empty() && check == false) {
		int cury = Swan_q.front().first;
		int curx = Swan_q.front().second;
		Swan_q.pop();
		for (int i = 0; i < 4; i++) {
			int tempy = cury + dy[i];
			int tempx = curx + dx[i];
			if (tempy >= 0 && tempx >= 0 && tempy < R && tempx < C) {
				if (Visit[tempy][tempx] == false) {
					if (Map[tempy][tempx] == '.') {
						Visit[tempy][tempx] = true;
						Swan_q.push({ tempy,tempx });
					}
					else if (Map[tempy][tempx] == 'L') {
						Visit[tempy][tempx] = true;
						check = true;
						break;
					}
					else if (Map[tempy][tempx] == 'X') {
						Visit[tempy][tempx] = true;
						Swan_nq.push({ tempy,tempx });
					}
				}
				
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> Map[i][j];
			if (Map[i][j] != 'X') W_q.push({ i,j });
			if (Map[i][j] == 'L') {
				Swan.first = i;
				Swan.second = j;
			}
		}
	}
	int day = 0;
	Swan_q.push(Swan);
	Visit[Swan.first][Swan.second] = true;
	while (!check) {
		Swan_bfs();
		if (check == false) {
			Water_bfs();
			W_q = W_nq;
			Swan_q = Swan_nq;
			while (!Swan_nq.empty()) Swan_nq.pop();
			while (!W_nq.empty()) W_nq.pop();
			day++;
		}
	}
	cout << day;
}