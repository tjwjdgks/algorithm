#include <iostream>
using namespace std;

int main() {
	int firstnum;
	cin >> firstnum;
	bool check = false;
	for (int i = 1; i < 8; i++) {
		int cur;
		cin >> cur;
		if (firstnum - cur == i) {
			check = true;
		}
		else if (cur - firstnum != i) {
			cout << "mixed";
			return 0;
		}	
	}
	if (check) {
		cout << "descending";
	}
	else cout << "ascending";
	return 0;
}