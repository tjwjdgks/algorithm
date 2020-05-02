#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int getAnswer(vector<vector<int>> p) {
	int maxNum = 0;
	for (int i = 0; i < p.size(); i++) {
		if (p[i][0] == 1) {
			maxNum = 1;
		}
	}
	for (int i = 0; i < p[0].size(); i++) {
		if (p[0][i] == 1) {
			maxNum = 1;
		}
	}
	for (int i = 1; i < p.size(); i++) {
		for (int j = 1; j < p[i].size(); j++) {
			if (p[i][j] != 0) {
				p[i][j] = min(p[i - 1][j - 1], min(p[i - 1][j], p[i][j - 1]))+1;
			}
			maxNum = max(maxNum, p[i][j]);
		}
	}
	return maxNum;
}
int main() {
	vector<int> answerArry;
	while (true) {
		int n, m;
		vector<vector<int>> p;
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			vector<int> v;
			for (int j = 0; j < m; j++) {
				int curnum;
				cin >> curnum;
				v.push_back(curnum);
			}
			p.push_back(v);
		}
		int answerNum = getAnswer(p);
		answerArry.push_back(answerNum);
	}
	for (int i = 0; i<answerArry.size(); i++) {
		cout << answerArry[i] << endl;
	}
}