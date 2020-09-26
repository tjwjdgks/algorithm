#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;


    int loops = n / 3;
    int index = n % 3;
    vector<vector<int>> arry;
    for (int i = 1; i <= n; i++) {
        vector<int> temprow(i, 0);
        arry.push_back(temprow);
    }
    int curx = 0;
    int cury = 0;
    int curn = n;
    int curnum = 0;
    for (int i = 0; i < loops; i++) {
        for (int j = 0; j < curn - 1; j++) {
            curnum++;
            arry[cury++][curx] = curnum;
        }
        for (int j = 0; j < curn; j++) {
            curnum++;
            arry[cury][curx++] = curnum;
        }
        curx -= 2;
        cury--;
        for (int j = 0; j < curn - 2; j++) {
            curnum++;
            arry[cury--][curx--] = curnum;
        }
        cury += 2;
        curx++;
        curn -= 3;
    }
    if (index == 1) {
        curnum++;
        arry[cury][curx] = curnum;
    }
    else if (index == 2) {
        curnum++;
        arry[cury][curx] = curnum;
        arry[cury + 1][curx] = curnum + 1;
        arry[cury + 1][curx + 1] = curnum + 2;
    }
    for (int i = 0; i < arry.size(); i++) {
        for (int j = 0; j < arry[i].size(); j++) {
            answer.push_back(arry[i][j]);
        }
    }
    return answer;
}