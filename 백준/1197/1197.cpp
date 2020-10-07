#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int check[10001];
struct Edge {
	int first, end, value;
};
bool compare(Edge a, Edge b) {
	return a.value < b.value;
}
int getParent(int num) {
	if (check[num] == num) return num;
	return check[num] = getParent(check[num]);
}
bool isCycle(int num1, int num2) {
	num1 = getParent(num1);
	num2 = getParent(num2);
	if (num1 == num2) return true;
	else return false;
}
vector<Edge> v;
int main() {
	int V, E;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int tempf, tempe, val;
		cin >> tempf >> tempe >> val;
		v.push_back({ tempf,tempe,val });
	}
	for (int i = 1; i <= V; i++) {
		check[i] = i;
	}
	sort(v.begin(), v.end(), compare);
	long long answer = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!isCycle(v[i].first, v[i].end)) {
			answer += v[i].value;
			int firstnum = getParent(v[i].first);
			int secondnum = getParent(v[i].end);
			if (firstnum > secondnum) check[firstnum] = secondnum;
			else check[secondnum] = firstnum;
		}
	}
	cout << answer;
}