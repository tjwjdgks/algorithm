#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int R, C, T;
int arr[50][50];
int add_arr[50][50];
int airtop;
int airbottom;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int main() {
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1)
				airbottom = i;
		}
	}
	airtop = airbottom - 1;

	for (int k = 0; k < T; k++) {
		memset(add_arr, 0, sizeof(add_arr));
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (arr[i][j] != 0 && arr[i][j] != -1) {
					int directNum = 0;
					for (int a = 0; a < 4; a++) {
						int tempy = i + dy[a];
						int tempx = j + dx[a];
						if (tempy >= 0 && tempy < R && tempx >= 0 && tempx < C && arr[tempy][tempx] != -1) {
							directNum++;
							add_arr[tempy][tempx] += arr[i][j] / 5;
						}
					}
					arr[i][j] = arr[i][j] - (arr[i][j] / 5) * directNum;
				}
			}
		}
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				arr[i][j] += add_arr[i][j];
			}
		}
		// y =R x = C
		//top
		for (int i = airtop - 1; i >= 1; i--) {
			arr[i][0] = arr[i - 1][0];
		}
		for (int i = 0; i <= C - 2; i++) {
			arr[0][i] = arr[0][i + 1];
		}
		for (int i = 0; i <= airtop - 1; i++) {
			arr[i][C - 1] = arr[i + 1][C - 1];
		}
		for (int i = C - 1; i >= 2; i--) {
			arr[airtop][i] = arr[airtop][i - 1];
		}
		arr[airtop][1] = 0;
		//bottom
		int airbottom = airtop + 1;
		for (int i = airbottom + 1; i <= R - 2; i++) {
			arr[i][0] = arr[i + 1][0];
		}
		for (int i = 0; i <= C - 2; i++) {
			arr[R - 1][i] = arr[R - 1][i + 1];
		}
		for (int i = R - 1; i >= airbottom + 1; i--) {
			arr[i][C - 1] = arr[i - 1][C - 1];
		}
		for (int i = C - 1; i >= 2; i--) {
			arr[airbottom][i] = arr[airbottom][i - 1];
		}
		arr[airbottom][1] = 0;
	}
	int answer = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] != 0 && arr[i][j] != -1)
				answer += arr[i][j];
		}
	}
	cout << answer;
}