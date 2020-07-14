#include <string>
#include <vector>
#include <deque>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (int i = 0; i < skill_trees.size(); i++) {
        deque<char> temp(skill.begin(), skill.end());
        int j = 0;
        for (j = 0; j < skill_trees[i].size(); j++) {
            bool check = true;
            for (int z = 0; z < temp.size(); z++) {
                if (temp[z] == skill_trees[i][j]) {
                    if (z == 0) {
                        temp.pop_front();
                    }
                    else {
                        check = false;
                        break;
                    }
                }
            }
            if (!check) break;
        }
        if (j == skill_trees[i].size()) answer++;
    }
    return answer;
}