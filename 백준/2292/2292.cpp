#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;
	bool check = true;
	if (num == 1) cout << 1;
	else {
		long long int minNum = 2;
		long long int maxNum=1;
		long long int minIndex = 0;
		long long int maxIndex = 1;
		int count = 1;
		while (check) {
			minNum += 6 * minIndex;
			maxNum += 6 * maxIndex;
			if (num >= minNum && num <= maxNum) {
				cout << count+1;
				break;
			}
			else {
				minIndex += 1;
				maxIndex += 1;
				count += 1;
			}
		}
	}
}