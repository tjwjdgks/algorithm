#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>>node(n + 1);
    for (int i = 0; i < m; i++) {
        int f, s, l;
        cin >> f >> s >> l;
        node[f].push_back(make_pair(s, l));
    }
    int start, end;
    cin >> start >> end;
    vector<int> distance(n + 1, 987654321);
    vector<int> hist(n + 1, 0);
    distance[start] = 0;
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push({ 0,start });
    while (!pq.empty()) {
        int cost = pq.top().first;
        int curnode = pq.top().second;
        pq.pop();
        if (distance[curnode] < cost) continue;
        for (int i = 0; i < node[curnode].size(); i++) {
            int neighbor = node[curnode][i].first;
            int neighborcost = node[curnode][i].second + cost;
            if (distance[neighbor] > neighborcost) {
                distance[neighbor] = neighborcost;
                hist[neighbor] = curnode;
                pq.push({ neighborcost,neighbor });
            }
        }
    }
    cout << distance[end] << endl;
    vector<int>route;
    int back = end;
    while (back) {
        route.push_back(back);
        back = hist[back];
    }
    cout << route.size() << endl;
    for (int i = route.size() - 1; i >= 0; i--) {
        cout << route[i] << " ";
    }
    return 0;
}