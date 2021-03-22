#include <iostream>
using namespace std;

const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,-1,0,1 };
int main() {
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	int board[50][5];
	for (int i = 0; i <= (r2 - r1); i++) {
		for (int j = 0; j <= (c2 - c1); j++) {
			board[i][j] = 0;
		}
	}
	int y = 0, x = 0;
	int dir = 3;
	int count = 0, num = 1, dcount = 1;
	while (!board[r2 - r1][0] || !board[0][0] || !board[0][c2 - c1] || !board[r2 - r1][c2 - c1]) {
		if (y - r1 >= 0 && y-r1 <= (r2 - r1) && x - c1 >= 0 && x <= (c2 - c1))
			board[y - r1][x - c1] = num;
		count++;
		num++;
		y = y + dy[dir];
		x = x + dx[dir];
		if (count == dcount) {
			count = 0;
			dir = (dir + 1) % 4;
			if (dir == 1 || dir == 3)
				dcount += 1;
		}
	}
	count = 0;
	while (num) {
		num /= 10;
		count++;
	}
	for (int i = 0; i <= (r2 - r1); ++i) {
		for (int j = 0; j <= (c2 - c1); ++j) {
			printf("%*d ", count, board[i][j]);
		}
		cout << "\n";
	}
	return 0;
}