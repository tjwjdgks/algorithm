#include <string>
#include <vector>

using namespace std;

vector<vector<int>> totalarry;
pair<int, int> getAnswer(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) {
        if (totalarry[y1][x1] == 0) return { 1,0 };
        else return { 0,1 };
    }
    pair<int, int> p[4];
    p[0] = getAnswer(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2);
    p[1] = getAnswer((x1 + x2) / 2 + 1, y1, x2, (y1 + y2) / 2);
    p[2] = getAnswer(x1, (y1 + y2) / 2 + 1, (x1 + x2) / 2, y2);
    p[3] = getAnswer((x1 + x2) / 2 + 1, (y1 + y2) / 2 + 1, x2, y2);
    int num0 = 0;
    int num1 = 0;
    for (int i = 0; i < 4; i++) {
        num0 += p[i].first;
        num1 += p[i].second;
    }
    if (num0 == 0)
        return { 0,1 };
    else if (num1 == 0)
        return { 1,0 };
    else return { num0,num1 };
}
vector<int> solution(vector<vector<int>> arr) {
    totalarry = arr;
    vector<int> answer;
    pair<int, int> a = getAnswer(0, 0, arr.size() - 1, arr.size() - 1);
    answer.push_back(a.first);
    answer.push_back(a.second);
    return answer;
}