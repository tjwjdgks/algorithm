#include <iostream>
using namespace std;

#define FAIL 9
// 0 1 ¼ø¼­
int state[10][2] = {
	{2,1}, //0
	{3,FAIL},//1
	{FAIL,4},//2
	{5,FAIL}, //3
	{2,1}, // 4
	{5,6}, // 5
	{2,7}, // 6
	{8,7}, // 7
	{5,4}, // 8
	{FAIL,FAIL} // FAIL
};
bool anchek(string s) {
	int statenum = 0;
	for (int i = 0; i < s.size(); i++) {
		int tempnum = s[i] - '0';
		statenum = state[statenum][tempnum];
	}
	return statenum == 4 || statenum == 6 || statenum == 7;
}
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string temp;
		cin >> temp;
		bool check = anchek(temp);
		if (check)
			cout << "YES" << '\n';
		else
			cout << "NO" << endl;
	}
}