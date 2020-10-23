#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            answer += ' ';
            continue;
        }
        int c = 0;
        int f = 0;
        if (s[i] >= 'a' && s[i] <= 'z') {
            c = (s[i] - 'a' + 1 + n) % 26;
            f = 'a';
        }
        else {
            c = (s[i] - 'A' + 1 + n) % 26;
            f = 'A';
        }
        if (c == 0)c = 26;
        answer += f + c - 1;
    }
    return answer;
}