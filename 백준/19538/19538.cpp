#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

int main() {
    int totalperson;
    cin >> totalperson;
    vector<vector<int>> personarry(totalperson + 1);
    for (int i = 1; i <= totalperson; i++) {
        int temp = -1;
        while (true) {
            cin >> temp;
            if (temp == 0) break;
            personarry[i].push_back(temp);
        }
    }
    int totalrumer;
    cin >> totalrumer;
    vector<int> checkarry(totalperson + 1, -1);
    queue<pair<int, int>> bfs;
    vector<int> rumercount(totalperson + 1, 0);
    for (int i = 0; i < totalrumer; i++) {
        int firstrumer;
        cin >> firstrumer;
        checkarry[firstrumer] = 0;
        bfs.push(make_pair(firstrumer, 0));
    }
    while (!bfs.empty()) {
        int temrumer = bfs.front().first;
        int temptime = bfs.front().second;

        /*
        if (checkarry[temrumer] != -1 &&checkarry[temrumer]!=0) {
            checkarry[temrumer] = min(checkarry[temrumer], temptime + 1);
            continue;
        }
        */
        bfs.pop();
        for (int i = 0; i < personarry[temrumer].size(); i++) {
            int tempidx = personarry[temrumer][i];
            if (checkarry[tempidx] == -1) {
                int tempcount = personarry[tempidx].size() / 2;
                if (personarry[tempidx].size() % 2 != 0) tempcount++;
                rumercount[tempidx] += 1;
                if (rumercount[tempidx] >= tempcount) {
                    bfs.push(make_pair(tempidx, temptime + 1));
                    checkarry[tempidx] = temptime + 1;
                }
            }
        }
    }
    for (int i = 1; i < checkarry.size(); i++) {
        cout << checkarry[i] << " ";
    }
}