#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int minnum = stones[0];
    int maxnum = stones[0];
    for (int i = 1; i < stones.size(); i++) {
        minnum = min(minnum, stones[i]);
        maxnum = max(maxnum, stones[i]);
    }
    while (minnum <= maxnum) {
        int midnum = (minnum + maxnum) / 2;
        if (minnum == maxnum) break;
        int distance = 0;
        int i;
        for (i = 0; i < stones.size(); i++) {
            int tempnum = stones[i] - midnum;
            if (tempnum < 0)distance++;
            else distance = 0;
            if (distance > k - 1)break;
        }
        if (i == stones.size()) {
            minnum = midnum + 1;
        }
        else {
            maxnum = midnum - 1;
        }
    }
    int distance = 0;
    int i;
    for (i = 0; i < stones.size(); i++) {
        int tempnum = stones[i] - minnum;
        if (tempnum < 0)distance++;
        else distance = 0;
        if (distance > k - 1)break;
    }
    if (i == stones.size())answer = minnum;
    else answer = minnum - 1;
    return answer;
}