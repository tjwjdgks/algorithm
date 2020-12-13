#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char compareAndChangeAlpha(char a, bool check = false) {
    if (check) {
        if (a >= 'a' && a <= 'z') return a - 'a' + 'A';
    }
    else {
        if (a >= 'A' && a <= 'Z') return a - 'A' + 'a';
    }
    return a;
}
string solution(string s) {
    string answer = "";
    for (int i = 0; i < s.size(); i++) {
        if (i == 0) {
            answer += compareAndChangeAlpha(s[i], true);
        }
        else {
            if (s[i - 1] == ' ') {
                answer += compareAndChangeAlpha(s[i], true);
            }
            else {
                answer += compareAndChangeAlpha(s[i], false);
            }
        }
    }
    return answer;
}