#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int lands[301][301];
int N;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
vector<vector<int>> copyland;
int copyheight;
struct Edge {
    int firstnum, endnum, value;
};
void DFS(int y, int x, int num) {
    lands[y][x] = num;
    for (int i = 0; i < 4; i++) {
        int tempy = y + dy[i];
        int tempx = x + dx[i];
        if (tempy >= 0 && tempy < N && tempx >= 0 && tempx < N) {
            if (lands[tempy][tempx] == 0 && copyheight >= abs(copyland[tempy][tempx] - copyland[y][x])) {
                DFS(tempy, tempx, num);
            }
        }
    }
    return;
}
bool compare(Edge a, Edge b) {
    return a.value < b.value;
}
int check[90001];
int getParent(int num) {
    if (num == check[num]) return num;
    return check[num] = getParent(check[num]);
}
int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    copyheight = height;
    N = land.size();
    copyland = land;
    vector<Edge> v;

    int num = 1;
    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < land[i].size(); j++) {
            if (lands[i][j] == 0) {
                DFS(i, j, num);
                num++;
            }
        }
    }
    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < land[i].size(); j++) {
            for (int k = 0; k < 4; k++) {
                int tempy = i + dy[k];
                int tempx = j + dx[k];
                if (tempy >= 0 && tempy < N && tempx >= 0 && tempx < N) {
                    if (lands[tempy][tempx] != lands[i][j]) {
                        int gap = abs(land[tempy][tempx] - land[i][j]);
                        v.push_back({ lands[tempy][tempx],lands[i][j],gap });
                    }
                }
            }
        }
    }
    for (int i = 0; i < num + 2; i++) {
        check[i] = i;
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); i++) {
        int firstnum = getParent(v[i].firstnum);
        int secondnum = getParent(v[i].endnum);
        if (firstnum != secondnum) {
            answer += v[i].value;
            check[firstnum] = secondnum;
        }
    }
    int ass = 3;
    return answer;
}