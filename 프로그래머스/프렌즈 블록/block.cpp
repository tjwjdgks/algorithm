#include <string>
#include <vector>
#include <queue>
using namespace std;
int x[4] = { 0,1,0,1 };
int y[4] = { 0,0,1,1 };
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool check = true;
    while (check) {
        vector<pair<int, int>>v;
        for (int i = 0; i < board.size() - 1; i++) {
            for (int j = 0; j < board[i].size() - 1; j++) {
                if (board[i][j] != '0') {
                    if (board[i][j] == board[i + 1][j] && board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j + 1]) {
                        v.push_back({ i,j });
                    }
                }
            }
        }
        if (v.empty()) break;
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < 4; j++) {
                if (board[v[i].first + y[j]][v[i].second + x[j]] != '0') {
                    board[v[i].first + y[j]][v[i].second + x[j]] = '0';
                    answer++;
                }
            }
        }
        for (int i = 1; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                int tempy = i;
                int tempx = j;
                while (tempy >= 1 && board[tempy][tempx] == '0' && board[tempy - 1][tempx] != '0') {
                    board[tempy][tempx] = board[tempy - 1][tempx];
                    board[tempy - 1][tempx] = '0';
                    tempy--;
                }
            }
        }
    }
    return answer;
}