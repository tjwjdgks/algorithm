#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int curs = 0;
    int stick = 0;
    for (int i = 0; i < arrangement.size(); i++) {
        if (arrangement[i] == '(') {
            if (arrangement[i + 1] != ')') {
                stick++;
            }
        }
    }
    for (int i = 0; i < arrangement.size(); i++) {
        if (arrangement[i] == '(') {
            if (arrangement[i + 1] == ')') {
                answer += curs;
            }
            else {
                curs++;
            }
        }
        else {
            if (arrangement[i - 1] == '(') {

            }
            else curs--;
        }
    }
    return answer + stick;
}