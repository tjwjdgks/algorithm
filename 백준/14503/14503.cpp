#include <iostream>
#include <vector>
using namespace std;

int N, M;
int r, c, d;

//0 ºÏ 1 ¼­ 2 ³² 3 µ¿
int x[4] = { 0,-1,0,1 };
int y[4] = { -1,0,1,0 };
int arry[51][51];
int answer = 0;
void clean(int y, int x) {
	arry[y][x] = -1;
	answer++;
}
int main() {
	cin >> N >> M;
	cin >> r >> c >> d;
	if (d == 1)
		d = 3;
	else if (d == 3)
		d = 1;
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < M;j++) {
			cin >> arry[i][j];
		}
	}
	bool startflag = true;
	bool step1 = false;
	bool step2 = false;
	int count = 0;
	while (startflag) {
		if (step1==false) {
			step1 = true;
			clean(r, c);
			count =0;
		}
		int tempy = r + y[(d + 1) % 4];
		int tempx = c + x[(d + 1) % 4];
		if (arry[tempy][tempx] == 0) {
			step1 = false;
			r = tempy;
			c = tempx;
			d++;
			d = d % 4;
			continue;
		}
		else {
			if (count == 4) {
				count = 0;
				int tty = r + y[(d + 2) % 4];
				int ttx = c + x[(d + 2) % 4];
				if (arry[tty][ttx] == 1) break;
				else {
					r = tty;
					c = ttx;
					continue;
				}
			}
			else {
				count++;
				d++;
				d = d % 4;
			}
		}
	}
	cout << answer;
}