#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
vector<int> checknode;
struct noded {
    pair<int, int> edge;
    int distance;
};
bool compare(noded a, noded b) {
    return a.distance < b.distance;
}
int getParent(int a) {
    if (a == checknode[a])return a;
    return checknode[a] = getParent(checknode[a]);
}
bool find(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a == b) return true;
    else return false;
}
void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a < b) checknode[b] = a;
    else checknode[a] = b;
}
int solution(vector<vector<int>> land, int height) {
    int answer = 0;

    vector<vector<bool>> check(land.size(), vector<bool>(land[0].size(), false));
    vector<vector<int>> area(land.size(), vector<int>(land[0].size(), false));
    int count = 0;
    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < land[i].size(); j++) {
            if (check[i][j] == false) {
                area[i][j] = count;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                check[i][j] = false;
                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx >= 0 && ny >= 0 && nx < land.size() && ny < land.size()) {
                            if (check[ny][nx] == false && abs(land[y][x] - land[ny][nx]) <= height) {
                                check[ny][nx] = true;
                                area[ny][nx] = count;
                                q.push(make_pair(ny, nx));
                            }
                        }
                    }
                }
                count++;
            }
        }
    }
    vector<vector<int>> node(count, vector<int>(count, 10001));
    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < land[i].size(); j++) {
            int y = i;
            int x = j;
            for (int k = 0; k < 4; k++) {
                int ny = y + dy[k];
                int nx = x + dx[k];
                if (nx >= 0 && ny >= 0 && nx < land.size() && ny < land.size() && area[y][x] != area[ny][nx]) {
                    int temp = abs(land[y][x] - land[ny][nx]);
                    if (node[area[y][x]][area[ny][nx]] > temp) {
                        node[area[y][x]][area[ny][nx]] = temp;
                        node[area[ny][nx]][area[y][x]] = temp;
                    }
                }
            }
        }
    }
    vector<noded> p;
    for (int i = 0; i < node.size(); i++) {
        for (int j = i; j < node[i].size(); j++) {
            if (node[i][j] != 10001) {
                noded temp;
                temp.edge = make_pair(i, j);
                temp.distance = node[i][j];
                p.push_back(temp);
            }
        }
    }
    for (int i = 0; i < count; i++) {
        checknode.push_back(i);
    }

    sort(p.begin(), p.end(), compare);
    for (int i = 0; i < p.size(); i++) {
        if (!find(p[i].edge.first, p[i].edge.second)) {
            answer += p[i].distance;
            unionParent(p[i].edge.first, p[i].edge.second);
        }
    }
    int a = 0;

    return answer;
}
int main() {
    vector < vector<int> >a({ {1, 4, 8, 10},{5, 5, 5, 5},{10, 10, 10, 10}, {10, 10, 10, 20} });
    int solutions = solution(a, 3);
    cout << solutions;
}