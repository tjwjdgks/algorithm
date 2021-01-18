#include <iostream>
#include <string>
using namespace std;

char rarr[1000001];
int main() {
	string arr, erase;
	cin >> arr >> erase;
	int idx = 0;
	for (int i = 0; i < arr.size(); i++) {
		rarr[idx++] = arr[i];
		if (rarr[idx - 1] == erase[erase.size() - 1]) {
			if (idx - erase.size() < 0) continue;
			int j;
			for (j = 0; j < erase.size(); j++) {
				if (rarr[idx - j - 1] != erase[erase.size() - j - 1]) break;
			}
			if (j == erase.size())
				idx = idx - erase.size();
		}
	}
	if (idx == 0)
		cout << "FRULA";
	else {
		for (int i = 0; i < idx; i++) {
			cout << rarr[i];
		}
	}
}