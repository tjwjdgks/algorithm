#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int main() {
	int total;
	long long int  answer = 0;
	vector<int> xarry(100001, 0);
	vector<int> yarry(100001, 0);
	vector<pair<int, int>> v;
	
	cin >> total;
	for (int i = 0; i < total; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
		xarry[x] += 1;
		yarry[y] += 1;
	}
	
	for (int i = 0; i < v.size(); i++) {
		if (xarry[v[i].first] > 1 && yarry[v[i].second] > 1) {
			answer += ((long long int)xarry[v[i].first] - 1) * (yarry[v[i].second] - 1);
		}
	}
	
	cout << answer;
}