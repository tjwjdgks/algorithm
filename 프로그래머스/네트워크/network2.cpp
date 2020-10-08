#include <string>
#include <vector>

using namespace std;

bool check[201];
vector<vector<int>> arry;
void getAnswer(int num) {
    check[num] = true;
    for (int i = 0; i < arry[num].size(); i++) {
        if (num == i || check[i] == true) continue;
        else {
            if (arry[num][i] == 1) getAnswer(i);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    arry = computers;
    for (int i = 0; i < computers.size(); i++) {
        if (check[i] == true) continue;
        else {
            answer++;
            getAnswer(i);
        }
    }
    return answer;
}