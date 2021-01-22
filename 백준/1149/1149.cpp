#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int a = 0;
	cin >> a;
	int rgb[1000][3] = { 0, };
	for (int i = 0; i < a; i++) {
		cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
	}
	if (a == 1) {
		cout << min(rgb[0][0], min(rgb[0][1], rgb[0][2]));
	}
	else {
		for (int i = a - 1; i > 0; i--) {
			rgb[i - 1][0] = rgb[i - 1][0] + min(rgb[i][1], rgb[i][2]);
			rgb[i - 1][1] = rgb[i - 1][1] + min(rgb[i][0], rgb[i][2]);
			rgb[i - 1][2] = rgb[i - 1][2] + min(rgb[i][1], rgb[i][0]);
		}
	}
	cout << min(rgb[0][0], min(rgb[0][1], rgb[0][2]));
	return 0;
}