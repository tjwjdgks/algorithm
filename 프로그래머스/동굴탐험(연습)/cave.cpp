#include <string>
#include <vector>
using namespace std;
const int MAX = 200001;

bool check_visit[MAX];
int before[MAX];
int hang[MAX];
vector<int> edge[MAX];

void visit(int num) {
    if (check_visit[num]) return;

    if (!check_visit[before[num]]) {
        hang[before[num]] = num;
        return;
    }

    check_visit[num] = true;

    visit(hang[num]);

    for (int n : edge[num]) visit(n);
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    for (auto& it : path) {
        edge[it[0]].push_back(it[1]);
        edge[it[1]].push_back(it[0]);
    }

    for (auto& it : order) before[it[1]] = it[0];

    if (before[0]) return false;

    check_visit[0] = true;
    for (int n : edge[0]) visit(n);
    for (int i = 0; i < n; i++) if (!check_visit[i]) return false;

    return true;
}