#include <iostream>
#include <vector>
using namespace std;

struct CCTV {
	int x, y, type;
};
struct CCTV cctv[8];
const int rotaion[] = { 0,4,2,4,4,1 };
int N, M;
int map[8][8];
int cctvsize;
void map_copy(int dest[8][8], int src[8][8]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dest[i][j] = src[i][j];
		}
	}
}
void update(int dir, CCTV cctv) {
	dir %= 4;
	// 0 µ¿ 1 ºÏ 2 ¼­ 3 ³²
	if (dir==0) {
		for (int x = cctv.x + 1; x < M; x++) {
			if (map[cctv.y][x] == 6) break;
			map[cctv.y][x] = -1;
		}
	}
	else if (dir == 1) {
		for (int y = cctv.y - 1; y >= 0; y--) {
			if (map[y][cctv.x] == 6) break;
			map[y][cctv.x] = -1;
		}
	}
	else if (dir == 2) {
		for (int x = cctv.x - 1; x >= 0; x--) {
			if (map[cctv.y][x] == 6) break;
			map[cctv.y][x] = -1;
		}
	}
	else if (dir == 3) {
		for (int y = cctv.y + 1; y < N; y++) {
			if (map[y][cctv.x] == 6) break;
			map[y][cctv.x] = -1;
		}
	}
}
int answer = 987654321;
void DFS(int cctvidx) {
	if (cctvidx == cctvsize) {
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0)
					count++;
			}
		}
		if (answer > count)
			answer = count;
		return;
	}
	int backup[8][8];
	int temptype = cctv[cctvidx].type;
	for (int dir = 0; dir < rotaion[temptype]; dir++) {
		map_copy(backup, map);
		if (temptype == 1) {
			update(dir, cctv[cctvidx]);
		}
		else if (temptype == 2) {
			update(dir, cctv[cctvidx]);
			update(dir + 2, cctv[cctvidx]);
		}
		else if (temptype == 3) {
			update(dir, cctv[cctvidx]);
			update(dir + 1, cctv[cctvidx]);
		}
		else if (temptype == 4) {
			update(dir, cctv[cctvidx]);	
			update(dir + 1, cctv[cctvidx]);
			update(dir + 2, cctv[cctvidx]);
		}
		else if (temptype == 5) {
			update(dir, cctv[cctvidx]);
			update(dir+1, cctv[cctvidx]);
			update(dir+2, cctv[cctvidx]);
			update(dir+3, cctv[cctvidx]);
		}
		DFS(cctvidx + 1);
		map_copy(map, backup);
	}

}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6) {
				cctv[cctvsize].y = i;
				cctv[cctvsize].x = j;
				cctv[cctvsize].type = map[i][j];
				cctvsize++;
			}
		}
	}
	DFS(0);
	cout << answer << endl;
}