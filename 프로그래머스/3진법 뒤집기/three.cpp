#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> threearry;
    while (n != 0) {
        int temprest = n % 3;
        threearry.push_back(temprest);
        n = n / 3;
    }
    int firstnum = 1;
    for (int i = threearry.size() - 1; i >= 0; i--) {
        answer += threearry[i] * firstnum;
        firstnum *= 3;
    }
    return answer;
}