#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int sum[2001];
int solution(vector<int> cookie) {
    int answer = 0;
    for (int i = 0; i < cookie.size(); ++i)
        sum[i + 1] = sum[i] + cookie[i];
    for (int m = 1; m < cookie.size(); ++m) {
        int c = sum[m];
        for (int r = m + 1; r <= cookie.size(); ++r) {
            int s = sum[r] - c;
            if (answer >= s || s > c) continue;
            for (int l = 0; l < m; ++l)
                if (s == c - sum[l]) {
                    answer = max(answer, s);
                    break;
                }
        }
    }
    return answer;
}