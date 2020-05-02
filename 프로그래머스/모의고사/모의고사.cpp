#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> arry1{ 1,2,3,4,5 };
    vector<int> arry2{ 2,1,2,3,2,4,2,5 };
    vector<int> arry3{ 3,3,1,1,2,2,4,4,5,5 };
    int count[3] = { 0, };
    for (int i = 0; i < answers.size(); i++) {
        if (arry1[i % arry1.size()] == answers[i]) {
            count[0] += 1;
        }
        if (arry2[i % arry2.size()] == answers[i]) {
            count[1] += 1;
        }
        if (arry3[i % arry3.size()] == answers[i]) {
            count[2] += 1;
        }
    }
    int answerNum = max(count[0], max(count[1], count[2]));
    for (int i = 0; i < 3; i++) {
        if (count[i] == answerNum) {
            answer.push_back(i + 1);
        }
    }
    return answer;
}