#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#include <utility>
#include <list>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N;
vector<pii> v;
int cache[102];

bool check(pii a, pii b) { //a위에 b를 올릴 수 있는가?
	if (a.first >= b.first && a.second >= b.second) return true;
	if (a.first >= b.second && a.second >= b.first) return true;
	return false;
}

bool cmp(const pii& a, const pii& b) {
	return a.first * a.second > b.first* b.second;
}

int solve(int pos) {
	if (pos == N + 1) return 0;
	int& ret = cache[pos];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = pos + 1; i <= N + 1; i++)
		if (i == N + 1 || check(v[pos], v[i]))
			ret = max(ret, solve(i) + 1);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> N;
	v.resize(N + 1);
	v[0] = { 1000, 1000 };
	for (int i = 1; i <= N; i++)
		cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end(), cmp);
	memset(cache, -1, sizeof(cache));
	cout << solve(0) - 1 << '\n';
	return 0;
}