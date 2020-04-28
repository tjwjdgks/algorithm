#include <iostream>
using namespace std;
int main() {
	int row, col;
	cin >> col >> row;
	int blind[5] = { 0, };
	char** mat = new char* [col * 5 + 1];
	for (int i = 0; i < col * 5 + 1; i++) {
		mat[i] = new char[row * 5 + 1];
		for (int j = 0; j < row * 5 + 1; j++) {
			cin >> mat[i][j];
		}
	}
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			int count = 0;
			for (int z = 0; z < 4; z++) {
				if (mat[i * 5 + 1+z][j * 5 + 1] == '*') {
					count += 1;
				}
				else break;
			}
			blind[count] += 1;
		}
	}
	for (int i = 0; i < 5; i++) {
		cout << blind[i] << " ";
	}
}