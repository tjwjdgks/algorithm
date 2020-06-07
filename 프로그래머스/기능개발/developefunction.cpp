#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int>speeds) {
	vector<int> answer;
	while (!progresses.empty()) {
		int t = (100 - progresses[0]) / speeds[0];
		int rest = (100 - progresses[0]) % speeds[0];
		if (rest != 0) {
			t += 1;
		}
		int curtotal=0;
		for (int i = 0; i < progresses.size();i++) {
			progresses[i] += speeds[i] * t;
		}
		int cur;
		for (cur = 0; cur < progresses.size(); cur++) {
			if (progresses[cur] < 100) {
				break;
			}
			curtotal++;
		}
		progresses.erase(progresses.begin(), progresses.begin() + cur);
		speeds.erase(speeds.begin(), speeds.begin() + cur);
		answer.push_back(curtotal);
	}
	return answer;
	/*
	while (!arry.empty()) {
		int curtotal =0;
		while (arry[0]<100) {
			for (int i = 0; i<arry.size();) {
				arry[i] += speeds[i];
				if (arry[i] >= 100) {
					if (i != 0) {
						arry.erase(arry.begin() + i);
						speeds.erase(speeds.begin() + i);
					}
					curtotal++;
				}
				else {
					i++;
				}
			}
		}
		answer.push_back(curtotal);
	}
	*/
}
int main() {
	solution({ 93,30,55 }, { 1,30,5 });
}