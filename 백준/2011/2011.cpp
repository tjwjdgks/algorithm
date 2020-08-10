#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	string arry;
	cin >> arry;
	vector<int> numarry;
	for (int i = 0; i < arry.size(); i++) {
		numarry.push_back(arry[i] - '0');
	}
	if (numarry.size() == 1 && numarry[0] == 0) cout << 0;
	else {
		vector<int>numdp(arry.size() + 1, 0);
		numdp[0] = 1;
		for (int i = 1; i <= numarry.size(); i++) {
			if (numarry[i - 1] >= 1 && numarry[i - 1] <= 9) numdp[i] = (numdp[i - 1] + numdp[i]) % 1000000;
			if (i == 1) continue;
			int temp = numarry[i - 2] * 10 + numarry[i - 1];
			if (temp >= 10 && temp <= 26) numdp[i] = (numdp[i - 2] + numdp[i]) % 1000000;
		}
		cout << numdp[arry.size()];
	}
}