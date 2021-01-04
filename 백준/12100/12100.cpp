#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

//À§ ¿À ¾Æ ¿Þ
void move(int direction, vector<vector<int>>& arr);
int getAnswer(int count, vector<vector<int>> arr) {
	if (count == 5) {
		int maxinum = 0;
		for (int i = 0; i < arr.size(); i++) {
			for (int j = 0; j < arr.size(); j++) {
				if (maxinum < arr[i][j])
					maxinum = arr[i][j];
			}
		}
		return maxinum;
	}
	int maxnum = 0;
	for (int i = 0; i < 4; i++) {
		vector<vector<int>> temparr = arr;
		move(i, temparr);
		maxnum = max(maxnum, getAnswer(count + 1, temparr));
	}
	return maxnum;
}
void move(int direction, vector<vector<int>>& arr) {
	deque<int> d;
	if (direction == 0) {
		//x
		for (int i = 0; i < arr.size(); i++) {
			d.clear();
			//y
			for (int j = 0; j < arr.size(); j++) {
				if (arr[j][i] != 0) {
					d.push_back(arr[j][i]);
					arr[j][i] = 0;
				}
			}
			int temparrindex = 0;
			while (!d.empty()) {
				if (d.size() >= 2 && d[0] == d[1]) {
					arr[temparrindex][i] = d[0] * 2;
					d.pop_front();
					d.pop_front();
					temparrindex++;
				}
				else {
					arr[temparrindex][i] = d.front();
					d.pop_front();
					temparrindex++;
				}
			}
		}
	}
	//¿À
	else if (direction == 1) {
		//y
		for (int i = 0; i < arr.size(); i++) {
			d.clear();
			//x
			for (int j = arr.size() - 1; j >= 0; j--) {
				if (arr[i][j] != 0) {
					d.push_back(arr[i][j]);
					arr[i][j] = 0;
				}
			}
			int temparrindex = arr.size() - 1;
			while (!d.empty()) {
				if (d.size() >= 2 && d[0] == d[1]) {
					arr[i][temparrindex] = d[0] * 2;
					d.pop_front();
					d.pop_front();
					temparrindex--;
				}
				else {
					arr[i][temparrindex] = d.front();
					d.pop_front();
					temparrindex--;
				}
			}
		}
	}
	//¾Æ
	else if (direction == 2) {
		//x
		for (int i = 0; i < arr.size(); i++) {
			d.clear();
			//y
			for (int j = arr.size() - 1; j >= 0; j--) {
				if (arr[j][i] != 0) {
					d.push_back(arr[j][i]);
					arr[j][i] = 0;
				}
			}
			int temparrindex = arr.size() - 1;
			while (!d.empty()) {
				if (d.size() >= 2 && d[0] == d[1]) {
					arr[temparrindex][i] = d[0] * 2;
					d.pop_front();
					d.pop_front();
					temparrindex--;
				}
				else {
					arr[temparrindex][i] = d.front();
					d.pop_front();
					temparrindex--;
				}
			}
		}
	}
	//¿Þ
	else {
		//y
		for (int i = 0; i < arr.size(); i++) {
			d.clear();
			//x
			for (int j = 0; j < arr.size(); j++) {
				if (arr[i][j] != 0) {
					d.push_back(arr[i][j]);
					arr[i][j] = 0;
				}
			}
			int temparrindex = 0;
			while (!d.empty()) {
				if (d.size() >= 2 && d[0] == d[1]) {
					arr[i][temparrindex] = d[0] * 2;
					d.pop_front();
					d.pop_front();
					temparrindex++;
				}
				else {
					arr[i][temparrindex] = d.front();
					d.pop_front();
					temparrindex++;
				}
			}
		}
	}
}

int main() {
	int N;
	cin >> N;
	vector<vector<int>> arr(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	int answer = getAnswer(0, arr);
	cout << answer;
}