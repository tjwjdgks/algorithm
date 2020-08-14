#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    long long factorynum = 1;
    long long factorydivide = 1;
    for (int i = n + 1; i <= 2 * n; i++) {
        factorynum *= i;
    }
    for (int i = 1; i <= n; i++) {
        factorydivide *= i;
    }
    answer = factorynum / factorydivide;
    answer /= n + 1;
    return answer;
}