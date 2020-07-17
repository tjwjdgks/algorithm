#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
bool compare(vector<int> a, vector<int>b) {
    if (a[0] == b[0]) return a[1] < b[1];
    else return a[0] < b[0];
}
int solution(int n, vector<vector<int>> data) {
    int answer = 0;
    sort(data.begin(), data.end(), compare);
    for (int i = 0; i < data.size() - 1; i++) {
        int maxnum = 2147483647;
        int minnum = -1;
        int cur = -1;
        int previousmaxnum = 2147483647;
        int previousminnum = -1;
        for (int j = i + 1; j < data.size(); j++) {
            if (data[i][0] == data[j][0] || data[i][1] == data[j][1]) continue;
            else {
                if (cur != data[j][0]) {
                    cur = data[j][0];
                    previousmaxnum = maxnum;
                    previousminnum = minnum;
                }

                if (data[i][1] < data[j][1]) {
                    if (data[j][1] <= previousmaxnum) {
                        maxnum = min(maxnum, data[j][1]);
                        answer++;
                    }
                }
                else {
                    if (data[j][1] >= previousminnum) {
                        minnum = max(minnum, data[j][1]);
                        answer++;
                    }
                }
            }
        }
    }
    return answer;
}