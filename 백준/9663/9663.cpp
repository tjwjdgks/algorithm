#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int boardy[15];
int counts;
int N;
bool checknum(int range) {
	for (int i = 0; i < range; i++) {
		if (boardy[i] == boardy[range] || range - i == abs(boardy[i] - boardy[range]))
			return false;
	}
	return true;
}
void N_Queen(int num) {
	if (num == N) {
		counts++;
	}
	for (int i = 0; i < N; i++) {
		boardy[num] = i;
		if (checknum(num)) {
			N_Queen(num + 1);
		}
	}
}
int main() {
	cin >> N;
	N_Queen(0);
	cout << counts;
}