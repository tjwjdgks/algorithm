#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;
//¿Þ ¾Æ·¡ ¿À À§
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int main() {
	int N, K, L;
	cin >> N >> K;
	vector<vector<bool>> arr(N + 1, vector<bool>(N + 1, false));
	vector<vector<bool>> check(N + 1, vector<bool>(N + 1, false));
	for (int i = 0; i < K; i++) {
		int tempx, tempy;
		cin >> tempy >> tempx;
		arr[tempy][tempx] = true;
	}
	cin >> L;
	queue<pair<int, int>> orderarr;
	for (int i = 0; i < L; i++) {
		int countV;
		char directionC;
		cin >> countV >> directionC;
		orderarr.push({ countV,directionC });
	}
	int answer = 0;
	int direction = 0;
	deque<pair<int, int>> snake;
	snake.push_back({ 1,1 });
	while (1) {
		answer++;
		pair<int, int> head = snake.back();
		pair<int, int> curhead = { head.first + dy[direction],head.second + dx[direction] };
		if (!(curhead.first >= 1 && curhead.first <= N && curhead.second >= 1 && curhead.second <= N) || check[curhead.first][curhead.second]) {
			cout << answer;
			break;
		}
		check[curhead.first][curhead.second] = true;
		snake.push_back(curhead);
		if (arr[curhead.first][curhead.second])
			arr[curhead.first][curhead.second] = false;
		else {
			pair<int, int> tail = snake.front();
			check[tail.first][tail.second] = false;
			snake.pop_front();
		}
		if (!orderarr.empty() && orderarr.front().first == answer) {
			if (orderarr.front().second == 'L') {
				direction = (direction + 3) % 4;
			}
			else {
				direction = (direction + 1) % 4;
			}
			orderarr.pop();
		}

	}
}