#include <iostream>
#include <vector>
using namespace std;
int main() {
	int a;
	cin >> a;
	vector<int> num;
	vector<int> arry;
	vector<char> s;
	int index = 0;
	for (int i = 0; i < a; i++) {
		int n;
		cin >> n;
		num.push_back(n);
	}
	for (int i = 1; i <= a; i++) {
		arry.push_back(i);
		s.push_back('+');
		while (!arry.empty() && arry.back() == num[index]) {
			arry.pop_back();
			s.push_back('-');
			index++;
		}
	}
	if (!arry.empty()) cout << "NO" << endl;
	else {
		for (int j = 0; j < s.size(); j++) {
			cout << s[j] << endl;
		}
	}
	return 0;
}