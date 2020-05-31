#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	sort(citations.begin(), citations.end(), greater<int>());
	int arrynum;
	int num;
	for (int i = 0; i < citations.size(); i++) {
		arrynum = i + 1;
		num = citations[i];
		if (arrynum > num) {
			break;
		}
		answer += 1;
	}
	return answer;
}