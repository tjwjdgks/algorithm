#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N, M, K;
string arry[50];
vector<int> rowzero;
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arry[i];
		int tempcount = 0;
		for (int j = 0; j < arry[i].size(); j++) {
			if (arry[i][j] == '0')
				tempcount++;
		}
		rowzero.push_back(tempcount);
	}
	cin >> K;

	int maxanswer = 0;
	for (int i = 0; i < N; i++) {
		int curzerocount = rowzero[i];
		if (curzerocount <= K && K %2  == curzerocount%2) {
			int tempnum = 0;
			for (int j = 0; j < N; j++) {
				if (arry[i] == arry[j])
					tempnum++;
			}
			if (tempnum > maxanswer)
				maxanswer = tempnum;
		}
	}
	cout << maxanswer;
}