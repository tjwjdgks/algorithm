#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct compare {
	bool operator()(vector<int> a, vector<int> b) {
		return a.at(1) > b.at(1);
	}
};
int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int time = 0;
	int j = 0;
	sort(jobs.begin(), jobs.end());
	priority_queue<int, vector<vector<int>>, compare> pq;
	while (!pq.empty() || j < jobs.size()) {
		if (j < jobs.size() && time >= jobs[j][0]) {
			pq.push(jobs[j++]);
			continue;
		}
		if (!pq.empty()) {
			time += pq.top()[1];
			answer += time - pq.top()[0];
			pq.pop();
		}
		else {
			time = jobs[j][0];
		}
	}
	return answer / jobs.size();
}