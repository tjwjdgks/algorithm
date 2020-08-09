#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for (long long i = begin; i <= end; i++) {
        if (i == 1)answer.push_back(0);
        else {
            bool check = true;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    if (i / j <= 10000000) {
                        check = false;
                        answer.push_back(i / j);
                        break;
                    }
                }
            }
            if (check) answer.push_back(1);
        }
    }
    return answer;
}
