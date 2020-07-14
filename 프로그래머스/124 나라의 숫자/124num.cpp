#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n) {
    string answer = "";
    while (n != 0) {
        n--;
        int rest = n % 3;
        n /= 3;
        switch (rest) {
        case 0:
            answer += '1';
            break;
        case 1:
            answer += '2';
            break;
        case 2:
            answer += '4';
            break;
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}