#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<deque<bool>> arr(4, deque<bool>(8, false));

// N = false, S = true
// 12 = 0 
// 2와 7 신경
// dirction 0 왼 1 오
// rotate 1 시계 0 반시계;
void change(int index, int direction, bool rotate, int check) {
	if (direction == 0) {
		if (index != 0 && arr[index][6] != arr[index - 1][2]) {
			change(index - 1, 0, !rotate, check + 1);
		}
		if (check != 0) {
			if (rotate) {
				bool temp = arr[index].back();
				arr[index].pop_back();
				arr[index].push_front(temp);
			}
			else {
				bool temp = arr[index].front();
				arr[index].pop_front();
				arr[index].push_back(temp);
			}
		}
	}
	else if (direction == 1) {
		if (index != 3 && arr[index][2] != arr[index + 1][6]) {
			change(index + 1, 1, !rotate, check + 1);
		}
		if (check != 0) {
			if (rotate) {
				bool temp = arr[index].back();
				arr[index].pop_back();
				arr[index].push_front(temp);
			}
			else {
				bool temp = arr[index].front();
				arr[index].pop_front();
				arr[index].push_back(temp);
			}
		}
	}
}
int main() {
	for (int i = 0; i < 4; i++) {
		string array;
		cin >> array;
		for (int j = 0; j < array.size(); j++) {
			arr[i][j] = array[j] - '0';
		}
	}
	vector<pair<int, int>> order;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tempindex, tempd;
		cin >> tempindex >> tempd;
		order.push_back({ tempindex - 1, tempd });
	}


	for (int i = 0; i < N; i++) {
		if (order[i].second == 1) {
			change(order[i].first, 0, 1, 0);
			change(order[i].first, 1, 1, 0);
			bool temp = arr[order[i].first].back();
			arr[order[i].first].pop_back();
			arr[order[i].first].push_front(temp);
		}
		else {
			change(order[i].first, 0, 0, 0);
			change(order[i].first, 1, 0, 0);
			bool temp = arr[order[i].first].front();
			arr[order[i].first].pop_front();
			arr[order[i].first].push_back(temp);
		}
	}
	int answer = 0;
	int tnum = 1;
	for (int i = 0; i < 4; i++) {
		if (arr[i][0]) {
			answer += tnum;
		}
		tnum = tnum * 2;
	}
	cout << answer;
}