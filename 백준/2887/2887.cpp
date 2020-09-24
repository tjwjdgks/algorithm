#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Planet {
	int x, y, z, num;
};
bool comparex(Planet a, Planet b) {
	return a.x < b.x;
}
bool comparey(Planet a, Planet b) {
	return a.y < b.y;
}
bool comparez(Planet a, Planet b) {
	return a.z < b.z;
}
struct edge {
	int value, src, dst;
};
bool compare(edge a, edge b) {
	return a.value < b.value;
}
int parent[100001];
int Find(int num) {
	if (parent[num] == num) return num;
	return parent[num] = Find(parent[num]);
}
void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	parent[a] = b;
}
int main() {
	int N;
	cin >> N;
	vector<Planet> P;
	for (int i = 0; i < N; i++) {
		int tempx, tempy, tempz;
		cin >> tempx >> tempy >> tempz;
		P.push_back({ tempx,tempy,tempz,i });
		parent[i] = i;
	}
	vector<edge> e;
	sort(P.begin(), P.end(), comparex);
	for (int i = 0; i < N - 1; i++) {
		e.push_back({ abs(P[i].x - P[i + 1].x),P[i].num,P[i + 1].num });
	}
	sort(P.begin(), P.end(), comparey);
	for (int i = 0; i < N - 1; i++) {
		e.push_back({ abs(P[i].y - P[i + 1].y),P[i].num,P[i + 1].num });
	}
	sort(P.begin(), P.end(), comparez);
	for (int i = 0; i < N - 1; i++) {
		e.push_back({ abs(P[i].z - P[i + 1].z),P[i].num,P[i + 1].num });
	}
	sort(e.begin(), e.end(), compare);
	int count = 0;
	int answer = 0;
	for (int i = 0; count != N - 1; i++) {
		if (Find(e[i].src) != Find(e[i].dst)) {
			count++;
			answer += e[i].value;
			Union(e[i].src, e[i].dst);
		}
		if (count == N - 1) break;
	}
	cout << answer;

}