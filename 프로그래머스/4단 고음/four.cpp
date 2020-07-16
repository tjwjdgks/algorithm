#include<iostream>
#include<cmath>
using namespace std;


int dfs(int n, int cur) {
    int answer = 0;
    if (n < 1 || 2 * log(n) / log(3) < cur) return 0;
    else if (n == 3 && cur == 2) return 1;


    if (n % 3 == 0 && cur >= 2) {
        answer += dfs(n / 3, cur - 2);
    }
    answer += dfs(n - 1, cur + 1);
    return answer;
}
int solution(int n) {
    int answer = 0;
    answer = dfs(n - 2, 2);
    return answer;
}