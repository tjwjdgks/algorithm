#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int length, width, height,cnt;
int totalcount;
int fail = 0;
vector<pair<int, int>> arr;
bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second > b.second;
	return a.first > b.first;
}
void devide(int l, int w, int h,int idx) {
	if (l == 0 || w == 0 || h == 0) return;
	for (int i = idx; i < arr.size(); i++) {
		if (arr[i].second != 0 && l >= arr[i].first && w >= arr[i].first && h >= arr[i].first) {
			arr[i].second--;
			totalcount++;
			devide(l - arr[i].first, w, h,i);
			devide(arr[i].first, w - arr[i].first, h,i);
			devide(arr[i].first, arr[i].first, h - arr[i].first, i);
			return;
		}
	}
	fail = 1;
}
int main() {
	cin >> length >> width >> height;
	cin >> cnt;

	for (int i = 0; i < cnt; i++) {
		int first, second;
		cin >> first >> second;
		arr.push_back({ pow(2, first), second });
	}
	sort(arr.begin(), arr.end(),compare);

	devide(length, width, height, 0);
	if (fail)
		cout << -1;
	else
		cout << totalcount;

}