#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int x[4] = { 0,1,0,-1 };
int y[4] = { 1,0,-1,0 };
int solution(vector<vector<int> > maps)
{
    vector<vector<int>> dp(maps.size() + 1, vector<int>(maps[0].size() + 1, 123456));
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[0].size(); j++) {
            if (maps[i][j] == 1) {
                dp[i][j] = 1;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                maps[i][j] = 0;
                while (!q.empty()) {
                    int cury = q.front().first;
                    int curx = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int tempy = cury + y[k];
                        int tempx = curx + x[k];
                        if (tempy >= 0 && tempx >= 0 && tempy < maps.size() && tempx < maps[i].size()) {
                            if (maps[tempy][tempx] == 1) {
                                q.push(make_pair(tempy, tempx));
                                maps[tempy][tempx] = 0;
                            }
                        }
                    }
                    if (cury == i && curx == j)continue;
                    else {
                        int curmin = 123456;
                        for (int k = 0; k < 4; k++) {
                            int tempy = cury + y[k];
                            int tempx = curx + x[k];
                            if (tempy >= 0 && tempx >= 0) curmin = min(dp[tempy][tempx], curmin);
                        }
                        dp[cury][curx] = curmin + 1;
                    }
                }
            }
        }
    }
    if (dp[maps.size() - 1][maps[0].size() - 1] < maps.size() + maps[0].size() - 1) return -1;
    else return dp[maps.size() - 1][maps[0].size() - 1];
}