#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
vector<int> arry;
int equals[4];
int nummin = INT_MAX;
int nummax = INT_MIN;
int N;
void dfs(int plus, int minus, int mult, int divid, int count, int sum) {
	if (count == N) {
		nummin = min(nummin, sum);
		nummax = max(nummax, sum);
	}
	if (plus > 0)
		dfs(plus - 1, minus, mult, divid, count + 1, sum + arry[count]);
	if (minus > 0)
		dfs(plus, minus - 1, mult, divid, count + 1, sum - arry[count]);
	if (mult > 0)
		dfs(plus, minus, mult - 1, divid, count + 1, sum * arry[count]);
	if (divid > 0)
		dfs(plus, minus, mult, divid - 1, count + 1, sum / arry[count]);
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tempnum;
		cin >> tempnum;
		arry.push_back(tempnum);
	}
	for (int i = 0; i < 4; i++) {
		cin >> equals[i];
	}
	dfs(equals[0], equals[1], equals[2], equals[3], 1, arry[0]);
	cout << nummax << endl;
	cout << nummin << endl;
}