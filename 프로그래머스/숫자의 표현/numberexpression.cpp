#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i = 1; i < n; i++) {
        int tempnum = 0;
        for (int j = 0; j < i; j++) {
            tempnum += j;
        }
        if ((n - tempnum) < 0 || (n - tempnum) / i == 0)break;
        if ((n - tempnum) % i == 0) answer++;

    }
    return answer;
}