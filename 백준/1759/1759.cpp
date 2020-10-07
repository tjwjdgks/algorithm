#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<char> carry;
//시작, 마침, 모음count, 자음count
void getAnswer(int startindex, int numcount, int count, int concount, int collcount, string num) {
	if (numcount == count) {
		if (concount >= 1 && collcount >= 2) {
			cout << num << endl;
			return;
		}
	}
	for (int i = startindex + 1; i < carry.size(); i++) {
		if (carry[i] == 'a' || carry[i] == 'e' || carry[i] == 'i' || carry[i] == 'o' || carry[i] == 'u') {
			getAnswer(i, numcount + 1, count, concount + 1, collcount, num + carry[i]);
		}
		else {
			getAnswer(i, numcount + 1, count, concount, collcount + 1, num + carry[i]);
		}
	}
	return;
}
int main() {
	int L, C;
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char tempc;
		cin >> tempc;
		carry.push_back(tempc);
	}
	sort(carry.begin(), carry.end());
	getAnswer(-1, 0, L, 0, 0, "");
}