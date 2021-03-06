#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, T;
struct Tarr {
	int xi, di, ki;
};
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
// di 0 시계 1 반시계
vector<deque<int>> arr;
void arrrotate(int index, int dir, int count) {
	for (int i = 0; i < count; i++) {
		int tempnum = -1;
		//시계
		if (dir == 0) {
			tempnum = arr[index].back();
			arr[index].pop_back();
			arr[index].push_front(tempnum);
		}
		//반시계
		else {
			tempnum = arr[index].front();
			arr[index].pop_front();
			arr[index].push_back(tempnum);
		}
	}
}
void dfs(int y, int x,int num) {
	for (int i = 0; i < 4; i++) {
		int tempy = y + dy[i];
		int tempx = x + dx[i];
		if (tempx == -1)
			tempx = M - 1;
		else if (tempx == M)
			tempx = 0;
		if (tempy >= 0 && tempx >= 0 && tempy < N && tempx < M && arr[tempy][tempx] == num) {
			arr[y][x] = 0;
			arr[tempy][tempx] = 0;
			dfs(tempy, tempx, num);
		}
	}
}
bool find() {
	bool flag = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] != 0) {
				dfs(i, j, arr[i][j]);
				if (arr[i][j] == 0)
					flag = true;
			}
		}
	}
	return flag;
}
int main() {
	cin >> N >> M >> T;
	arr.resize(N, deque<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	vector<Tarr> tindex;
	int answer = 0;
	for (int i = 0; i < T; i++) {
		Tarr tempt;
		cin >> tempt.xi >> tempt.di >> tempt.ki;
		tindex.push_back(tempt);
	}

	for (int i = 0; i < tindex.size(); i++) {
		int range = tindex[i].xi;	
		for (int j = 0; j < N; j++) {
			if ((j + 1) % range == 0) {
				arrrotate(j, tindex[i].di, tindex[i].ki);
			}
		}
		bool flag = find();
		if (flag == false) {
			int count = 0;
			int sum = 0;
			for (int y = 0; y < N; y++) {
				for (int x = 0; x < M; x++) {
					if (arr[y][x] != 0) {
						count++;
						sum += arr[y][x];
					}
				}
			}
			if (count == 0) break;
			double average = (double)sum / count;
			for (int y = 0; y < N; y++) {
				for (int x = 0; x < M; x++) {
					if (arr[y][x] != 0 && arr[y][x] < average)
						arr[y][x]++;
					else if (arr[y][x] != 0 && arr[y][x] > average)
						arr[y][x] --;
				}
			}
		}
	}
	answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] != 0) answer += arr[i][j];
		}
	}
	cout << answer;
}