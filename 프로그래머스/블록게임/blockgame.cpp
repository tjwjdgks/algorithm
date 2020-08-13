#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<vector<int>> boards;
bool Check(int y, int x) {
    bool checks = true;
    for (int i = 0; i < y; i++) {
        if (boards[i][x] == 0) continue;
        else {
            checks = false;
            break;
        }
    }
    return checks;
}
bool isone3(int y, int x) {
    if (y + 1 < boards.size() && x + 2 < boards.size()) {
        if (boards[y][x] == boards[y + 1][x] && boards[y][x] == boards[y + 1][x + 1] && boards[y][x] == boards[y + 1][x + 2]) return true;
    }
    return false;
}
bool isone4(int y, int x) {
    if (y + 2 < boards.size() && x - 1 >= 0) {
        if (boards[y][x] == boards[y + 1][x] && boards[y][x] == boards[y + 2][x] && boards[y][x] == boards[y + 2][x - 1]) return true;
    }
    return false;
}
bool istwo2(int y, int x) {
    if (y + 2 < boards.size() && x + 1 < boards.size()) {
        if (boards[y][x] == boards[y + 1][x] && boards[y][x] == boards[y + 2][x] && boards[y][x] == boards[y + 2][x + 1]) return true;
    }
    return false;
}
bool istwo3(int y, int x) {
    if (y + 1 < boards.size() && x - 2 >= 0) {
        if (boards[y][x] == boards[y + 1][x] && boards[y][x] == boards[y + 1][x - 1] && boards[y][x] == boards[y + 1][x - 2]) return true;
    }
    return false;
}
bool isthree1(int y, int x) {
    if (y + 1 < boards.size() && x - 1 >= 0 && x + 1 <= boards.size()) {
        if (boards[y][x] == boards[y + 1][x] && boards[y][x] == boards[y + 1][x - 1] && boards[y][x] == boards[y + 1][x + 1])return true;
    }
    return false;
}
int solution(vector<vector<int>> board) {
    int answer = 0;
    boards = board;
    for (int i = 0; i < boards.size(); i++) {
        for (int j = 0; j < boards[i].size(); j++) {
            if (boards[i][j] != 0) {
                if (isone3(i, j)) {
                    bool checkup = true;
                    if (Check(i + 1, j + 1) && Check(i + 1, j + 2)) {
                        boards[i][j] = 0;
                        boards[i + 1][j] = 0;
                        boards[i + 1][j + 1] = 0;
                        boards[i + 1][j + 2] = 0;
                        answer++;
                        j = -1;
                    }

                }
                else if (isone4(i, j)) {
                    bool checkup = true;
                    if (Check(i + 2, j - 1)) {
                        boards[i][j] = 0;
                        boards[i + 1][j] = 0;
                        boards[i + 2][j] = 0;
                        boards[i + 2][j - 1] = 0;
                        answer++;
                        j = -1;
                    }
                }
                else if (istwo2(i, j)) {
                    bool checkup = true;
                    if (Check(i + 2, j + 1)) {
                        boards[i][j] = 0;
                        boards[i + 1][j] = 0;
                        boards[i + 2][j] = 0;
                        boards[i + 2][j + 1] = 0;
                        answer++;
                        j = -1;
                    }
                }
                else if (istwo3(i, j)) {
                    bool checkup = true;
                    if (Check(i + 1, j - 1) && Check(i + 1, j - 2)) {
                        boards[i][j] = 0;
                        boards[i + 1][j] = 0;
                        boards[i + 1][j - 1] = 0;
                        boards[i + 1][j - 2] = 0;
                        answer++;
                        j = -1;
                    }
                }
                else if (isthree1(i, j)) {
                    bool checkup = true;
                    if (Check(i + 1, j - 1) && Check(i + 1, j + 1)) {
                        boards[i][j] = 0;
                        boards[i + 1][j] = 0;
                        boards[i + 1][j - 1] = 0;
                        boards[i + 1][j + 1] = 0;
                        answer++;
                        j = -1;
                    }
                }
            }
        }
    }
    return answer;
}