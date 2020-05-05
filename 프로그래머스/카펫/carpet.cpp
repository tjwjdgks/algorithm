#include <string>
#include <vector>
#include <utility>
using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    vector<pair<int,int>> answerarry;
    for (int i = 1; i<= red; i++) {
        int row, col;
        row = red / i;
        col = i;
        if (row >= col) {
            if (red % i == 0) {
                answerarry.push_back(make_pair(col, row));
            }
        }
        else break;
    }
    for (int i = 0; i < answerarry.size(); i++) {
        int total = answerarry[i].second * 2 + answerarry[i].first * 2 + 4;
        if (total == brown) {
            answer.push_back(answerarry[i].second + 2);
            answer.push_back(answerarry[i].first + 2);
            break;
        }
    }
    return answer;
}