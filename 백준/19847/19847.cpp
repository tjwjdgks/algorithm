#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main() {
	int total;
	cin >> total;
	vector<int> totalarry(total, 0);
	for (int i = 0; i < total; i++) {
		int tempnum;
		cin >> tempnum;
		totalarry[i] = tempnum;
	}
	vector<int> answercount(totalarry[0], 1);
	double firstdiv = (double)1 / totalarry[0];
	int maxindex = totalarry[0];
	for (int i = 1; i < total; i++) {
		if (maxindex > totalarry[i]) {
			for (int j = totalarry[i]; j < maxindex; j++) {
				int temp = j % totalarry[i];
				answercount[temp] += answercount[j];
			}
			maxindex = totalarry[i];
		}
	}
	double answer = 0;
	for (int i = 0; i < maxindex; i++) {
		answer += i * (firstdiv * answercount[i]);
	}
	printf("%.12f", answer);
}