#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    map<char, pair<int, int>> m;
    char num = '1';
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            m[num] = { i,j };
            num++;
        }
    }
    m['*'] = { 4,1 };
    m['0'] = { 4,2 };
    m['#'] = { 4,3 };
    pair<int, int> rightpos = m['#'];
    pair<int, int> leftpos = m['*'];
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            numbers[i] += '0';
            leftpos = m[numbers[i]];
            answer += 'L';
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            numbers[i] += '0';
            rightpos = m[numbers[i]];
            answer += 'R';
        }
        else {
            numbers[i] += '0';
            pair<int, int> target = m[numbers[i]];
            int numL = abs(target.first - leftpos.first) + abs(target.second - leftpos.second);
            int numR = abs(target.first - rightpos.first) + abs(target.second - rightpos.second);
            if (numL > numR) {
                rightpos = m[numbers[i]];
                answer += 'R';
            }
            else if (numL < numR) {
                leftpos = m[numbers[i]];
                answer += 'L';
            }
            else {
                if (hand == "right") {
                    rightpos = m[numbers[i]];
                    answer += 'R';
                }
                else {
                    leftpos = m[numbers[i]];
                    answer += 'L';
                }
            }
        }
    }

    return answer;
}
