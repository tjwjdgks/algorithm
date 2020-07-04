#include <string>
#include <vector>

using namespace std;
long long dp[5001];
int recursive(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    if (n == 2) return 3;
    if (dp[n] != 0) return dp[n];
    int result = 3 * recursive(n - 2) % 1000000007;
    for (int i = 3; i <= n; i++) {
        if (n % 2 == 0) {
            result += 2 * recursive(n - i) % 1000000007;
        }
    }
    return dp[n] = result;
}
int solution(int n) {
    int answer = 0;
    if (n == 0) return 0;
    dp[0] = 1;
    dp[2] = 3;
    for (int i = 3; i <= n; i++) {
        dp[i] = 3 * dp[i - 2] % 1000000007;
        for (int j = 3; j <= i; j++) {
            if (j % 2 == 0)
                dp[i] += 2 * dp[i - j] % 1000000007;
        }
    }
    answer = dp[n];
    return answer;
}