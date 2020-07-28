#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

const char friends[8] = { 'A','C','F','J','M','N','R','T' };
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    vector<int> index;
    unordered_map<int, int> friendm;
    for (int i = 0; i < sizeof(friends) / sizeof(char); i++) {
        friendm.insert(make_pair(friends[i], i));
    }
    for (int i = 0; i < 8; i++)index.push_back(i);

    do {
        int i = 0;
        for (i = 0; i < data.size(); i++) {
            int firstnum = friendm.find(data[i][0])->second;
            int secondnum = friendm.find(data[i][2])->second;
            int first, second;
            for (int j = 0; j < index.size(); j++) {
                if (firstnum == index[j]) first = j;
                if (secondnum == index[j]) second = j;
            }
            char cursign = data[i][3];
            int bound = data[i][4] - '0' + 1;
            if (cursign == '=') {
                if (abs(first - second) != bound)break;
            }
            else if (cursign == '>') {
                if (abs(first - second) <= bound)break;
            }
            else if (cursign == '<') {
                if (abs(first - second) >= bound)break;
            }
        }
        if (i == data.size())answer++;

    } while (next_permutation(index.begin(), index.end()));
    return answer;
}