#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> s;
    int i;
    s.insert(words[0]);
    for (i = 1; i < words.size(); i++) {
        int number = i / n + 1;
        int rest = (i % n) + 1;
        if (s.find(words[i]) != s.end() || words[i - 1][words[i - 1].size() - 1] != words[i][0]) {
            answer.push_back(rest);
            answer.push_back(number);
            break;
        }
        else {
            s.insert(words[i]);
        }

    }
    if (i == words.size()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}