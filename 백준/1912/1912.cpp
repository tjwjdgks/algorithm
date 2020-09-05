#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int inputsize;
	cin >> inputsize;
	vector<int> inputarry(inputsize);
	for (int i = 0; i < inputsize; i++) {
		int temp;
		cin >> temp;
		inputarry[i] = temp;
	}
	vector<int> curarry(inputsize, 0);
	int maxnum = -1000;
	curarry[0] = inputarry[0];
	maxnum = max(maxnum, curarry[0]);
	for (int i = 1; i < inputsize; i++) {
		if (curarry[i - 1] >= 0) {
			curarry[i] = curarry[i - 1] + inputarry[i];
			maxnum = max(maxnum, curarry[i]);
		}
		else {
			curarry[i] = inputarry[i];
			maxnum = max(maxnum, curarry[i]);
		}
	}
	cout << maxnum;
}