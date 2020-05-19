#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int main() {
	while (true) {
		char input[101];
		cin.getline(input, 101);
		if (!strcmp(input, "."))break;
		vector<char> arry;
		bool check = true;
		for (int i = 0; i < strlen(input); i++) {
			if (input[i] == '(' || input[i] == '[') arry.push_back(input[i]);
			else if (input[i] == ')') {
				if (!arry.empty() && arry.back() == '(') arry.pop_back();
				else {
					check = false;
					cout << "no" << endl;
					break;
				}
			}
			else if (input[i] == ']') {

				if (!arry.empty() && arry.back() == '[') arry.pop_back();
				else {
					check = false;
					cout << "no" << endl;
					break;
				}
			}
		}
		if (check) {
			if (!arry.empty()) cout << "no" << endl;
			else cout << "yes" << endl;
		}
	}
}