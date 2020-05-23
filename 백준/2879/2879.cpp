#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int total;
	cin >> total;
	vector<int> arryt;
	vector<int> arry;
	for (int i = 0; i < total; i++) {
		//틀림
		int num;
		cin >> num;
		arryt.push_back(num);
	}
	for (int i = 0; i < arryt.size(); i++) {
		//올바른 탭
		int num;
		cin >> num;
		arry.push_back(num - arryt[i]);
	}
	if (total == 1) {
		cout << abs(arry[0]);
	}
	else {
		int pre = arry[0];
		int answer = 0;
		for (int i = 1; i < arryt.size(); i++) {
			if (pre >= 0) {
				if (arry[i] < 0) {
					answer += abs(pre);
					pre = arry[i];
				}
				else if (pre < arry[i]) {
					pre = arry[i];
				}
				else {
					answer += abs(pre) - abs(arry[i]);
					pre = arry[i];
				}
			}
			else {
				if (arry[i] >= 0) {
					answer += abs(pre);
					pre = arry[i];
				}
				else if (pre > arry[i]) {
					pre = arry[i];
				}
				else {
					answer += abs(pre) - abs(arry[i]);
					pre = arry[i];
				}
			}
		}
		answer += abs(pre);
		cout << answer;
	}
}