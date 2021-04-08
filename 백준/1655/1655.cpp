#include <iostream>
#include <functional>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	priority_queue<int> pqfirst;
	priority_queue<int, vector<int>, greater<int>> pqsecond;
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (pqfirst.empty())
			pqfirst.push(x);
		else {
			if (pqfirst.size() > pqsecond.size())
				pqsecond.push(x);
			else {
				pqfirst.push(x);
			}
			if (pqfirst.top() > pqsecond.top()) {
				int tempfirst = pqfirst.top();
				int tempsecond = pqsecond.top();
				pqfirst.pop();
				pqsecond.pop();
				pqfirst.push(tempsecond);
				pqsecond.push(tempfirst);
			}
		}
		cout << pqfirst.top() << '\n';
	}
}