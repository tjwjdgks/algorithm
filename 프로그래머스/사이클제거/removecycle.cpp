#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> node[5000];
int nodenum[5000], dfsn[5000], dstn;
int dfs(int now, int pre) {
    int temp, ret = dfsn[now] = dstn++;

    for (int next : node[now]) {
        if (next != pre) {
            if (dfsn[next] == -1) temp =dfs(next, now);
            else {
                temp = dfsn[next];
                if (temp > dfsn[now]) continue;
            }
            if (temp >= dfsn[now]) ++nodenum[now];
            ret = min(ret, temp);
        }
    }
    if (pre == -1) nodenum[now] = max(0, nodenum[now] - 1);
    return ret;
}
int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    for (auto &i : edges) {
        node[--i[0]].push_back(--i[1]);
        node[i[1]].push_back(i[0]);
    }
    memset(dfsn, -1, sizeof(dfsn));
    dfs(0, -1);
    for (int i = 0; i < n; ++i) {
        if (edges.size() - node[i].size() + nodenum[i] < n - 1) answer += i + 1;
    }
    return answer;
}