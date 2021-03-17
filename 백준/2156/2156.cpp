#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int grape[10002];
int dp[10002];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> grape[i];
    }

    dp[0] = 0;
    dp[1] = grape[1];
    dp[2] = grape[1] + grape[2];

    for (int i = 3; i <= n; i++) {
        int res = 0;
        res = (dp[i - 1] > dp[i - 2] + grape[i]) ? dp[i - 1] : dp[i - 2] + grape[i];
        dp[i] = (res > dp[i - 3] + grape[i - 1] + grape[i]) ? res : dp[i - 3] + grape[i - 1] + grape[i];
    }
    cout << dp[n];

    return 0;
}