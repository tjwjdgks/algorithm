#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    vector<pair<string, int>> p;
    for (int i = 0; i < clothes.size(); i++) {
        int count = 0;
        for (count = 0; count < p.size(); count++) {
            if (p[count].first == clothes[i][1]) {
                p[count].second += 1;
                break;
            }
        }
        if (count == p.size()) {
            p.push_back(make_pair(clothes[i][1], 1));
        }
    }
    for (int i = 0; i < p.size(); i++) {
        answer *= (p[i].second + 1);
    }
    answer -= 1;
    return answer;
}