#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int N, M;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
int main() {
	
	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			if (temp == 1) {
				house.push_back(make_pair(i, j));
			}
			else if (temp == 2) {
				chicken.push_back({ i,j });
			}
		}
	}
	vector<int> indexarr(chicken.size() - M, 0);
	for (int i = 0; i < M; i++)
		indexarr.push_back(1);
	int answer = INF;
	do {
		vector<int> temparr(house.size(), INF);
		for (int k = 0; k < indexarr.size(); k++) {
			if (indexarr[k] == 1) {
				for (int i = 0; i < house.size(); i++) {
					int tempdist = abs(chicken[k].first - house[i].first) + abs(chicken[k].second - house[i].second);
					if (tempdist < temparr[i])
						temparr[i] = tempdist;
				}
			}
		}
		int temptotal = 0;
		for (int k = 0; k < temparr.size(); k++) {
			temptotal += temparr[k];
		}
		if (answer > temptotal)
			answer = temptotal;
	} while (next_permutation(indexarr.begin(), indexarr.end()));
	cout << answer;
}