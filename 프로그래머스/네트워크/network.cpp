#include <string>
#include <vector>
using namespace std;
int getAnswer(int n, vector<vector<int>>& computers) {
	if (computers[n][n] != 1) return 0;
	computers[n][n] = 0;
	int answer = 1;
	int i;
	for (i = 0; i < computers[n].size(); i++) {
		if (computers[n][i] == 1) {
			computers[n][i] == 0;
			computers[i][n] == 0;
			answer += getAnswer(i, computers);
		}
	}
	if (i == computers[n].size()) return answer;
}
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	vector<int> answerArry;
	for (int i = 0; i < computers.size(); i++) {
		int answerN = getAnswer(i, computers);
		if (answerN != 0) answerArry.push_back(answer);
	}
	answer = answerArry.size();
	return answer;
}