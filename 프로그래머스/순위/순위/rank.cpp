#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int arrysize = results.size();
    vector<vector<bool>> v(n, vector<bool>(n, false));
    for (auto r : results) {
        v[r[0]-1][r[1]-1] = true;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int z = 0; z < n; z++) {
                if (v[i][z] && v[j][i]) {
                    v[j][z] = true;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (v[i][j] || v[j][i]) {
                count++;
            }
        }
        if (count == n - 1) {
            answer++;
        }
    }
    return answer;
}
