#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int totals;
	cin >> totals;
	vector<pair<int, int>> v;
	for (int i = 0; i < totals; i++) {
		int limit, price;
		cin >> limit >> price;
		v.push_back(make_pair(limit, price));
	}
	int check = 0;
	int maxnum = 0;
	long long total = 0;
	int i;
	for (i = 0; i < v.size(); i++) {
		if (total <= v[i].first) {
			maxnum = max(maxnum, v[i].second);
			total += v[i].second;
		}
		else {
			check++;
			if (check >= 2)break;
			if (total - maxnum <= v[i].first) {
				total = min(total - maxnum + v[i].second, total);
			}
		}

	}
	if (i == v.size()) cout << "Kkeo-eok";
	else cout << "Zzz";
}