#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = -1;
    if (num == 1) {
        return 0;
    }
    long long numl = num;
    for (int i = 1; i <= 500; i++) {
        if (numl % 2 == 0)
            numl /= 2;
        else numl = numl * 3 + 1;

        if (numl == 1) {
            answer = i;
            break;
        }
    }
    return answer;
}