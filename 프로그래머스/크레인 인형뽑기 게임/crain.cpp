#include <string>
#include <vector>
#include <deque>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    deque<int> arry;
    for (int i = 0; i < moves.size(); i++) {
        int x = moves[i] - 1;
        for (int y = 0; y < board.size(); y++) {
            if (board[y][x] != 0) {
                arry.push_front(board[y][x]);
                board[y][x] = 0;
                break;
            }
        }
        if (arry.size() >= 2) {
            if (arry[0] == arry[1]) {
                arry.pop_front();
                arry.pop_front();
                answer += 2;
            }
        }
    }
    return answer;
}