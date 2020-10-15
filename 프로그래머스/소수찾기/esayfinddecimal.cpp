#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<bool> arry(n + 1, false);
    int answer = 0;
    for (int i = 2; i <= n; i++) {
        if (arry[i] == false) answer++;
        for (int j = i; j <= n; j += i) {
            arry[j] = true;
        }
    }
    return answer;
}