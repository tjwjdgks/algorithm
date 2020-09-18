#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pos {
	int y, x;
}
;
struct Land {
	vector<Pos> edge;
};
struct Brige {
	int src, dest, len;
};
const Pos d[4] = { {0,1},{1,0},{-1,0},{0,-1} };
vector<vector<int>> arry;
vector<Brige> brige;
Land land[7];
int N, M;
int dsu[7];
bool inside(Pos a) {
	return a.x >= 0 && a.x < M && a.y >= 0 && a.y < N;
}
bool compare(Brige a, Brige b) {
	return a.len < b.len;
}
int dsufind(int p) {
	while (dsu[p] != p) {
		p = dsu[p];
	}
	return p;
}
void dfs(Pos p, int id) {
	arry[p.y][p.x] = id;
	int check = 0;
	for (int i = 0; i < 4; i++) {
		Pos temp = { p.y + d[i].y , p.x + d[i].x };

		if (inside(temp)) {
			if (arry[temp.y][temp.x] == -1)
				dfs(temp, id);
			else if (arry[temp.y][temp.x] == 0) check++;
		}
	}
	if (check)
		land[id].edge.push_back(p);
}
void bridge(Pos pos) {
	const int id = arry[pos.y][pos.x];
	for (int k = 0; k < 4; k++) {
		Pos p = { pos.y + d[k].y,pos.x + d[k].x };
		int len = 0;
		int dest = 0;
		while (inside(p) && arry[p.y][p.x] == 0) {
			p.y += d[k].y;
			p.x += d[k].x;
			len++;
		}
		if (inside(p)) {
			dest = arry[p.y][p.x];
		}
		if (len >= 2 && dest) {
			brige.push_back({ id,dest,len });
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		vector<int> row;
		for (int j = 0; j < M; j++) {
			int tempnum;
			cin >> tempnum;
			if (tempnum == 1) tempnum = -1;
			row.push_back(tempnum);
		}
		arry.push_back(row);
	}
	int id = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arry[i][j] == -1) {
				dsu[id] = id;
				dfs({ i,j }, id++);
			}
		}
	}
	for (int i = 1; i < id; i++) {
		for (Pos p : land[i].edge) {
			bridge(p);
		}
	}
	sort(brige.begin(), brige.end(), compare);
	int totallen = 0;
	for (auto b : brige) {
		if (dsufind(b.src) != dsufind(b.dest)) {
			totallen += b.len;
			dsu[dsufind(b.src)] = dsufind(b.dest);
		}
	}
	int dsuf = dsufind(1);
	for (int i = 2; i < id; i++) {
		if (dsuf != dsufind(i)) {
			totallen = -1;
		}
	}
	cout << totallen << endl;
}