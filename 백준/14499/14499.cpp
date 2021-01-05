#include <iostream>
using namespace std;



int dice[3][2];

//µ¿ ¼­ ºÏ ³²
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int arr[21][21];
int order[1001];
// ¿Þ ¿À , ¾Õ µÚ, À§ ¾Æ·¡
void rotate(int curdice[][2], int direction) {
	int tempfront = curdice[2][0];
	int tempback = curdice[2][1];
	if (direction / 2 == 0) {
		//µ¿
		if (direction % 2 == 0) {
			curdice[2][0] = curdice[0][0];
			curdice[2][1] = curdice[0][1];
			curdice[0][0] = tempback;
			curdice[0][1] = tempfront;
		}
		//¼­
		else {
			curdice[2][0] = curdice[0][1];
			curdice[2][1] = curdice[0][0];
			curdice[0][0] = tempfront;
			curdice[0][1] = tempback;
		}
	}
	else {
		//ºÏ
		if (direction % 2 == 0) {
			curdice[2][0] = curdice[1][0];
			curdice[2][1] = curdice[1][1];
			curdice[1][0] = tempback;
			curdice[1][1] = tempfront;
		}
		//³²
		else {
			curdice[2][0] = curdice[1][1];
			curdice[2][1] = curdice[1][0];
			curdice[1][0] = tempfront;
			curdice[1][1] = tempback;
		}
	}
}
int main() {
	int N, M, x, y, K;
	cin >> N >> M >> y >> x >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> order[i];
	}
	for (int i = 0; i < K; i++) {
		int tempx = x + dx[order[i] - 1];
		int tempy = y + dy[order[i] - 1];
		if (tempx >= 0 && tempx < M && tempy >= 0 && tempy < N) {
			x = tempx;
			y = tempy;
			rotate(dice, order[i] - 1);
			if (arr[y][x] == 0)
				arr[y][x] = dice[2][1];
			else {
				dice[2][1] = arr[y][x];
				arr[y][x] = 0;
			}
			cout << dice[2][0] << endl;
		}
	}
}