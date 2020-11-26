#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct edges {
	int first;
	int second;
	int value;
};
struct dis_set {
	int parent;
	int depth;
};
vector<dis_set> U;
bool compare(edges A, edges B) {
	return A.value < B.value;
}
void makeset(int i) {
		U[i].depth = 0;
		U[i].parent = i;
}
int find(int i) {
	int j;
	j = i;
	while (U[j].parent != j)
		j = U[j].parent;
	return j;
}
void merge(int p, int q) {
	if (U[p].depth == U[q].depth) {
		U[p].depth += 1;
		U[q].parent = p;
	}
	else if (U[p].depth < U[q].depth)
		U[p].parent = q;
	else U[q].parent = p;
}
bool equal(int p, int q) {
	if (p == q) return true;
	else return false;
}
void initial(int n) {
	U.resize(n+1);
	for (int i = 1; i <= n; i++)
		makeset(i);
}
void kruskal(int n, int m, vector<edges> E, vector<edges>&F) {
	int i, j, v;
	int p, q;
	//배열 0부터 시작하므로
	int edgeindex = 0;
	sort(E.begin(), E.end(),compare);
	F.clear();
	initial(n);
	while (F.size() < n-1) {
		i = E[edgeindex].first;
		j = E[edgeindex].second;
		v = E[edgeindex].value;
		p = find(i);
		q = find(j);
		if (!equal(p, q)) {
			merge(p, q);
			F.push_back({ i,j,v });
		}
		edgeindex++;
	}
}

int main() {
	vector<edges> E({ { 1,2,1 },{3,5,2},{1,3,3},{3,4,4},{4,5,5},{2,4,6},{2,3,3} });
	vector<edges> F;
	kruskal(5, 7, E, F);
	int a=3;
	int c = a + 2;
}