#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[202][202];

int solution(vector<vector<int>> matrix_sizes) {
    int answer = 0;
    vector<int> numarry;
    numarry.push_back(matrix_sizes[0][0]);
    for (int i = 0; i < matrix_sizes.size(); i++) {
        numarry.push_back(matrix_sizes[i][1]);
    }
    for (int i = 0; i < matrix_sizes.size(); i++) {
        for (int j = 1; j <= matrix_sizes.size() - i; j++) {
            int k = j + i;
            if (k == j) {
                dp[j][k] = 0;
                continue;
            }
            dp[j][k] = 1600000001;
            for (int z = j; z <= k - 1; z++) {
                dp[j][k] = min(dp[j][k], dp[j][z] + dp[z + 1][k] + numarry[j - 1] * numarry[z] * numarry[k]);
            }

        }
    }
    answer = dp[1][matrix_sizes.size()];
    return answer;
}