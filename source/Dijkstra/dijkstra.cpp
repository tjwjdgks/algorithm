#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define INF INT_MAX
struct edge {
	int first, second, value;
};
void dijkstra(int n, vector<vector<int>> W, vector<edge>& F) {
	int i, vnear;
	vector<int> touch(n, 0);
	vector<int> length(n, 0);
	F.clear();
	//0부터 시작
	for (int i = 1; i < n; i++) {
		touch[i] = 1;
		length[i] = W[1][i];
	}
	for (int j = 0; j < n - 1; j++) {
		int min = INF;
		for(i=1; i<n;i++)
			if (length[i] >= 0 && length[i] < min) {
				min = length[i];
				vnear = i;
			}
		F.push_back(vnear, touch[vnear]);
		for(i=1;i<n;i++)
			if (length[vnear] + W[vnear][i] < length[i]) {
				length[i] = length[vnear] + W[vnear][i];
				touch[i] = vnear;
			}
		length[vnear] = -1;
	}
}
int main() {

}