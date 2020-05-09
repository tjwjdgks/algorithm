#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    vector<int>money2 = money;
    int size = money.size();
    if (money.size() == 3) {
        answer = max(money[0], max(money[1], money[2]));
        return answer;
    }
    for (int i = 2; i < money.size() - 1; i++) {

        if (i == 2) {
            money[i] += money[i - 2];
        }
        else {
            money[i] += max(money[i - 2], money[i - 3]);
        }
    }
    int a = max(money[size - 2], money[size - 3]);
    for (int i = 3; i < money.size(); i++) {

        if (i == 3) {
            money2[i] += money2[i - 2];
        }
        else {
            money2[i] += max(money2[i - 2], money2[i - 3]);
        }
    }
    int b = max(money2[size - 1], money2[size - 2]);
    if (a > b) {
        answer = a;
    }
    else {
        answer = b;
    }
    return answer;
}