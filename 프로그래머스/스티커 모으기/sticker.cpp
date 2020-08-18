#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;
    int size = sticker.size();
    vector<int> dp(sticker.size(), 0);
    if (size == 1) return sticker[0];
    else if (size == 2) return max(sticker[0], sticker[1]);
    else {
        dp[0] = sticker[0];
        dp[1] = sticker[0];
        for (int i = 2; i < size - 1; i++) {
            dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
        }
        answer = dp[size - 2];
        for (int i = 0; i < dp.size(); i++) dp[i] = 0;
        dp[0] = 0;
        dp[1] = sticker[1];
        for (int i = 2; i < size; i++) {
            dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
        }
        answer = max(answer, dp[size - 1]);

    }
    return answer;
}