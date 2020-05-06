#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	for (int i = 0; i < commands.size(); i++) {
		int start = commands[i][0]-1;
		int end = commands[i][1];
		int selectNum = commands[i][2];
		vector<int> curarray;
		for (int j = start; j < end; j++) {
			curarray.push_back(array[j]);
		}
		sort(curarray.begin(), curarray.end());
		answer.push_back(curarray[selectNum - 1]);
	}
	return answer;
}