#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<long long, long long > um;
long long find(long long num) {
    if (!um[num]) return num;
    else return um[num] = find(um[num]);
}
vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for (int i = 0; i < room_number.size(); i++) {
        long long curnum = room_number[i];
        if (!um[curnum]) {
            answer.push_back(curnum);
            um[curnum] = find(curnum + 1);
        }
        else {
            long long temp = find(curnum);
            answer.push_back(temp);
            um[temp] = find(temp + 1);

        }
    }
    return answer;
}