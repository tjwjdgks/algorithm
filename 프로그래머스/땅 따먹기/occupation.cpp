#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    vector<int> nextv(4, 0);
    for (int i = 0; i < land.size() - 1; i++) {
        nextv = land[i + 1];
        for (int j = 0; j < land[i].size(); j++) {
            for (int k = 0; k < land[i].size(); k++) {
                if (k == j) continue;
                land[i + 1][j] = max(land[i + 1][j], nextv[j] + land[i][k]);
            }
        }
    }
    sort(land[land.size() - 1].begin(), land[land.size() - 1].end(), greater<int>());
    answer = land[land.size() - 1][0];
    return answer;
}